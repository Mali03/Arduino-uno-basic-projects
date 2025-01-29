#define ledPin 5
#define echoPin 6
#define trigPin 7

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  int measured = measureDistance();

  if (measured >= 30 && measured <= 65) {
    digitalWrite(ledPin,HIGH);
    delay(5000);
    digitalWrite(ledPin,LOW);
    delay(5000);
  }
}

int measureDistance() {
  long duration, distance;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;

  delay(50);
  
  return distance;
}