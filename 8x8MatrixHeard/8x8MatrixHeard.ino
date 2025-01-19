int X[] = {1,2,3,4,5,6,7,8}; // rows
int Y[] = {9,10,11,12,13,A0,A1,A2}; // columns

int matris[14][2] = {{3,13},{2,A0},{3,A1},{4,A2},{5,A1},{6,A0},{7,13},{7,12},{6,11},{5,10},{4,9},{3,10},{2,11},{3,12}};

void setup() {
  for (int i = 0; i<14; i++) {
    pinMode(matris[i][0],OUTPUT);
    pinMode(matris[i][1],OUTPUT);
    digitalWrite(matris[i][0],HIGH);
    digitalWrite(matris[i][1],LOW);
  }

  for (int i = 0; i<14; i++) {
    digitalWrite(matris[i][0],LOW);
    digitalWrite(matris[i][1],HIGH);
    delay(150);
    digitalWrite(matris[i][0],HIGH);
    digitalWrite(matris[i][1],LOW);
  }
}

void loop() {
    for (int i = 0; i < 14; i++) {
      // clear all leds
      for (int row = 0; row < 9; row++) {
        digitalWrite(row, HIGH);
      }
      for (int col = 9; col <= A2; col++) {
        digitalWrite(col, LOW);
      }

      digitalWrite(matris[i][0], LOW);
      digitalWrite(matris[i][1], HIGH);
      delay(1);
    }
}