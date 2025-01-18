#define echoPin 6
#define trigPin 7
#define buzzerPin 8
#define greenLed 2
#define yellowLed 3
#define redLed 4

int minDistance = 0; // cm
int maxDistance = 50; // cm

void setup() {
  pinMode(greenLed,OUTPUT); // green led
  pinMode(yellowLed,OUTPUT); // yellow led
  pinMode(redLed,OUTPUT); // red led
  pinMode(trigPin, OUTPUT); // sends trigger signal
  pinMode(echoPin, INPUT); // fetchs response signal
  pinMode(buzzerPin, OUTPUT); // makes noises

  Serial.begin(9600);
}

void loop() {
  int measured = measureDistance(maxDistance,minDistance);

  Serial.print("Distance: ");
  Serial.println(measured);

  if (measured != 0) {
    if (measured > 35 && measured <= 50) {
      if (digitalRead(redLed)) digitalWrite(redLed,LOW);
      if (digitalRead(yellowLed)) digitalWrite(yellowLed,LOW);
      bip(measured);
      digitalWrite(greenLed,HIGH);
    } else if (measured > 15 && measured <= 35) {
      if (digitalRead(greenLed)) digitalWrite(greenLed,LOW);
      if (digitalRead(redLed)) digitalWrite(redLed,LOW);
      bip(measured);
      digitalWrite(yellowLed,HIGH);
    } else if (measured > 0 && measured <= 15) {
      if (digitalRead(redLed)) digitalWrite(redLed,LOW);
      if (digitalRead(yellowLed)) digitalWrite(yellowLed,LOW);
      bip(measured);
      digitalWrite(redLed,HIGH);
    }
  }
}

int measureDistance(int maxRange, int minRange) {
  long duration, distance;

  digitalWrite(trigPin,LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration / 58.2;

  delay(50);

  if (distance >= maxRange || distance <= minRange)
    return 0;
  
  return distance;
}

void bip(int measured) {
  tone(buzzerPin, 440);
  delay(measured*10);
  noTone(buzzerPin);
  delay(measured*10);
}