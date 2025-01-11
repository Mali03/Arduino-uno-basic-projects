#define Button 8
#define Led 10

int buttonInfo;

void setup() {
  pinMode(Button, INPUT);
  pinMode(Led, OUTPUT);
}

void loop() {
  buttonInfo = digitalRead(Button);

  if (buttonInfo == 1) {
    digitalWrite(Led, HIGH);
  } else {
    digitalWrite(Led, LOW);
  }
}
