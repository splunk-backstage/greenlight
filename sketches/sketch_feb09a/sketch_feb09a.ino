// color swirl! connect an RGB LED to the PWM pins as indicated
// in the #defines
// public domain, enjoy!
 
//#define REDPIN 5
//#define GREENPIN 6
//#define BLUEPIN 3
 
#define REDPIN 9
#define GREENPIN 10
#define BLUEPIN 11 
 
#define FADESPEED 20     // make this higher to slow down
#define DELAY 1000

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
// 18:25 fade up to orange/yellow, dim to orangered or just red
// 18:45 dim down to off
// 19:00 fade up to green (lights garden at night, does not interfere with plant photosynthesis)
// 22:00 fade down to off
///////////////////////////////////////////////////////////////////////////////////////////////////////
 
void loop() {
  int r, g, b;
 
  analogWrite(REDPIN, 0);
  analogWrite(GREENPIN, 0);
  analogWrite(BLUEPIN, 0);
 
  // red
  for (int i=0; i<256; i++) {
    analogWrite(REDPIN, i);
    delay(FADESPEED);
  }
  delay(DELAY);
  
  // orange
  for (int i=0; i<20; i++) {
    analogWrite(GREENPIN, i);
    delay(FADESPEED);
  }
  delay(DELAY);
  
  // yellow
  for (int i=20; i<50; i++) {
    analogWrite(GREENPIN, i);
    delay(FADESPEED);
  }
  delay(DELAY);
  
  // white
  analogWrite(REDPIN, 200);
  analogWrite(GREENPIN, 100);
  analogWrite(BLUEPIN, 50);
  delay(3000);
    
}
