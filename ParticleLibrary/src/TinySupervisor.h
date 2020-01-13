/*
Particle Library for TinyParticleSupervisor
*/

#define I2CADDR 0x07
#define myID 0xF222222F
#define unixTimeRegister 0x01
#define WakeTimeRegister 0x02
#define myIDRegister 0x03

#include "Arduino.h"

class TinySupervisor{
public:
   boolean isAttached();
   void setTime(uint32_t time);
   uint32_t getTime();
   void setAlarm(uint32_t time);
   uint32_t getAlarm();

private:
   uint32_t _cooldown;
};