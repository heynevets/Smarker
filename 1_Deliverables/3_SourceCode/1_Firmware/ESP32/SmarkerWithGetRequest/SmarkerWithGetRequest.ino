// Client
const char* clientssid     = "Meme";
const char* clientpassword = "smarker123";



// WIFI AP
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>

const char *ssid = "smk";
const char *password = "aabbccdd";
WiFiServer server(80);

// SERVO
#include <Servo.h>
static const int servoPin = 13;
Servo servo1;
int servo_start = 30;
int servo_end = 60;

// MOTOR
#include "AccelStepper.h"
#include "MultiStepper.h"

// GET counter 
int getCounter = 0; //
int getRefresh = 20; // refresh every 20 steps

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

  // AP
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  // Client
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(clientssid);  
  WiFi.begin(clientssid, clientpassword);
  
  while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  // Servo
  servo1.attach(servoPin);  
  stepper1.setMaxSpeed(150);
  stepper2.setMaxSpeed(150);
  stepper1.setAcceleration(100.0);
  stepper1.setSpeed(10);
  stepper2.setAcceleration(100.0);
  stepper2.setSpeed(10);
  steppers.addStepper(stepper1);
  steppers.addStepper(stepper2);
  stepper1.setCurrentPosition(0);
  stepper2.setCurrentPosition(0);
}

void pingLive(WiFiClient client) {  
  const int httpPort = 80;
  String url = "/?status=true";
  String hostname = "api.smarker.fun";

  const char* host = hostname.c_str();  
  Serial.println("hostname: " + hostname);
  Serial.println("url: " + url);
  if (!client.connect(host, httpPort)) {
      Serial.println("connection failed");
      return;
  }
  Serial.print("Requesting URL: ");
  Serial.println(url);

  client.print(String("GET ") + url + " HTTP/1.1\r\n" +
               "Host: " + host + "\r\n" +
               "Conection: close\r\n\r\n");
                   
  unsigned long timeout = millis();            
  while (client.available() == 0) {
      if (millis() - timeout > 5000) {
          Serial.println(">>> Client Timeout !");
          client.stop();
          return;
      }
  }

  // Read all the lines of the reply from server and print them to Serial
  String content = "";
  while(client.available()) {
      String line = client.readStringUntil('\r');                
      if (!line.equals("HTTP/1.1 200 OK")) {
      }                                          
      content += line;
  }        
  Serial.println("closing connection");
  
  
}

void loop() {

  //wifiCheck(server);

    int i = 0;

  while (i >= 0) {
    long position[2]; // = {stepper1.currentPosition() + positions[i][0], stepper2.currentPosition() + positions[i][1]};     
          
    position[0] = positions[i][0] * numStepsPerRev/66/PI + stepper1.currentPosition();
    position[1] = -positions[i][1] * numStepsPerRev/66/PI + stepper2.currentPosition();

//    Serial.print("current I: ");
//    Serial.println(i);
//    Serial.print("delta 0: ");
//    printDouble(positions[i][0], 3);
//    Serial.print("delta 1: ");
//    printDouble(positions[i][1], 3);
//    Serial.println(">>>");
    
//    Serial.print("current position 0:");
//    printDouble(stepper1.currentPosition(), 3);
//    Serial.print("target position 0:");
//    printDouble(position[0], 3);

//    Serial.print("current position 1:");
//    printDouble(stepper2.currentPosition(), 3);
//    Serial.print("target position 1:");
//    printDouble(position[1], 3);

//    Serial.println("^-----------------");
    
    steppers.moveTo(position);
    steppers.runSpeedToPosition(); // Blocks until all are in position  

    i = (i + 1) % SIZE;



    WiFiClient client = server.available();   // listen for incoming clients
    if (client) {                          // if you get a client,
      Serial.println("New Client.");           // print a message out the serial port
      String currentLine = "";                // make a String to hold incoming data from the client
      
      while (client.connected()) {            // loop while the client's connected      
        if (client.available()) {             // if there's bytes to read from the client,
          char c = client.read();             // read a byte, then
          Serial.write(c);                    // print it out the serial monitor
          if (c == '\n') {                    // if the byte is a newline character
  
            // if the current line is blank, you got two newline characters in a row.
            // that's the end of the client HTTP request, so send a response:
            if (currentLine.length() == 0) {
              // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
              // and a content-type so the client knows what's coming, then a blank line:
              client.println("HTTP/1.1 200 OK");
              client.println("Content-type:text/html");
              client.println();
  
              // the content of the HTTP response follows the header:
              client.print("Click <a href=\"/up\">here</a> to toggle UP<br>");
              client.print("Click <a href=\"/down\">here</a> to toggle DOWN<br>");
  
              // The HTTP response ends with another blank line:
              client.println();
              // break out of the while loop:
              break;
            } else {    // if you got a newline, then clear currentLine:
              currentLine = "";
            }
          } else if (c != '\r') {  // if you got anything else but a carriage return character,
            currentLine += c;      // add it to the end of the currentLine
          }
  
          if (currentLine.endsWith("GET /up")) {
            moveServoUp();
          }
          if (currentLine.endsWith("GET /down")) {
            moveServoDown();
          }
        }
      }
      // close the connection:
      client.stop();
      Serial.println("Client Disconnected.");
    }
    // ping live 
    if (getCounter == 0) {
      pingLive(client);
    }
    getCounter = (getCounter + 1) % getRefresh;
  }
  

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

void moveServoUp() {
  for(int posDegrees = 30; posDegrees <= 60; posDegrees++) {
        servo1.write(posDegrees);
        Serial.println(posDegrees);
        delay(20);
    }
}

void moveServoDown() {
  for(int posDegrees = 60; posDegrees >= 30; posDegrees--) {
        servo1.write(posDegrees);
        Serial.println(posDegrees);
        delay(20);
    }
}
