# TinyParticleSupervisor
Using an ATTINY44 with SpenceKonde/ATTinyCore to control the enable pin on a 3rd gen particle.io board.
Keeps Real Time for only 6uA around 100ppm or worse.  
ATTINY simulates I2C for two registers and controls a wake pin according to internal timers. 


# Wiring
| Pin Mode      | Function                    | Core Pin | ATTINY84 PIN  |
| ------------- | -------------               | :--------: | :------------: |
| OUTPUT        | Control Particle EN pin     |    1     | PA1           |
| INPUT         | Detect if Particle is awake |    2     | PA2           |
| INPUT         | I2C SDA                     |    6     | PA6           |
| INPUT         | I2C SCL                     |    4     | P4           |

# Registers
All registers read and write 32 bit

I2C Address = 0x07

unixTimeRegister 0x01 (Increaments at 1HZ from WDT)

wakeTimeRegister 0x02

# TODO:
*Add defines to support both ATTINYx5 and ATTINYx4
*Investigate alternate chips, ATtiny13A , perhaps STM32L0 for lower run power, RTC crystal, Proper I2C
*Add function to read VCC for boards without Power Good Signal