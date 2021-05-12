//#GARUDGOD

// defining the pins
const int trigPin = 9;
const int echoPin = 10;
// defining variables
long duration;
int distance;
int pin1=2;
int pin2=3;
#include <Servo.h>

Servo myservohand;  // create servo object to control a first hand
Servo myservohand2;  // create servo object to control a first hand
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position

void setup() {
  myservohand.attach(11);  // attaches the servo on pin 9 to the servo object
  myservohand2.attach(6);
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input
  Serial.begin(9600); // Starts the serial communication
}
void loop() {
  // Clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin on HIGH state for 10 micro seconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance= duration*0.034/2;
  // Prints the distance on the Serial Monitor
  Serial.print("Distance: ");
  Serial.println(distance);
  if (distance<20 && distance>0)
  {
   digitalWrite(pin1,HIGH);
   digitalWrite(pin2,LOW);
  }
    if( distance >20 && distance <40)
  {
    for (pos = 0; pos <= 90; pos += 2)  // goes from 0 degrees to 180 degrees
    { 
      // in steps of 1 degree
      myservohand.write(pos);              // tell servo to go to position in variable 'pos'
      myservohand2.write(pos);
      delay(15);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 90; pos >= 0; pos -= 2)  // goes from 180 degrees to 0 degrees
    {
     myservohand.write(pos);              // tell servo to go to position in variable 'pos'
     myservohand2.write(pos);
     delay(15);                       // waits 15ms for the servo to reach the position
    }
  }
  if (distance>40 && distance <100)
  {
    digitalWrite(pin2,HIGH);
    digitalWrite(pin1,LOW);
  }
}
