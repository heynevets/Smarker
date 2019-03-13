

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
{3.00, 3.00}, 
{3.56, 2.44}, 
{4.68, 1.32}, 
{5.77, 0.23}, 
{6.82, -0.82}, 
{7.80, -1.80}, 
{8.71, -2.71}, 
{9.52, -3.52}, 
{10.23, -4.23}, 
{10.83, -4.83}, 
{11.29, -5.29}, 
{11.63, -5.63}, 
{11.82, -5.82}, 
{11.88, -5.88}, 
{11.79, -5.79}, 
{11.56, -5.56}, 
{11.19, -5.19}, 
{10.69, -4.69}, 
{10.07, -4.07}, 
{9.33, -3.33}, 
{8.49, -2.49}, 
{7.56, -1.56}, 
{6.56, -0.56}, 
{5.50, 0.50}, 
{4.40, 1.60}, 
{3.28, 2.72}, 
{2.16, 3.84}, 
{1.04, 4.96}, 
{-0.04, 6.04}, 
{-1.07, 7.07}, 
{-2.04, 8.04}, 
{-2.92, 8.92}, 
{-3.71, 9.71}, 
{-4.39, 10.39}, 
{-4.96, 10.96}, 
{-5.39, 11.39}, 
{-5.69, 11.69}, 
{-5.85, 11.85}, 
{-5.87, 11.87}, 
{-5.74, 11.74}, 
{-5.48, 11.48}, 
{-5.08, 11.08}, 
{-4.55, 10.55}, 
{-3.89, 9.89}, 
{-3.13, 9.13}, 
{-2.26, 8.26}, 
{-1.32, 7.32}, 
{-0.30, 6.30}, 
{0.77, 5.23}, 
{1.88, 4.12}, 
{3.00, 3.00}, 
{4.12, 1.88}, 
{5.23, 0.77}, 
{6.30, -0.30}, 
{7.32, -1.32}, 
{8.26, -2.26}, 
{9.13, -3.13}, 
{9.89, -3.89}, 
{10.55, -4.55}, 
{11.08, -5.08}, 
{11.48, -5.48}, 
{11.74, -5.74}, 
{11.87, -5.87}, 
{11.85, -5.85}, 
{11.69, -5.69}, 
{11.39, -5.39}, 
{10.96, -4.96}, 
{10.39, -4.39}, 
{9.71, -3.71}, 
{8.92, -2.92}, 
{8.04, -2.04}, 
{7.07, -1.07}, 
{6.04, -0.04}, 
{4.96, 1.04}, 
{3.84, 2.16}, 
{2.72, 3.28}, 
{1.60, 4.40}, 
{0.50, 5.50}, 
{-0.56, 6.56}, 
{-1.56, 7.56}, 
{-2.49, 8.49}, 
{-3.33, 9.33}, 
{-4.07, 10.07}, 
{-4.69, 10.69}, 
{-5.19, 11.19}, 
{-5.56, 11.56}, 
{-5.79, 11.79}, 
{-5.88, 11.88}, 
{-5.82, 11.82}, 
{-5.63, 11.63}, 
{-5.29, 11.29}, 
{-4.83, 10.83}, 
{-4.23, 10.23}, 
{-3.52, 9.52}, 
{-2.71, 8.71}, 
{-1.80, 7.80}, 
{-0.82, 6.82}, 
{0.23, 5.77}, 
{1.32, 4.68}, 
{2.44, 3.56}, 
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
