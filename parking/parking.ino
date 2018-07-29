#include <Servo.h>

Servo Gate1servo;
Servo Gate2servo;

// defines pins numbers
const int front_sen_one_trigPin = 2;
const int front_sen_one_echoPin = 3;

//const int front_sen_two_trigPin = 4;
const int front_sen_two_echoPin = 4;

//const int back_sen_one_trigPin = 7;
const int back_sen_one_echoPin = 5;

//const int back_sen_two_trigPin = 8;
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
int AccessGranded = 12;
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
  vehicalCount = 3;

  Gate1servo.write(0);
  Gate2servo.write(0);

  pinMode(carParkFull, OUTPUT);
  pinMode(AccessGranded,OUTPUT);
  pinMode(AccessDenide,OUTPUT);

  _isUserValid = "0";
}


void loop() {
  // Clears the trigPin
  int timer1;
  int timer2;

  //  front_sen_one_distance = front_sen_one();
  //  delay(500);
  //  front_sen_two_distance = front_sen_two();
  //  delay(500);
  //   back_sen_one_distance  = back_sen_one();
  //   delay(500);
  //    back_sen_two_distance = back_sen_two();
  //    delay(500);

  if (front_sen_one() <= 5 && front_sen_one() > 1) {
    if (vehicalCount > 0) {
      while (isUserValid() == "0"){
        Serial.println("Im in the while loop");
        }
      
      if (_isUserValid == "1") {
        openGate1();
        for ( timer1 = 0 ; timer1 < 10 ; timer1++) {
          delay(2000);
          if (front_sen_two() <= 5 && front_sen_two() > 1) {
            closeGate1();
            vehicalCount--;
            timer1 = 20;
          }
        }
        if (timer1 != 21) {
          closeGate1();
        }
      }
      else if (_isUserValid == "2") {
        digitalWrite(AccessDenide,HIGH);
        delay(5000);
        digitalWrite(AccessDenide,LOW);
      }
    }
    else {
      digitalWrite(carParkFull , HIGH);
    }
  }
  else {
    digitalWrite(carParkFull, LOW);
    delay(100);
    if (back_sen_one() <= 5 && back_sen_one() > 1) {
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
  // Prints the distance on the Serial Monitor
  Serial.print("Front Sensor One Distance: ");
  Serial.println(distance);
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
  // Prints the distance on the Serial Monitor
  Serial.print("Front Sensor Two Distance: ");
  Serial.println(distance);

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
  // Prints the distance on the Serial Monitor
  Serial.print("Back Sensor One Distance: ");
  Serial.println(distance);

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
  // Prints the distance on the Serial Monitor
  Serial.print("Back Sensor Two Distance: ");
  Serial.println(distance);

  return distance;
}

void openGate1() {
  digitalWrite(AccessGranded,HIGH);
  for (posGate1 = 0; posGate1 <= 60; posGate1 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Gate1servo.write(posGate1);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
}

void closeGate1() {

  for (posGate1 = 60; posGate1 >= 1; posGate1 -= 1) { // goes from 180 degrees to 0 degrees
    Gate1servo.write(posGate1);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
  digitalWrite(AccessGranded,LOW);
}

void openGate2() {

  for (posGate2 = 0; posGate2 <= 60; posGate2 += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    Gate2servo.write(posGate2);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
}

void closeGate2() {

  for (posGate2 = 60; posGate2 >= 1; posGate2 -= 1) { // goes from 180 degrees to 0 degrees
    Gate2servo.write(posGate2);              // tell servo to go to position in variable 'pos'
    delay(30);                       // waits 15ms for the servo to reach the position
  }
}

char isUserValid() {
  if (Serial.available()) {
    _isUserValid = Serial.read();
    Serial.print(_isUserValid);
return _isUserValid;
  } else {
    return "0";
  }

}
