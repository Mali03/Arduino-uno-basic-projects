#define echoPin 6
#define trigPin 7
#define buzzerPin 8

int minDistance = 0; // cm
int maxDistance = 50; // cm

void setup() {
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
    tone(buzzerPin, 440);
    delay(measured*10);
    noTone(buzzerPin);
    delay(measured*10);
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