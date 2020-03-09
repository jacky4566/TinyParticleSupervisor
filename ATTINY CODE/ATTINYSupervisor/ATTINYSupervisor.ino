//Ensure 8MHz Internal
//BOD optional, uses more power
#include <avr/sleep.h> //Needed for sleep_mode
#include <avr/wdt.h> //Needed to enable/disable watch dog timer
#include <Wire.h> //Needed for I2C

static int BoronENpin = 1;
static int BoronRQPin = 2;
static int VBAT_OKpin = 3;
static int LEDpin = 10;

#define I2CADDR 0x07
static uint32_t myID = 0xF222222F;
//Our I2C "Registers" 32 bit
#define unixTimeRegister 0x01
#define WakeTimeRegister 0x02
#define myIDRegister 0x03

//State machine
byte opcode = 0; //what register is being targeted by I2C?
boolean boronControlState = false;

//Time Machine
uint32_t UNIXTime = 1569463512;  //Current time
uint32_t WakeTime = 1569463512;  //Next wake time

union fourByteArray {
  byte array[4];
  uint32_t integer;
};

void setup() {
  ADCSRA = 0; //Disable ADC, saves ~300uA
  pinMode(BoronENpin, OUTPUT);
  setup_watchdog(); //Setup watchdog to go off after 1sec
  Wire.begin(I2CADDR);
  PCMSK0 |= bit (PCINT2); //enable PC interupt on PA2
  GIMSK |= bit (PCIE0); //enable PC interupts on bank 0
}

void loop() {
  WDTCSR |= bit (WDIE); //kick the dog

  //compute I2C
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);

  //Should I be waking the Particle master?
  if (((UNIXTime >= WakeTime) || digitalRead(BoronRQPin)) && digitalRead(VBAT_OKpin)) {
    boronToggle(1);
    idle();
  } else {
    boronToggle(0);
    sleep();
  }
}

void LEDSTATE(byte newState){//Used for debugging
  if (newState){
    pinMode(LEDpin, OUTPUT);
    digitalWrite(LEDpin, HIGH);
  }else{
    digitalWrite(LEDpin, LOW);
    pinMode(LEDpin, INPUT);
  }
}

void sleep() {
  sleep_enable();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); //Power down everything, wake up from WDT
  sleep_cpu();
}

void idle(){
  sleep_enable();
  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_cpu ();
}

ISR(WDT_vect) {
  //Wake up
  UNIXTime++;//increament unix timer
}

ISR(PCINT0_vect) {
  //wake on Pin Change
}

//Sets the watchdog timer to wake us up, but not reset
void setup_watchdog() {
  cli();
  MCUSR = 0;
  // allow changes, disable reset
  WDTCSR = bit (WDCE) | bit (WDE);
  // set interrupt and reset mode and an interval
  WDTCSR = bit (WDE) | bit (WDIE) | bit (WDP2) | bit (WDP1);    // set WDIE, and 1 second delay
  sei();
}

void boronToggle(boolean newState) {
  if (boronControlState == 1 && newState == 1) {
    //do nothing
  } else if (boronControlState == 1 && newState == 0) {
    //turn off
  digitalWrite(BoronENpin, LOW);
    boronControlState = 0;
  } else if (boronControlState == 0 && newState == 0) {
    //do nothing
  } else if (boronControlState == 0 && newState == 1) {
    digitalWrite(BoronENpin, HIGH);
    boronControlState = 1;
  }
}

void requestEvent() {
  fourByteArray converter;
  switch (opcode) {
    case unixTimeRegister:
      converter.integer = UNIXTime;
      Wire.write(converter.array[0]);
      Wire.write(converter.array[1]);
      Wire.write(converter.array[2]);
      Wire.write(converter.array[3]);
      break;
    case WakeTimeRegister:
      converter.integer = WakeTime;
      Wire.write(converter.array[0]);
      Wire.write(converter.array[1]);
      Wire.write(converter.array[2]);
      Wire.write(converter.array[3]);
      break;
    case myIDRegister:
      converter.integer = myID;
      Wire.write(converter.array[0]);
      Wire.write(converter.array[1]);
      Wire.write(converter.array[2]);
      Wire.write(converter.array[3]);
      break;
    default:
      Wire.write(0x0); //What are you asking? OPCODE not recognized
    Wire.write(0x0);
    Wire.write(0x0);
    Wire.write(0x0);
      break;
  }
  opcode = 0;
}

void receiveEvent(int bytesReceived) {
  // Read the first byte to determine which register is concerned
  opcode = Wire.read();
  // If there are more than 1 byte, then the master is writing to the slave
  if (bytesReceived > 1) {
    fourByteArray converter; //Create a converter
    for (int i = 0; i < 4 ; i++) {
      converter.array[i] = Wire.read();
    }
    if (opcode == unixTimeRegister) {
      UNIXTime = converter.integer;
    } else if (opcode == WakeTimeRegister) {
      WakeTime = converter.integer;
    }
  }
}
