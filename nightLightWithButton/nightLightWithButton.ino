#define ldr A0
#define greenLed 2
#define blueLed 3
#define redLed 4
#define button 5

int lightValue, buttonValue, systemValue = 1, lastButtonState = LOW, currentButtonState;

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(button, INPUT);
}

void loop() {
  lightValue = analogRead(ldr);
  currentButtonState = digitalRead(button);

  if (currentButtonState == LOW && lastButtonState == HIGH) {
    systemValue = !systemValue;
  }

  lastButtonState = currentButtonState;
  
  if (systemValue) { 
    if (lightValue > 100) {
      digitalWrite(greenLed, HIGH);
      digitalWrite(blueLed, LOW);
      digitalWrite(redLed, LOW);
    } else if (lightValue > 50) {
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, HIGH);
      digitalWrite(redLed, LOW);
    } else {
      digitalWrite(greenLed, LOW);
      digitalWrite(blueLed, LOW);
      digitalWrite(redLed, HIGH);
    }
  } else { 
    digitalWrite(greenLed, LOW);
    digitalWrite(blueLed, LOW);
    digitalWrite(redLed, LOW);
  }
}
