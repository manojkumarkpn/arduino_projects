/********************************************************************
 * Author : N Manoj Kumar
 * Topic : Basic motor movements using Arduino and L293d Interface module
 * Motor driver module
 *  - Forward   - IN1 = 1 , IN2 = 0, IN3 = 1 , IN4 = 0
 *  - Backward  - IN1 = 0 , IN2 = 1, IN3 = 0 , IN4 = 1
 *  - Left      - IN1 = 0 , IN2 = 0, IN3 = 1 , IN4 = 0
 *  - Right     - IN1 = 1 , IN2 = 0, IN3 = 0 , IN4 = 0
 * Arduino interface
 *  PIN 3 - IN1 
 *  PIN 5 - IN2
 *  PIN 6 - IN3
 *  PIN 9 - IN4
 *******************************************************************/
const int IN1 = 3;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 9;
const int speed = 255;
const int stop = 0;

void setup(){
  pinMode(IN1, OUTPUT);  // set up the pin as an OUTPUT FOR IN1
  pinMode(IN2, OUTPUT);  // set up the pin as an OUTPUT FOR IN2
  pinMode(IN3, OUTPUT);  // set up the pin as an OUTPUT FOR IN3
  pinMode(IN4, OUTPUT);  // set up the pin as an OUTPUT FOR IN4
  Serial.begin(9600);         // initialize Serial communications
}

void loop(){
  int delayTime = 5000;
  motor_forward();
  delay(delayTime);
  motor_reverse();
  delay(delayTime);
  motor_left();
  delay(delayTime);
  motor_right();
  delay(delayTime);
  motor_stop();
  delay(delayTime);
}

void motor_stop(){
  analogWrite(IN1, stop);
  analogWrite(IN2, stop);
  analogWrite(IN3, stop);
  analogWrite(IN4, stop);
}

void motor_forward(){
  analogWrite(IN1, speed);
  analogWrite(IN2, stop);
  analogWrite(IN3, speed);
  analogWrite(IN4, stop);
}

void motor_reverse(){
  analogWrite(IN1, stop);
  analogWrite(IN2, speed);
  analogWrite(IN3, stop);
  analogWrite(IN4, speed);
}

void motor_left(){
  analogWrite(IN1, stop);
  analogWrite(IN2, stop);
  analogWrite(IN3, speed);
  analogWrite(IN4, stop);
}

void motor_right(){
  analogWrite(IN1, speed);
  analogWrite(IN2, stop);
  analogWrite(IN3, stop);
  analogWrite(IN4, stop);
}
