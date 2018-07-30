
#include <Servo.h>

Servo Gate1servo;
Servo Gate2servo;

// defines pins numbers
const int front_sen_one_trigPin = 2;
const int front_sen_one_echoPin = 3;
const int front_sen_two_echoPin = 4;
const int back_sen_one_echoPin = 5;
const int back_sen_two_echoPin = 6;

// defines variables
long front_sen_one_duration;
long front_sen_two_duration;
long back_sen_one_duration;
long back_sen_two_duration;

int front_sen_one_distance;
int front_sen_two_distance;
int back_sen_one_distance;
int back_sen_two_distance;

int vehicalCount;

int posGate1 = 0;
int posGate2 = 0;

char _isUserValid;

int carParkFull = 11;
int scanQR = 12;
int AccessDenide = 13;

void setup() {
  pinMode(front_sen_one_trigPin, OUTPUT); // Sets the trigPin as an Output
  //pinMode(front_sen_two_trigPin, OUTPUT);
  //pinMode(back_sen_one_trigPin, OUTPUT);
  //pinMode(back_sen_two_trigPin, OUTPUT);

  pinMode(front_sen_one_echoPin, INPUT); // Sets the echoPin as an Input
  pinMode(front_sen_two_echoPin, INPUT);
  pinMode(back_sen_one_echoPin, INPUT);
  pinMode(back_sen_two_echoPin, INPUT);

  Gate1servo.attach(9);
  Gate2servo.attach(10);


  Serial.begin(9600); // Starts the serial communication
  vehicalCount = 3; // maximum vehicle capacity

  Gate1servo.write(0);
  Gate2servo.write(0);

  pinMode(carParkFull, OUTPUT);
  pinMode(scanQR, OUTPUT);
  pinMode(AccessDenide, OUTPUT);

  _isUserValid = '0';
}


void loop() {
  //init the timers
  int timer1;
  int timer2;

  if (front_sen_one() <= 5 && front_sen_one() > 1) { // check there is a vehicle in front gate
    if (vehicalCount > 0) {
      while (isUserValid() == '0') { //wait till user scan the QR code
        digitalWrite(scanQR, HIGH);
      }
      digitalWrite(scanQR, LOW);
      if (_isUserValid == '1') { // If user is valod then gate will open
        openGate1();
        for ( timer1 = 0 ; timer1 < 10 ; timer1++) {
          delay(2000);
          if (front_sen_two() <= 5 && front_sen_two() > 1) {
            closeGate1();
            vehicalCount--;
            timer1 = 20;
          }
        }
        if (timer1 != 21) {//if the vehicle do not get in to the car park then the gate will automatically close after 20sec wait
          closeGate1();
        }
      }
      else if (_isUserValid == '2') {//if user not valid gate will not open
        digitalWrite(AccessDenide, HIGH);
        delay(5000);
        digitalWrite(AccessDenide, LOW);
      }
    }
    else {
      digitalWrite(carParkFull , HIGH);
    }
  }
  else {
    digitalWrite(carParkFull, LOW);
    delay(100);
    if (back_sen_one() <= 5 && back_sen_one() > 1) {//back gate check
      openGate2();
      for ( timer2 = 0 ; timer2 < 10 ; timer2++) {
        delay(2000);
        if (back_sen_two() <= 5 && back_sen_two() > 1) {
          closeGate2();
          vehicalCount++;
          timer2 = 20;
        }
      }
      if (timer2 != 21) {
        closeGate2();
      }
    }

  }


}

int front_sen_one() {
  int distance = 0;
  // Clears the trigPin
  digitalWrite(front_sen_one_trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(front_sen_one_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(front_sen_one_trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  front_sen_one_duration = pulseIn(front_sen_one_echoPin, HIGH);
  // Calculating the distance
  distance = front_sen_one_duration * 0.034 / 2;

  return distance;
}

int front_sen_two() {
  int distance = 0;
  // Clears the trigPin
  digitalWrite(front_sen_one_trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(front_sen_one_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(front_sen_one_trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  front_sen_two_duration = pulseIn(front_sen_two_echoPin, HIGH);
  // Calculating the distance
  distance = front_sen_two_duration * 0.034 / 2;

  return distance;
}

int back_sen_one() {
  int distance = 0;
  // Clears the trigPin
  digitalWrite(front_sen_one_trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(front_sen_one_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(front_sen_one_trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  back_sen_one_duration = pulseIn(back_sen_one_echoPin, HIGH);
  // Calculating the distance
  distance = back_sen_one_duration * 0.034 / 2;

  return distance;
}

int back_sen_two() {
  int distance = 0;
  // Clears the trigPin
  digitalWrite(front_sen_one_trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(front_sen_one_trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(front_sen_one_trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  back_sen_two_duration = pulseIn(back_sen_two_echoPin, HIGH);
  // Calculating the distance
  distance = back_sen_two_duration * 0.034 / 2;

  return distance;
}

void openGate1() {
  for (posGate1 = 0; posGate1 <= 60; posGate1 += 1) { // goes from 0 degrees to 90 degrees
    Gate1servo.write(posGate1);              // tell servo to go to position in variable 'posGate1'
    delay(30);                       // waits 30ms for the servo to reach the position
  }
}

void closeGate1() {

  for (posGate1 = 60; posGate1 >= 1; posGate1 -= 1) { // goes from 90 degrees to 0 degrees
    Gate1servo.write(posGate1);              // tell servo to go to position in variable 'posGate1'
    delay(30);                       // waits 30ms for the servo to reach the position
  }
}

void openGate2() {

  for (posGate2 = 0; posGate2 <= 60; posGate2 += 1) { // goes from 0 degrees to 90 degrees
    // in steps of 1 degree
    Gate2servo.write(posGate2);              // tell servo to go to position in variable 'posGate2'
    delay(30);                       // waits 30ms for the servo to reach the position
  }
}

void closeGate2() {

  for (posGate2 = 60; posGate2 >= 1; posGate2 -= 1) { // goes from 90 degrees to 0 degrees
    Gate2servo.write(posGate2);              // tell servo to go to position in variable 'posGate2'
    delay(30);                       // waits 30ms for the servo to reach the position
  }
}

char isUserValid() {
  if (Serial.available()) {
    _isUserValid = Serial.read();
    Serial.print(_isUserValid);
    return _isUserValid;
  } else {
    return _isUserValid;
  }

}
