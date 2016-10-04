#include <AccelStepper.h>
#define HALFSTEP 8

// motor pins
#define motorPin1  10     // IN1 on the ULN2003 driver 1
#define motorPin2  11     // IN2 on the ULN2003 driver 1
#define motorPin3  12     // IN3 on the ULN2003 driver 1
#define motorPin4  13     // IN4 on the ULN2003 driver 1

#define motorPin5  A2     // IN1 on the ULN2003 driver 2
#define motorPin6  A3     // IN2 on the ULN2003 driver 2
#define motorPin7  A4    // IN3 on the ULN2003 driver 2
#define motorPin8  A5    // IN4 on the ULN2003 driver 2

// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(HALFSTEP, motorPin1, motorPin3, motorPin2, motorPin4);
AccelStepper stepper2(HALFSTEP, motorPin5, motorPin7, motorPin6, motorPin8);

// variables
int turnSteps = 2100; // number of steps for a 90 degree turn
int lineSteps = -6600; //number of steps to drive straight

int stepperSpeed = 1000; //speed of the stepper (steps per second)

int steps1 = 0; // keep track of the step count for motor 1
int steps2 = 0; // keep track of the step count for motor 2

boolean turn1 = false; //keep track if we are turning or going straight next
boolean turn2 = false; //keep track if we are turning or going straight next

  int target = 2000;

void setup() {
  delay(3000); //sime time to put the robot down after swithing it on

  stepper1.setMaxSpeed(2000.0);
  stepper1.move(1);  // I found this necessary
  stepper1.setSpeed(stepperSpeed);

  stepper2.setMaxSpeed(2000.0);
  stepper2.move(-1);  // I found this necessary
  stepper2.setSpeed(stepperSpeed);

  stepper1.move(target);

  Serial.begin(9600);


}
void loop() {

    Serial.println(stepper1.distanceToGo());
    if(stepper1.distanceToGo() > 0){
     stepper1.setSpeed(stepperSpeed);
     stepper1.runSpeedToPosition(); 
    }
    
}
