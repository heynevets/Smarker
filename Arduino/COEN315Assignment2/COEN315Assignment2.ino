/*
  WiFiAccessPoint.ino creates a WiFi access point and provides a web server on it.

  Steps:
  1. Connect to the access point "yourAp"
  2. Point your web browser to http://192.168.4.1/H to turn the LED on or http://192.168.4.1/L to turn it off
     OR
     Run raw TCP "GET /H" and "GET /L" on PuTTY terminal with 192.168.4.1 as IP address and 80 as port

  Created for arduino-esp32 on 04 July, 2018
  by Elochukwu Ifediora (fedy0)
*/
#include <FS.h>
#include "SPIFFS.h"
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>
#define LED1 4


// Set these to your desired credentials.
const char *ssid = "Ting-yu";
const char *password = "";

//WiFiServer server(80);
WebServer server(80);


String LED1Status;
String LED2Status;

void setup() {
  pinMode(LED1, OUTPUT);
  pinMode(2, OUTPUT);

  LED1Status = "off";
  LED2Status = "off";
  digitalWrite(LED1, LOW);
  digitalWrite(2, LOW);


  Serial.begin(115200);
  Serial.println();
  Serial.println("Configuring access point...");

  // You can remove the password parameter if you want the AP to be open.
  WiFi.softAP(ssid, password);
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
  server.begin();

  Serial.println("Server started");
  
  server.on("/", fileindex);
  server.on("/index.html", fileindex);
  server.on("/bootstrap.min.css", bootstrap);
  server.on("bootstrap.min.css", bootstrap);
  server.on("/popper.min.js", popper);
  server.on("/bootstrap.min.js", bootstrapmin);
  server.on("bootstrap.min.js", bootstrapmin);
  server.on("/background.jpg", backgroundImg);
  server.on("bootstrap.jpg", backgroundImg);

  
  server.on("/on", LED1On);
  server.on("/on2", LED2On);
  server.on("/off", LED1Off);
  server.on("/off2", LED2Off);

  SPIFFS.begin();  
}
void LED1On() {
  digitalWrite(LED1, HIGH);
  fileindex();
}
void LED2On() {
  digitalWrite(2, HIGH);
  fileindex();
}
void LED1Off() {
  digitalWrite(LED1, LOW);
  fileindex();
}
void LED2Off() {
  digitalWrite(2, LOW);
  fileindex();
}

void backgroundImg() {
  File file = SPIFFS.open("/background.jpg.gz", "r");
  size_t sent = server.streamFile(file, "image/jpeg");
}

void fileindex()
{
  File file = SPIFFS.open("/index.html.gz", "r");
  size_t sent = server.streamFile(file, "text/html");
}
void bootstrap()
{
  File file = SPIFFS.open("/bootstrap.min.css.gz", "r");
  size_t sent = server.streamFile(file, "text/css");
}
void popper()
{
  File file = SPIFFS.open("/popper.min.js.gz", "r");
  size_t sent = server.streamFile(file, "application/javascript");
}
void bootstrapmin()
{
  File file = SPIFFS.open("/bootstrap.min.js.gz", "r");
  size_t sent = server.streamFile(file, "application/javascript");
}

void loop() {
  server.handleClient();


// The following is my old code using assignment template, but I wanted to incorporate nicer UI, hence the bootstrap webpage
//  
//  WiFiClient client = server.available();   // listen for incoming clients
//
//  if (client) {                             // if you get a client,
//    Serial.println("New Client.");           // print a message out the serial port
//    String currentLine = "";                // make a String to hold incoming data from the client
//    while (client.connected()) {            // loop while the client's connected
//      if (client.available()) {             // if there's bytes to read from the client,
//        char c = client.read();             // read a byte, then
//        Serial.write(c);                    // print it out the serial monitor
//        if (c == '\n') {                    // if the byte is a newline character
//
//          // if the current line is blank, you got two newline characters in a row.
//          // that's the end of the client HTTP request, so send a response:
//          if (currentLine.length() == 0) {
//            // HTTP headers always start with a response code (e.g. HTTP/1.1 200 OK)
//            // and a content-type so the client knows what's coming, then a blank line:
//            client.println("HTTP/1.1 200 OK");
//            client.println("Content-type:text/html");
//            client.println();
//
//            // the content of the HTTP response follows the header:
//            client.print("Click <a href=\"/on\">here</a> to turn ON the RED LED.<br>");
//            client.print("Click <a href=\"/off\">here</a> to turn OFF the RED LED.<br>");
//
//
//
//            // the content of the HTTP response follows the header:
//            client.println("<br>");
//            client.print("Click <a href=\"/on2\">here</a> to turn ON the YELLOW LED.<br>");
//            client.print("Click <a href=\"/off2\">here</a> to turn OFF the YELLOW LED.<br>");
//
//            // The HTTP response ends with another blank line:
//            client.println();
//            // break out of the while loop:
//            break;
//          } else {    // if you got a newline, then clear currentLine:
//            currentLine = "";
//          }
//        } else if (c != '\r') {  // if you got anything else but a carriage return character,
//          currentLine += c;      // add it to the end of the currentLine
//        }
//
//        
//        if (currentLine.endsWith("GET /on ")) {
//          digitalWrite(LED1, HIGH);              
//        } else if (currentLine.endsWith("GET /off ")) {
//          digitalWrite(LED1, LOW);               
//        } else if (currentLine.endsWith("GET /on2")) {
//          digitalWrite(2, HIGH);              
//        } else if (currentLine.endsWith("GET /off2")) {
//          digitalWrite(2, LOW);               
//        }        
//      }
//    }
//    // close the connection:
//    client.stop();
//    Serial.println("Client Disconnected.");
//  }
}
