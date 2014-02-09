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
 
void setup() {
  pinMode(REDPIN, OUTPUT);
  pinMode(GREENPIN, OUTPUT);
  pinMode(BLUEPIN, OUTPUT);
}
 
 
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
  delay(3000);
  
  // orange
  for (int i=0; i<20; i++) {
    analogWrite(GREENPIN, i);
    delay(FADESPEED);
  }
  delay(3000);
  
  // yellow
  for (int i=20; i<50; i++) {
    analogWrite(GREENPIN, i);
    delay(FADESPEED);
  }
  delay(3000);
   
 
  // fade from blue to violet
//  for (r = 0; r < 256; r++) { 
//    analogWrite(REDPIN, r);
//    delay(FADESPEED);
//  }
// 
//  for (g = 0; g < 256; g++) { 
//    analogWrite(GREENPIN, g);
//    delay(FADESPEED);
//  } 
  
//  // fade from violet to red
//  for (b = 255; b > 0; b--) { 
//    analogWrite(BLUEPIN, b);
//    delay(FADESPEED);
//  } 
//  // fade from red to yellow
//  for (g = 0; g < 256; g++) { 
//    analogWrite(GREENPIN, g);
//    delay(FADESPEED);
//  } 
//  // fade from yellow to green
//  for (r = 255; r > 0; r--) { 
//    analogWrite(REDPIN, r);
//    delay(FADESPEED);
//  } 
//  // fade from green to teal
//  for (b = 0; b < 256; b++) { 
//    analogWrite(BLUEPIN, b);
//    delay(FADESPEED);
//  } 
//  // fade from teal to blue
//  for (g = 255; g > 0; g--) { 
//    analogWrite(GREENPIN, g);
//    delay(FADESPEED);
//  } 
}
