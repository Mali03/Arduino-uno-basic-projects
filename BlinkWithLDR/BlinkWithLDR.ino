#define led 3
#define ldr A0

int light;

void setup() {
  pinMode(led,OUTPUT);

  Serial.begin(9600);
}

void loop() {
  light = analogRead(ldr);

  // Serial.println(light); // test your ambient light - returned between 25-40 for me

  if (light >= 15) {
    digitalWrite(led,LOW);
  } else {
    digitalWrite(led,HIGH);
  }
}
