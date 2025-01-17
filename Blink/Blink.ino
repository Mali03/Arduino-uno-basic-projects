#define led 8 // 8. output

void setup() {
  pinMode(led, OUTPUT); // 8. pin
}

void loop() {
  digitalWrite(led, HIGH); // increases the voltage
  delay(1000); // waits 1 second
  digitalWrite(led, LOW); // decreases the voltage
  delay(1000); // waits 1 second
}