
#include <Stepper.h>

const int stepsPerRevolution = 4091;  // change this to fit the number of steps per revolution
// for your motor

// initialize the stepper library on pins 8 through 11:
Stepper myStepperLeft(stepsPerRevolution, 10,11,12,13);
Stepper myStepperRight(stepsPerRevolution, A2,A3,A4,A5);

void setup() {
  // set the speed at 60 rpm:
  myStepperLeft.setSpeed(60);
  myStepperRight.setSpeed(60);
  // initialize the serial port:
  Serial.begin(9600);
}

void loop() {

  myStepperRight.step(stepsPerRevolution);
  myStepperLeft.step(stepsPerRevolution);

}

