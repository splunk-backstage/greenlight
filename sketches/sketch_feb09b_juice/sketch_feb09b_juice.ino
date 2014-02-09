// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!
  
#define REDPIN 9
#define GREENPIN 10
#define BLUEPIN 11 
 
#define FADESPEED 30     // make this higher to slow down
#define DELAY 3000

void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
// TODO: to simulate (30 second demo)
//
// 06:15 off, fade up to red/orange/yellow
// 06:30 fadeup to white, turn off (just after fluorescents turn on)
//
// (Flourescence come on!!)
//
// 18:25 fade up to yellow/orange/red
// 18:45 dim down to off
// 19:00 fade up to green (lights garden at night, does not interfere with plant photosynthesis)
// 22:00 fade down to off
///////////////////////////////////////////////////////////////////////////////////////////////////////
 
void loop() {
  int r, g, b;
  
  do_turn_off();
 
  /* 06:15 off, fade up to red/orange/yellow */ 
  do_fade(0, 200, 1, REDPIN);   // red
  do_fade(0, 20, 1, GREENPIN);  // orange
  do_fade(20, 50, 1, GREENPIN); // yellow
   
  /* 06:30 fadeup to white, turn off (just after fluorescents turn on) */
  do_white();
  do_turn_off();
  
  /* 18:25 fade up to yellow/orange/red */
  analogWrite(REDPIN, 200);
  do_fade(20, 50, 1, GREENPIN); // yellow
  do_reverse_fade(50, 20, 1, GREENPIN);
  //do_fade(0, 20, 1, GREENPIN);  // orange
  do_turn_off();
  
  /* 19:00 fade up to green 
  (lights garden at night, does not interfere with plant photosynthesis) 
  */
  do_fade(0, 50, 1, GREENPIN);
}

////////////////////////////////////////////////////////////
// brings up one PIN to a particular limit (color)
////////////////////////////////////////////////////////////
void do_fade(int start, int limit, int incr, int pin) {
  for (int i=start; i<limit; i+=incr) {
    analogWrite(pin, i);
    delay(FADESPEED);
  }
  delay(DELAY);
}

void do_reverse_fade(int start, int limit, int incr, int pin) {
  for (int i=start; i>limit; i-=incr) {
    analogWrite(pin, i);
    delay(FADESPEED);
  }
  delay(DELAY);
}


////////////////////////////////////////////////////
// blinding white light
////////////////////////////////////////////////////
void do_white() {
  analogWrite(REDPIN, 200);
  analogWrite(GREENPIN, 100);
  analogWrite(BLUEPIN, 50);
  delay(6000);
}

////////////////////////////
// turn off the lights
////////////////////////////
void do_turn_off() {
  analogWrite(REDPIN, 0);
  analogWrite(GREENPIN, 0);
  analogWrite(BLUEPIN, 0);
}



