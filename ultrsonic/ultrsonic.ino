/*
* Ultrasonic Sensor HC-SR04 and Arduino Tutorial
*
* by Dejan Nedelkovski,
* www.HowToMechatronics.com
*
*/
// defines pins numbers
const int front_sen_one_trigPin = 2;
const int front_sen_one_echoPin = 3;

//const int front_sen_two_trigPin = 4;
const int front_sen_two_echoPin = 4;

//const int back_sen_one_trigPin = 6;
const int back_sen_one_echoPin = 5;

//const int back_sen_two_trigPin = 8;
const int back_sen_two_echoPin =6;


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

void setup() {
pinMode(front_sen_one_trigPin, OUTPUT); // Sets the trigPin as an Output
//pinMode(front_sen_two_trigPin, OUTPUT);
//pinMode(back_sen_one_trigPin, OUTPUT);
//pinMode(back_sen_two_trigPin, OUTPUT);

pinMode(front_sen_one_echoPin, INPUT); // Sets the echoPin as an Input
pinMode(front_sen_two_echoPin, INPUT);
pinMode(back_sen_one_echoPin, INPUT);
pinMode(back_sen_two_echoPin, INPUT);


Serial.begin(9600); // Starts the serial communication
vehicalCount = 5;
}


void loop() {
// Clears the trigPin

front_sen_one_distance = front_sen_one();
front_sen_two_distance = front_sen_two();
back_sen_one_distance  = back_sen_one();
back_sen_two_distance = back_sen_two();

}

int front_sen_one(){
  int distance=0;
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
distance= front_sen_one_duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Front Sensor One Distance: ");
Serial.println(distance);
return distance;
  }

  int front_sen_two(){
    int distance=0;
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
distance= front_sen_two_duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Front Sensor Two Distance: ");
Serial.println(distance);

return distance;
  }

int back_sen_one(){
  int distance=0;
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
distance= back_sen_one_duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Back Sensor One Distance: ");
Serial.println(distance);

return distance;
  }

int back_sen_two(){
    int distance=0;
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
distance= back_sen_two_duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Back Sensor Two Distance: ");
Serial.println(distance);

return distance;
  }

  



