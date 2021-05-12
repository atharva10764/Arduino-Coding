const int trigPin = 5;
const int echoPin = 3;
const int buzzPin = 12;

long duration;
float distance;

void setup() 
{
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(buzzPin, OUTPUT);
  Serial.begin(9600);
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
  Serial.println(distance);

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
