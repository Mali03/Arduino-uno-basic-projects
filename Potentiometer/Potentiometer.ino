#define led 3
#define pot A0

void setup() {
  // Don't have to write anything
}

void loop() {
  int value = analogRead(pot); // 0-1023

  value = value / 4; // 0-255 (you can also use value = map(value,0,1023,0,255))

  analogWrite(led,value);
}
