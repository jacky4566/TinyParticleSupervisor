#include <avr/sleep.h>
#include <avr/wdt.h>
#include <Wire.h>

#define BoronENPin 1
#define BoronRQPin 2
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

union 32bitArray {
  byte array[4];
  uint32_t integer;
};

void setup() {
  ADCSRA = 0; //dont need ADC
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

  if (UNIXTime < WakeTime) {
    //Boron Sleeps
    pinMode(BoronENPin, OUTPUT);
    digitalWrite(BoronENPin, LOW);
  } else {
    //Boron Wakes
    pinMode(BoronENPin, INPUT);
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
    ArrayToInteger converter; //Create a converter
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

void Sleep() {
  // clear various "reset" flags
  MCUSR = 0;
  // allow changes, disable reset
  WDTCR = bit (WDCE) | bit (WDE);
  // set interrupt and reset mode and an interval
  WDTCR = bit (WDE) | bit (WDIE) | bit (WDP2) | bit (WDP1);
  set_sleep_mode (SLEEP_MODE_PWR_DOWN);
  noInterrupts ();
  sleep_enable();
  interrupts ();
  sleep_cpu ();
  //Sleep here
  sleep_disable();
}

ISR(WDT_vect) {
  //increament unix timer
  UNIXTIME++;
  // allow changes, disable reset
  WDTCR = bit (WDCE) | bit (WDE);
  // set interrupt and reset mode and an interval
  WDTCR = bit (WDE) | bit (WDIE) | bit (WDP2) | bit (WDP1);    // set WDIE, and 1 second delay
}
