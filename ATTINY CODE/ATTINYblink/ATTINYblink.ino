//Basic blink to verify chip
//Ensure 8MHz Internal
//BOD optional
#include <avr/sleep.h> //Needed for sleep_mode
#include <avr/wdt.h> //Needed to enable/disable watch dog timer

static int BoronENpin = 1;
static int RQpin = 2;
static int VBAT_OKpin = 3;
static int LEDpin = 10;

void setup() {
  ADCSRA = 0; //Disable ADC, saves ~230uA
  pinMode(LEDpin, OUTPUT);
  setup_watchdog(); //Setup watchdog to go off after 1sec
}

void loop() {
  WDTCSR |= bit (WDIE); //kick the dog
  //Turn on LED and wait 50ms
  digitalWrite(LEDpin, HIGH); 
  delay(50);
  digitalWrite(LEDpin, LOW);
  sleep();  
  //WDT will wake from here
}

void sleep(){
  sleep_enable();
  set_sleep_mode(SLEEP_MODE_PWR_DOWN); //Power down everything, wake up from WDT
  sleep_mode();
}

ISR(WDT_vect) {
  //Don't do anything. This is just here so that we wake up.
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
