/*
Particle Library for TinyParticleSupervisor

*/

#define I2CADDR 0x07
#define unixTimeRegister 0x01
#define WakeTimeRegister 0x02

#define ATTINYwakePin 8

#include "Arduino.h"

class TinySupervisor
{
public:
   void setTime(uint32_t time);
   uint32_t getTime();
   void setAlarm(uint32_t time);
   uint32_t getAlarm();

private:
	
};