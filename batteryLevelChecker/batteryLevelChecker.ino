int pinA = 11, pinB = 7, pinC = 4, pinD = 2;
int pinE = 13, pinF = 10, pinG = 5;
int pinDP = 3, D1 = 12, D2 = 9, D3 = 8, D4 = 6;

int sensoreValue, percentageOfBattery, index = 3, value;
float measuredVoltage;

int digitValues[4] = {0,0,0,0};

void setup() {
  Serial.begin(9600);

  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);

  // Digit Pins
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
}

void loop() {
  // correct only for 9v battery

  sensoreValue = analogRead(A0);
  measuredVoltage = sensoreValue * (5.0 / 1023.0) * ((100.0 + 47.0) / 47.0);

  percentageOfBattery = (measuredVoltage / 9.0) * 100.0;
  if (percentageOfBattery > 100) percentageOfBattery = 100;

  /*Serial.print("Percentage of Battery: ");
  Serial.print(percentageOfBattery);
  Serial.println("%");*/

  int tempBattery = percentageOfBattery;
  
  while (tempBattery > 0) {
    digitValues[index] = tempBattery % 10;
    index = index - 1;
    tempBattery = tempBattery / 10;
  }

  index = 3;
  
  for (int i = 1; i < 4; i++) {
    digitalWrite(pinDP,HIGH);
    showDigit(i, digitValues[i]);
    delay(1);
  }

  for (int i = 1; i<4; i++) {
    digitValues[i] = 0;
  }
}

void showDigit(int digit, int value) {
  turnOffAllDigits();

  switch (digit) {
    case 0: digitalWrite(D1, HIGH); break;
    case 1: digitalWrite(D2, HIGH); break;
    case 2: digitalWrite(D3, HIGH); break;
    case 3: digitalWrite(D4, HIGH); break;
  }

  displayNumber(value);
}

void turnOffAllDigits() {
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
}

void displayNumber(int num) {
  switch (num) {
    case 0: zero(); break;
    case 1: one(); break;
    case 2: two(); break;
    case 3: three(); break;
    case 4: four(); break;
    case 5: five(); break;
    case 6: six(); break;
    case 7: seven(); break;
    case 8: eight(); break;
    case 9: nine(); break;
    default: turnOffAllSegments(); break;
  }
}

//functions representing numbers 0-9
void zero() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void one() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void two() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void three() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}

void four() {
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void five() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void six() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void seven() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void eight() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void nine() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void turnOffAllSegments() {
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void all4Digits() {
  digitalWrite(D1, HIGH);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, HIGH);
  digitalWrite(D4, HIGH);
}