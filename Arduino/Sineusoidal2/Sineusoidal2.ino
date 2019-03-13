

#include "AccelStepper.h"
#include "MultiStepper.h"

#define FULLSTEP 4


// Motor pin definitions
#define motorPin11  32     // IN1 on the ULN2003 driver 1
#define motorPin12  33     // IN2 on the ULN2003 driver 1
#define motorPin13  25    // IN3 on the ULN2003 driver 1
#define motorPin14  26    // IN4 on the ULN2003 driver 1

#define motorPin21  5     // IN1 on the ULN2003 driver 1
#define motorPin22  18     // IN2 on the ULN2003 driver 1
#define motorPin23  19    // IN3 on the ULN2003 driver 1
#define motorPin24  21    // IN4 on the ULN2003 driver 1

#define numStepsPerRev 2048


// Initialize with pin sequence IN1-IN3-IN2-IN4 for using the AccelStepper with 28BYJ-48
AccelStepper stepper1(FULLSTEP, motorPin11, motorPin13, motorPin12, motorPin14);
AccelStepper stepper2(FULLSTEP, motorPin21, motorPin23, motorPin22, motorPin24);
MultiStepper steppers;
//
//void setup() {
//  stepper1.setMaxSpeed(1000.0);
//  stepper1.setAcceleration(100.0);
//  stepper1.setSpeed(2);
////  stepper1.moveTo(2000);
//
//  stepper2.setMaxSpeed(1000.0);
//  stepper2.setAcceleration(100.0);
//  stepper2.setSpeed(2);
////  stepper2.moveTo(-2000);
//  
//  ms.addStepper(stepper1);
//  ms.addStepper(stepper2);
//  long pos[2] = {2000, -2000}; 
//  ms.moveTo(pos);
//  
//  
//}
//
//void loop() {
//
//  //Change direction when the stepper reaches the target position
//  if (stepper1.distanceToGo() == 0) {
////    stepper1.moveTo(-stepper1.currentPosition());
////    stepper2.moveTo(-stepper2.currentPosition());
//    long pos[2] = {-stepper1.currentPosition(), -stepper2.currentPosition()}; 
//    ms.moveTo(pos);
//  }
////  stepper1.run();
////  stepper2.run();
//  ms.runSpeedToPosition();
//}
#define SIZE 100
long positions[SIZE][2] = {
{10.00, 10.00}, 
{10.14, 9.86}, 
{10.42, 9.58}, 
{10.70, 9.30}, 
{10.98, 9.02}, 
{11.25, 8.75}, 
{11.52, 8.48}, 
{11.78, 8.22}, 
{12.04, 7.96}, 
{12.28, 7.72}, 
{12.52, 7.48}, 
{12.75, 7.25}, 
{12.96, 7.04}, 
{13.17, 6.83}, 
{13.36, 6.64}, 
{13.53, 6.47}, 
{13.70, 6.30}, 
{13.85, 6.15}, 
{13.98, 6.02}, 
{14.10, 5.90}, 
{14.20, 5.80}, 
{14.28, 5.72}, 
{14.35, 5.65}, 
{14.40, 5.60}, 
{14.43, 5.57}, 
{14.44, 5.56}, 
{14.44, 5.56}, 
{14.41, 5.59}, 
{14.37, 5.63}, 
{14.32, 5.68}, 
{14.24, 5.76}, 
{14.15, 5.85}, 
{14.04, 5.96}, 
{13.92, 6.08}, 
{13.77, 6.23}, 
{13.62, 6.38}, 
{13.45, 6.55}, 
{13.26, 6.74}, 
{13.07, 6.93}, 
{12.86, 7.14}, 
{12.63, 7.37}, 
{12.40, 7.60}, 
{12.16, 7.84}, 
{11.91, 8.09}, 
{11.65, 8.35}, 
{11.39, 8.61}, 
{11.12, 8.88}, 
{10.84, 9.16}, 
{10.56, 9.44}, 
{10.28, 9.72}, 
{10.00, 10.00}, 
{9.72, 10.28}, 
{9.44, 10.56}, 
{9.16, 10.84}, 
{8.88, 11.12}, 
{8.61, 11.39}, 
{8.35, 11.65}, 
{8.09, 11.91}, 
{7.84, 12.16}, 
{7.60, 12.40}, 
{7.37, 12.63}, 
{7.14, 12.86}, 
{6.93, 13.07}, 
{6.74, 13.26}, 
{6.55, 13.45}, 
{6.38, 13.62}, 
{6.23, 13.77}, 
{6.08, 13.92}, 
{5.96, 14.04}, 
{5.85, 14.15}, 
{5.76, 14.24}, 
{5.68, 14.32}, 
{5.63, 14.37}, 
{5.59, 14.41}, 
{5.56, 14.44}, 
{5.56, 14.44}, 
{5.57, 14.43}, 
{5.60, 14.40}, 
{5.65, 14.35}, 
{5.72, 14.28}, 
{5.80, 14.20}, 
{5.90, 14.10}, 
{6.02, 13.98}, 
{6.15, 13.85}, 
{6.30, 13.70}, 
{6.47, 13.53}, 
{6.64, 13.36}, 
{6.83, 13.17}, 
{7.04, 12.96}, 
{7.25, 12.75}, 
{7.48, 12.52}, 
{7.72, 12.28}, 
{7.96, 12.04}, 
{8.22, 11.78}, 
{8.48, 11.52}, 
{8.75, 11.25}, 
{9.02, 10.98}, 
{9.30, 10.70}, 
{9.58, 10.42}, 
{9.86, 10.14},
};

