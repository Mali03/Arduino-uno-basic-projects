#define buzzer 2

void setup() {
  pinMode(buzzer,OUTPUT);
}

void loop() {
  // for active buzzer
  /*
  digitalWrite(buzzer,HIGH);
  delay(100);
  digitalWrite(buzzer,LOW);
  delay(100);
  */

  // for passive buzzer -> 
  tone(buzzer,1000);
  delay(100);
  noTone(buzzer);
  delay(100);
}