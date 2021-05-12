const int trigPin = 11;
const int echoPin = 10;
const int buzzPin = 6;

long duration;
float distance;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(buzzPin, OUTPUT);
}

void loop() 
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = 0.034*(duration/2);

  if (distance < 100)
  {
    digitalWrite(buzzPin,HIGH);
  }
  else 
  {
    digitalWrite(buzzPin,LOW);
  }
  delay(300);
}
