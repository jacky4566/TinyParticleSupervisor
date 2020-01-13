/*
Particle Library for TinyParticleSupervisor
*/

#include "TinySupervisor.h"

union fourByteArray {
  byte array[4];
  uint32_t integer;
};

boolean TinySupervisor::isAttached(){
	Wire.beginTransmission(I2CADDR);
	Wire.write(myIDRegister);
	Wire.endTransmission();
	Wire.requestFrom(I2CADDR, 4);
	fourByteArray converter; //Create a converter
	for (int i = 0; i < 4; i++) {
		converter.array[i] = Wire.read();
	}
	if (converter.integer == myID){
		return true;
	}else {
		return false;
	}
}

void TinySupervisor::setTime(uint32_t newValue){
	fourByteArray converter; //Create a converter
	converter.integer = newValue;
	Wire.beginTransmission(I2CADDR);
	Wire.write(unixTimeRegister);
	for (int i = 0; i< 4; i++){
		Wire.write(converter.array[i]);
	}
	Wire.endTransmission();
	_cooldown = millis();
}

uint32_t TinySupervisor::getTime(){
	Wire.beginTransmission(I2CADDR);
	Wire.write(unixTimeRegister);
	Wire.endTransmission();
	Wire.requestFrom(I2CADDR, 4);
	fourByteArray converter; //Create a converter
	for (int i = 0; i < 4; i++) {
		converter.array[i] = Wire.read();
	}
	return converter.integer;
}

void TinySupervisor::setAlarm(uint32_t newValue){
	fourByteArray converter; //Create a converter
	converter.integer = newValue;
	Wire.beginTransmission(I2CADDR);
	Wire.write(WakeTimeRegister);
	for (int i = 0; i< 4; i++){
		Wire.write(converter.array[i]);
	}
	Wire.endTransmission();
}

uint32_t TinySupervisor::getAlarm(){
	Wire.beginTransmission(I2CADDR);
	Wire.write(WakeTimeRegister);
	Wire.endTransmission();
	Wire.requestFrom(I2CADDR, 4);
	fourByteArray converter; //Create a converter
	for (int i = 0; i < 4; i++) {
		converter.array[i] = Wire.read();
	}
	return converter.integer;
}