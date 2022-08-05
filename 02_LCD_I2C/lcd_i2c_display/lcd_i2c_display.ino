#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup()
{
  lcd.begin();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PUNITH");

  String textLen;
}

void text_display_loc(String text, int x, int y)
{ 
  lcd.setCursor(x,y);
  lcd.print(text);
  delay(1000);
}

void heart_display(int x, int y)
  {
    byte customChar0[8] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000,
    0b00000
  };
  
  //lcd.clear();
  lcd.createChar(0, customChar0); // create a new custom character (index 0)
  lcd.setCursor(x, y); // move cursor to (2, 0)
  lcd.write((byte)0);  // print the custom char 0 at (2, 0)
  delay(1000);
}

void up_arrow_display(int x, int y)
  {
    byte customChar1[8] = {
    0b00100,
    0b01110,
    0b11111,
    0b00100,
    0b00100,
    0b00100,
    0b00100,
    0b00100
  };
  
  //lcd.clear();
  lcd.createChar(1, customChar1); // create a new custom character (index 0)
  lcd.setCursor(x, y); // move cursor to (2, 0)
  lcd.write((byte)1);  // print the custom char 0 at (2, 0)
  delay(1000);
}

void Bell_display(int x, int y)
  {
  byte Bell[8] = {
    0b00100,
    0b01110,
    0b01110,
    0b01110,
    0b11111,
    0b00000,
    0b00100,
    0b00000
  };
  //lcd.clear();
  lcd.createChar(2, Bell); // create a new custom character (index 0)
  lcd.setCursor(x, y); // move cursor to (2, 0)
  lcd.write((byte)2);  // print the custom char 0 at (2, 0)
  delay(1000);
}


void Alien_display(int x, int y)
  {
  byte Alien[8] = {
    0b11111,
    0b10101,
    0b11111,
    0b11111,
    0b01110,
    0b01010,
    0b11011,
    0b00000
  };  
  //lcd.clear();
  lcd.createChar(3, Alien); // create a new custom character (index 0)
  lcd.setCursor(x, y); // move cursor to (2, 0)
  lcd.write((byte)3);  // print the custom char 0 at (2, 0)
  delay(1000);
}


void Check_display(int x, int y)
  {
  byte Check[8] = {
    0b00000,
    0b00001,
    0b00011,
    0b10110,
    0b11100,
    0b01000,
    0b00000,
    0b00000
  };  
  //lcd.clear();
  lcd.createChar(4, Check); // create a new custom character (index 0)
  lcd.setCursor(x, y); // move cursor to (2, 0)
  lcd.write((byte)4);  // print the custom char 0 at (2, 0)
  delay(1000);
}

void Speaker_display(int x, int y)
  {
  byte Speaker[8] = {
    0b00001,
    0b00011,
    0b01111,
    0b01111,
    0b01111,
    0b00011,
    0b00001,
    0b00000
  };
  //lcd.clear();
  lcd.createChar(5, Speaker); // create a new custom character (index 0)
  lcd.setCursor(x, y); // move cursor to (2, 0)
  lcd.write((byte)5);  // print the custom char 0 at (2, 0)
  delay(1000);
}


void Skull_display(int x, int y)
  {
  byte Skull[8] = {
    0b00000,
    0b01110,
    0b10101,
    0b11011,
    0b01110,
    0b01110,
    0b00000,
    0b00000
  };
  //lcd.clear();
  lcd.createChar(6, Skull); // create a new custom character (index 0)
  lcd.setCursor(x, y); // move cursor to (2, 0)
  lcd.write((byte)6);  // print the custom char 0 at (2, 0)
  delay(1000);
}

void Lock_display(int x, int y)
  {
  
  byte Lock[8] = {
    0b01110,
    0b10001,
    0b10001,
    0b11111,
    0b11011,
    0b11011,
    0b11111,
    0b00000
  };
  //lcd.clear();
  lcd.createChar(7, Lock); // create a new custom character (index 0)
  lcd.setCursor(x, y); // move cursor to (2, 0)
  lcd.write((byte)7);  // print the custom char 0 at (2, 0)
  delay(1000);
}


void scrollMessageLeftTwo(int row, String message, int delayTime, int totalColumns) {
  for (int i=0; i < totalColumns; i++) {
    message = " " + message;  
  } 
  message = message + " "; 
  for (int position = 0; position < message.length(); position++) {
    lcd.setCursor(0, row);
    lcd.print(message.substring(position, position + totalColumns));
    delay(delayTime);
  }
}


void scrollMessageRight(int row, String message, int delayTime, int totalColumns) {
  //lcd.setCursor(0, row);
  int textLen = sizeof(message) - 1;
  lcd.print(message);
  for (int positionCounter = 0; positionCounter < textLen + totalColumns; positionCounter++) {
    lcd.scrollDisplayRight();
    delay(delayTime);
  }
}

void scrollMessageLeft(int row, String message, int delayTime, int totalColumns) {
  //lcd.setCursor(0, row);
  int textLen = sizeof(message) - 1;
  lcd.print(message);
  for (int positionCounter = 0; positionCounter < textLen + totalColumns; positionCounter++) {
    lcd.scrollDisplayLeft();
    delay(delayTime);
  }
}

void loop()
{
  lcd.clear();
  scrollMessageLeft(1, "KPN LEFT TEXT", 500, 10);
  lcd.clear();
  scrollMessageRight(1, "KPN RIGHT TEXT", 500, 10);
  delay(500);
  lcd.clear();
  heart_display(0,0);
  text_display_loc("KPN LCD CHECK", 2, 0);
  up_arrow_display(0, 1);
  Bell_display(1, 1); //CR
  Alien_display(2, 1); //CR
  Speaker_display(3, 1); //CR
  Skull_display(4, 1); //CR
  Lock_display(5, 1); //CR
  
}

//https://create.arduino.cc/projecthub/akshayjoseph666/interface-i2c-16x2-lcd-with-arduino-uno-just-4-wires-273b24
//https://lastminuteengineers.com/i2c-lcd-arduino-tutorial/
//https://microcontrollerslab.com/i2c-lcd-arduino-tutorial/
