#include <Stepper.h>
#define button 4

int buttonInfo;
const int stepsPerRevolution = 2048;

Stepper steppername = Stepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  pinMode(button,INPUT);
  steppername.setSpeed(20); // rpm
}

void loop() {
  buttonInfo = digitalRead(button);
  if (buttonInfo)
    //steppername.step(stepsPerRevolution); // turns one step
    steppername.step(1); // turns while pressing
  else {
    // do nothing
  }
}
