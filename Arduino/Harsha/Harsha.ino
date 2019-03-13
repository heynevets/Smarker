

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
#define SIZE 243
long positions[SIZE][2] = {
{-1.45, 5.73}, 
{-6.49, 9.77}, 
{-1.88, 5.34}, 
{7.57, -3.95}, 
{7.99, -2.34}, 
{6.54, -1.93}, 
{-32.77, 33.33}, 
{-8.20, 9.82}, 
{3.26, 5.84}, 
{2.53, 5.67}, 
{5.78, 5.39}, 
{4.69, 4.26}, 
{5.11, 4.36}, 
{4.69, 4.44}, 
{2.32, 3.49}, 
{3.20, 3.58}, 
{3.39, 3.61}, 
{2.26, 3.97}, 
{1.54, 3.92}, 
{1.07, 4.75}, 
{-4.12, 7.77}, 
{115.20, -113.06}, 
{-15.31, 17.49}, 
{-5.07, 8.82}, 
{-2.85, 6.13}, 
{-2.57, 6.98}, 
{-4.02, 8.43}, 
{-1.09, 6.42}, 
{1.03, 3.50}, 
{0.46, 4.29}, 
{-0.87, 5.18}, 
{0.81, 2.72}, 
{1.39, 2.28}, 
{1.19, 2.72}, 
{1.20, 2.19}, 
{2.69, 0.97}, 
{4.05, 0.96}, 
{6.51, 3.00}, 
{7.27, 0.89}, 
{5.35, 2.08}, 
{5.47, 0.50}, 
{5.16, -0.31}, 
{4.67, -0.40}, 
{5.27, -0.40}, 
{6.92, -2.86}, 
{18.10, -14.39}, 
{24.59, -22.13}, 
{-115.27, 118.79}, 
{11.49, -7.42}, 
{2.27, 2.74}, 
{2.19, 2.69}, 
{3.27, 0.98}, 
{2.43, 2.81}, 
{1.60, 2.01}, 
{2.76, 1.30}, 
{3.90, 1.70}, 
{3.32, 0.64}, 
{3.32, 2.31}, 
{2.97, 1.01}, 
{3.02, 1.26}, 
{2.67, 1.63}, 
{3.72, 0.73}, 
{3.91, -0.02}, 
{2.64, 0.55}, 
{22.81, -21.00}, 
{16.15, -14.57}, 
{7.83, -4.34}, 
{1.40, 2.87}, 
{-1.40, 5.29}, 
{-0.29, 4.12}, 
{1.28, 4.38}, 
{0.01, 4.07}, 
{2.22, 1.44}, 
{2.49, 2.55}, 
{2.01, 3.58}, 
{1.69, 2.46}, 
{0.62, 3.32}, 
{54.59, -57.25}, 
{-17.84, 18.42}, 
{7.45, -2.06}, 
{6.25, -0.52}, 
{5.37, -1.62}, 
{5.01, -1.77}, 
{4.66, -0.67}, 
{3.30, 1.23}, 
{3.54, 1.52}, 
{4.53, 0.04}, 
{14.95, -11.47}, 
{26.79, -24.70}, 
{15.24, -12.33}, 
{5.86, -2.41}, 
{1.95, 1.95}, 
{1.31, 2.17}, 
{3.52, 1.50}, 
{3.35, 0.76}, 
{2.02, 1.51}, 
{1.56, 2.27}, 
{2.67, 2.25}, 
{-60.23, 57.54}, 
{-1.11, 1.39}, 
{2.01, 1.33}, 
{2.14, 0.95}, 
{3.03, 0.68}, 
{4.17, -0.78}, 
{3.75, -0.59}, 
{2.81, 0.48}, 
{7.95, -4.25}, 
{25.77, -23.49}, 
{16.96, -13.83}, 
{8.42, -3.69}, 
{4.39, -0.26}, 
{4.24, 0.11}, 
{3.67, -0.04}, 
{3.64, 0.04}, 
{4.73, 0.02}, 
{4.13, 0.07}, 
{-13.71, 16.38}, 
{-8.88, 11.73}, 
{4.33, -0.87}, 
{3.64, 0.15}, 
{-22.54, 24.95}, 
{-13.53, 15.02}, 
{1.16, 2.62}, 
{4.57, -1.29}, 
{2.23, 0.86}, 
{1.78, 1.40}, 
{3.45, -0.10}, 
{3.70, 0.60}, 
{4.11, -0.63}, 
{7.94, -4.97}, 
{24.20, -22.24}, 
{15.54, -13.22}, 
{7.01, -3.06}, 
{3.76, 1.03}, 
{1.33, 3.48}, 
{1.14, 3.54}, 
{1.95, 3.32}, 
{2.57, 1.48}, 
{1.31, 2.35}, 
{0.88, 4.50}, 
{1.38, 4.24}, 
{-67.16, 64.03}, 
{-0.41, 0.68}, 
{9.38, -5.24}, 
{8.10, -4.76}, 
{5.99, -2.73}, 
{2.82, 1.93}, 
{-3.56, 7.56}, 
{-6.92, 10.14}, 
{-3.62, 7.49}, 
{0.19, 3.95}, 
{76.40, -80.72}, 
{0.10, 0.04}, 
{3.84, 2.61}, 
{3.19, 3.59}, 
{2.58, 2.33}, 
{2.00, 2.78}, 
{3.44, 1.26}, 
{2.58, 2.52}, 
{2.16, 5.10}, 
{2.81, 2.56}, 
{3.24, 2.03}, 
{3.48, 2.68}, 
{3.50, 2.00}, 
{3.48, 2.65}, 
{2.30, 3.02}, 
{3.52, 0.44}, 
{6.47, -3.07}, 
{-0.45, 3.88}, 
{-70.43, 67.32}, 
{0.35, 0.51}, 
{7.01, -1.43}, 
{0.52, 3.78}, 
{1.02, 2.36}, 
{3.10, 1.72}, 
{2.78, 2.28}, 
{2.99, 1.93}, 
{3.38, 0.81}, 
{2.60, 1.50}, 
{2.88, 1.88}, 
{3.59, 0.67}, 
{1.90, 1.51}, 
{2.04, 3.16}, 
{1.73, 3.02}, 
{1.29, 2.34}, 
{58.99, -62.05}, 
{0.30, -0.18}, 
{-1.17, 4.43}, 
{0.98, 3.74}, 
{0.60, 3.84}, 
{2.03, 3.75}, 
{1.46, 4.46}, 
{0.11, 3.62}, 
{-1.51, 4.70}, 
{-24.20, 25.73}, 
{-13.16, 15.33}, 
{-3.07, 8.08}, 
{0.67, 3.18}, 
{0.40, 2.77}, 
{3.61, -0.35}, 
{6.52, -2.07}, 
{21.66, -19.18}, 
{20.64, -18.49}, 
{13.28, -10.28}, 
{2.81, 0.76}, 
{0.26, 3.45}, 
{0.04, 3.84}, 
{-0.23, 4.11}, 
{1.98, 3.48}, 
{0.10, 4.27}, 
{-1.27, 4.55}, 
{-0.08, 4.02}, 
{0.97, 3.92}, 
{-0.01, 4.12}, 
{57.22, -60.27}, 
{-9.37, 9.66}, 
{6.70, -2.90}, 
{7.08, -3.70}, 
{7.47, -3.59}, 
{3.94, -0.18}, 
{4.06, 1.17}, 
{7.21, -1.54}, 
{7.08, -1.65}, 
{11.20, -7.56}, 
{28.99, -27.39}, 
{14.52, -11.54}, 
{4.55, -0.54}, 
{1.99, 1.33}, 
{3.05, 0.70}, 
{2.24, 1.06}, 
{0.39, 3.73}, 
{2.44, 1.59}, 
{6.61, -2.45}, 
{-91.05, 88.48}, 
{2.72, -2.05}, 
{5.05, -0.64}, 
{3.97, 0.09}, 
{4.69, -0.01}, 
{5.03, -0.21}, 
{8.00, -3.59}, 
{20.33, -17.63}, 
{17.91, -15.58}, 
{10.13, -6.82}, 
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