void setup() {
  Serial.begin(9600);
// new
  // Configure each stepper
  stepper1.setMaxSpeed(150);
//  stepper1.setAcceleration(10.0);
  stepper2.setMaxSpeed(150);
//  stepper2.setAcceleration(10.0);
//
  stepper1.setAcceleration(100.0);
  stepper1.setSpeed(10);

  stepper2.setAcceleration(100.0);
  stepper2.setSpeed(10);

//old
//  stepper1.setMaxSpeed(1000.0);
//  stepper1.setAcceleration(300.0);
//  stepper1.setSpeed(100);
//
//  stepper2.setMaxSpeed(1000.0);
//  stepper2.setAcceleration(300.0);
//  stepper2.setSpeed(100);

  


  // Then give them to MultiStepper to manage
  steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);

  
  stepper1.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);
}

void loop() {

  long position[2]; // = {stepper1.currentPosition() + positions[i][0], stepper2.currentPosition() + positions[i][1]};     
//  position[0] = 0;
//  position[1] = 0;
//  steppers.moveTo(position);
//  
//  steppers.runSpeedToPosition(); // Blocks until all are in position  
//  delay(1000);
  
  for (int i = 0; i < SIZE; i++) {
    
    position[0] = positions[i][0] * numStepsPerRev/66/PI + stepper1.currentPosition();
    position[1] = -positions[i][1] * numStepsPerRev/66/PI + stepper2.currentPosition();

    Serial.print("current I: ");
    Serial.println(i);
    Serial.print("delta 0: ");
    printDouble(positions[i][0], 3);
    Serial.print("delta 1: ");
    printDouble(positions[i][1], 3);
    Serial.println(">>>");
    
    Serial.print("current position 0:");
    printDouble(stepper1.currentPosition(), 3);
    Serial.print("target position 0:");
    printDouble(position[0], 3);

    Serial.print("current position 1:");
    printDouble(stepper2.currentPosition(), 3);
    Serial.print("target position 1:");
    printDouble(position[1], 3);

    Serial.println("^-----------------");
    
    

    
//    stepper1.moveTo(position[0]);
//    stepper2.moveTo(position[1]);
//    stepper1.run();
//    stepper2.run();
    
//    long pos[2] = {-stepper1.currentPosition(), -stepper2.currentPosition()}; 

    steppers.moveTo(position);
    steppers.runSpeedToPosition(); // Blocks until all are in position  
//    delay(1000);
  }

//  
//  
//  positions[0] = 1000;
//  positions[1] = -1000;
//  
//  
//  // Move to a different coordinate
//  positions[0] = -1000;
//  positions[1] = 1000;
//  steppers.moveTo(positions);
//  steppers.runSpeedToPosition(); // Blocks until all are in position
//  delay(1000);
}


void printDouble( double val, unsigned int precision){
// prints val with number of decimal places determine by precision
// NOTE: precision is 1 followed by the number of zeros for the desired number of decimial places
// example: printDouble( 3.1415, 100); // prints 3.14 (two decimal places)

   Serial.print (int(val));  //prints the int part
   Serial.print("."); // print the decimal point
   unsigned int frac;
   if(val >= 0)
       frac = (val - int(val)) * precision;
   else
       frac = (int(val)- val ) * precision;
   Serial.println(frac,DEC) ;
} 
