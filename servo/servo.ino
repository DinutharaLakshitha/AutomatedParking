/* Sweep
 by BARRAGAN <http://barraganstudio.com>
 This example code is in the public domain.

 modified 8 Nov 2013
 by Scott Fitzgerald
 http://www.arduino.cc/en/Tutorial/Sweep
*/

#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
<<<<<<< HEAD
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
=======
 myservo.attach(9);  // attaches the servo on pin 9 to the servo object
 Serial.begin(9600);
>>>>>>> 4e095661b6ff65d4bc15f8a9e821b26fa4f7de81
}

void loop() {
<<<<<<< HEAD
  for (pos = 0; pos <= 90; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
=======
 for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees
 {                                  // in steps of 1 degree
    Serial.print(pos);
>>>>>>> 4e095661b6ff65d4bc15f8a9e821b26fa4f7de81
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 90; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
}
