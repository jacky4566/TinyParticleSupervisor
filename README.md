# TinyParticleSupervisor
Using an ATTINY45 with SpenceKonde/ATTinyCore to control the enable pin on a 3rd gen particle.io board.
ATTINY simulates I2C for two registers and controls the sleep pin according to internal timers. 
When unixTimeRegister is greater than wakeTimeRegister the Paricle enable pin is held low. Otherwise pin floats.
Also keeps somewhat real time!

# Registers
All registers read and write 32 bit
I2C Address = 0x07
unixTimeRegister 0x01
wakeTimeRegister 0x02
