/*
Particle Library for TinyParticleSupervisor

*/

#include "TinySupervisor.h"

union fourByteArray {
  byte array[4];
  uint32_t integer;
};

void TinySupervisor::setTime(uint32_t newValue){
	fourByteArray converter; //Create a converter
	converter.integer = newValue;
	pinMode(ATTINYwakePin, OUTPUT);
	digitalWrite(ATTINYwakePin, HIGH);
	Wire.begin();
	Wire.beginTransmission(I2CADDR);
	Wire.write(unixTimeRegister);
	for (int i = 0; i< 4; i++){
		Wire.write(converter.array[i]);
	}
	Wire.endTransmission();
	Wire.end();
	digitalWrite(ATTINYwakePin, LOW);
}

uint32_t TinySupervisor::getTime(){
	pinMode(ATTINYwakePin, OUTPUT);
	digitalWrite(ATTINYwakePin, HIGH);
	Wire.begin();
	Wire.beginTransmission(I2CADDR);
	Wire.write(unixTimeRegister);
	Wire.endTransmission();
	Wire.requestFrom(I2CADDR, 4);
	fourByteArray converter; //Create a converter
	int i = 0;
	while(Wire.available()){   // slave may send less than requested
		converter.array[i] = Wire.read();
		i++;
	}
	Wire.end();
	digitalWrite(ATTINYwakePin, LOW);
	return converter.integer;
}

void TinySupervisor::setAlarm(uint32_t newValue){
	fourByteArray converter; //Create a converter
	converter.integer = newValue;
	pinMode(ATTINYwakePin, OUTPUT);
	digitalWrite(ATTINYwakePin, HIGH);
	Wire.begin();
	Wire.beginTransmission(I2CADDR);
	Wire.write(WakeTimeRegister);
	for (int i = 0; i< 4; i++){
		Wire.write(converter.array[i]);
	}
	Wire.endTransmission();
	Wire.end();
	digitalWrite(ATTINYwakePin, LOW);
}

uint32_t TinySupervisor::getAlarm(){
	pinMode(ATTINYwakePin, OUTPUT);
	digitalWrite(ATTINYwakePin, HIGH);
	Wire.begin();
	Wire.beginTransmission(I2CADDR);
	Wire.write(WakeTimeRegister);
	Wire.endTransmission();
	Wire.requestFrom(I2CADDR, 4);
	fourByteArray converter; //Create a converter
	int i = 0;
	while(Wire.available()){   // slave may send less than requested
		converter.array[i] = Wire.read();
		i++;
	}
	Wire.end();
	digitalWrite(ATTINYwakePin, LOW);
	return converter.integer;
}