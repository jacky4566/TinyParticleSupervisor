# TinyParticleSupervisor
Using an ATTINY45 with SpenceKonde/ATTinyCore to control the enable pin on a 3rd gen particle.io board.
Keeps Real Time for only 6uA
ATTINY simulates I2C for two registers and controls the sleep pin according to internal timers. 
When wakeTimeRegister is less than unixTimeRegister the Paricle EN pin is held low to sleep. Otherwise pin floats for wake.

# Wiring
| Pin Mode | Function | Core Pin | ATTINY45 PIN / PORT |
| ------------- | ------------- | ------------- | ------------- |
| OUTPUT  | Control Particle EN pin| 3  | 2 / PB3 |
| INPUT  | Detect if Particle is awake  | 4  | 3 / PB4 |
| INPUT  | I2C SDA  | 0  | 5 / PB0 |
| INPUT  | I2C SCL  | 2  | 7 / PB2 |

# Registers
All registers read and write 32 bit

I2C Address = 0x07

unixTimeRegister 0x01 (Increaments at 1HZ)

wakeTimeRegister 0x02
