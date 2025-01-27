#define lm35pin A0
#define led 2
#define buzzer 3

int value = 0;
float temperatureVoltage = 0;
float temperature = 0;

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  value = analogRead(lm35pin);  // 0-1023
  temperatureVoltage = (5000.0 / 1023.0) * value;
  temperature = temperatureVoltage / 100.0;

  Serial.print("The temperature is ");
  Serial.print(temperature);
  Serial.println(" °C");

  if (temperature > 30) {
    digitalWrite(led, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(50);
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
    delay(50);
  } else {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }

  delay(50);
}
