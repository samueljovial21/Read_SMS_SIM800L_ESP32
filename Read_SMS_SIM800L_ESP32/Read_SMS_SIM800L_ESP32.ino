/*
 GitHub : samueljovial21
 https://github.com/samueljovial21
*/

#include <SoftwareSerial.h>

#define rxPin 4
#define txPin 2
HardwareSerial sim800(1);

String messages;

void setup(){
  // Begin Serial Monitor at 115200 baud rate
	Serial.begin(115200);
  // Begin serial communication with Arduino IDE and SIM800L
  sim800.begin(9600, SERIAL_8N1, rxPin, txPin);
  sim800.println("AT+CMGF=1");  // Configuring TEXT mode
  sim800.println("AT+CNMI=1,2,0,0,0");
}

void loop(){

  if (Serial.available()) {
    sim800.write(Serial.read());
  }
  
  if (sim800.available() > 0) {
    messages = sim800.readStringUntil('\n');
    Serial.println(messages);
  }
  
}
