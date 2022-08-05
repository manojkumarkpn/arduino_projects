#include <SoftwareSerial.h>

SoftwareSerial BT_Serial(10, 11);
const int Light = 6; // Relay pin 1 (IN1)

void setup() {
  Serial.begin(19200);
  Serial.println("BT Messenger");
  pinMode(Light, OUTPUT);
  BT_Serial.begin(38400);
}

void loop() {
  String outMsg;
  int incomingByte;
  byte byteCounter = 0;
  byte words[64];
  
  if (BT_Serial.available() > 0) {
    Serial.println("got data"); 
    incomingByte = BT_Serial.read();
    while (incomingByte > 0){
        words[byteCounter++] = incomingByte;
        Serial.print(incomingByte,DEC);    
        incomingByte = BT_Serial.read();
        Serial.print(" ");
      } // while
      Serial.println("");
      for (int x = 0; x < byteCounter; x++){
        outMsg += char(words[x]);
      } // for
      Serial.println(outMsg);

      if(outMsg=="light on"){
        digitalWrite(Light, HIGH);
      }
      else if(outMsg=="light off"){
        digitalWrite(Light, LOW);
      }
      
    } // if (BT_Serial.available()
} // loop()
