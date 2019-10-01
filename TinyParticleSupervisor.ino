//Recomneded fuse settings for ATTINY 45, Internal 8MHZ no startup delay, no BOD
//LOW:C2  
//HIGH:DF
//EXT:FF

#include <avr/sleep.h>
#include <avr/wdt.h>
#include <Wire.h>

#define BoronENPin 3
#define BoronRQPin 4
//SDA DI PB0
//SCL SCL PB2

#define I2CADDR 0x07

//Our I2C "Registers" 32 bit
#define unixTimeRegister 0x01
#define WakeTimeRegister 0x02

//State machine
byte opcode = 0; //what register is being targeted by I2C?

boolean I2CActive = false;  //Is I2C active?
boolean boronAwake = false; //Is the boron awake?

//Time Machine
uint32_t UNIXTime = 1569463512;  //Current time
uint32_t WakeTime = 1569463512;  //Next wake time

union fourByteArray {
  byte array[4];
  uint32_t integer;
};

void setup() {
  patTheDog();
  ADCSRA = 0; //dont need ADC
  attachInterrupt(digitalPinToInterrupt(BoronRQPin), wakeISR, RISING);
}

void loop() {
  //Check if boron is awake
  digitalRead(BoronRQPin) ? boronAwake = true : boronAwake = false;

  if (boronAwake && !I2CActive) { //Activate I2C
    Wire.begin(I2CADDR);
    Wire.onReceive(receiveEvent); // register event
    Wire.onRequest(requestEvent);
    opcode = 0;
    I2CActive = true;
  } else if (!boronAwake && I2CActive) { //De-activate I2C
    Wire.end();
    I2CActive = false;
  }

  if (WakeTime > UNIXTime) {
    //Boron Wakes
    pinMode(BoronENPin, INPUT);
  } else {
    //Boron Sleeps
    pinMode(BoronENPin, OUTPUT);
    digitalWrite(BoronENPin, LOW);
  }

  if (!I2CActive) {
    sleep();
  }
}


void requestEvent() {
  //Might need to use this version?
  //Wire.write((uint8_t *)&speed, sizeof(speed));
  switch (opcode) {
    case unixTimeRegister:
      Wire.write(UNIXTime);
      break;
    case WakeTimeRegister:
      Wire.write(WakeTime);
      break;
    default:
      Wire.write(0); //What are you asking?
      return;
  }
}

void receiveEvent(int bytesReceived) {
  // Read the first byte to determine which register is concerned
  opcode = Wire.read();
  // If there are more than 1 byte, then the master is writing to the slave
  if (bytesReceived > 1) {
    fourByteArray converter; //Create a converter
    for (int i = 0 ; i < 4 ; i++) {
      converter.array[i] = Wire.read();
    }
    if (opcode == unixTimeRegister) {
      UNIXTime = converter.integer;
    } else if (opcode == WakeTimeRegister) {
      WakeTime = converter.integer;
    }
  }
  while (Wire.available()) { //empty extra junk
    Wire.read();
  }
}

void sleep() {
  // clear various "reset" flags
  MCUSR = 0;
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);
  noInterrupts ();
  sleep_enable();
  interrupts ();
  sleep_cpu ();
  //Sleep here
  sleep_disable();
}

void patTheDog(){
    //increament unix timer
  UNIXTime++;
  // allow changes, disable reset
  WDTCR = bit (WDCE) | bit (WDE);
  // set interrupt and reset mode and an interval
  WDTCR = bit (WDE) | bit (WDIE) | bit (WDP2) | bit (WDP1);    // set WDIE, and 1 second delay
}

ISR(WDT_vect) {
  patTheDog();
}

void wakeISR(){
  
}
