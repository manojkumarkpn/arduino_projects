/********************************************************************
 * Author : N Manoj Kumar
 * Topic : Obstacle detatction and  movements using Arduino, ultrasonic sensor and L293d Interface module
 * Motor driver module
 *  - Forward   - IN1 = 1 , IN2 = 0, IN3 = 1 , IN4 = 0
 *  - Backward  - IN1 = 0 , IN2 = 1, IN3 = 0 , IN4 = 1
 *  - Left      - IN1 = 0 , IN2 = 0, IN3 = 1 , IN4 = 0
 *  - Right     - IN1 = 1 , IN2 = 0, IN3 = 0 , IN4 = 0
 * Arduino UNO interface with L293D
 *  PIN 3 - IN1 
 *  PIN 5 - IN2
 *  PIN 6 - IN3
 *  PIN 9 - IN4
 * Arduino UNO interface with ultrasonic sensor  
 *  PIN 11 - trig 
 *  PIN 10 - echo
 *******************************************************************/
const int IN1 = 3;
const int IN2 = 5;
const int IN3 = 6;
const int IN4 = 9;
const int speed = 150;
const int stop = 0;

const int trigPin  = 13;
const int echoPin = 12;    // Echo


void setup(){
  pinMode(IN1, OUTPUT);  // set up the pin as an OUTPUT FOR IN1
  pinMode(IN2, OUTPUT);  // set up the pin as an OUTPUT FOR IN2
  pinMode(IN3, OUTPUT);  // set up the pin as an OUTPUT FOR IN3
  pinMode(IN4, OUTPUT);  // set up the pin as an OUTPUT FOR IN4
  Serial.begin(9600);         // initialize Serial communications
}

void loop(){
  int delayTime = 500;
  long distance = ultra_sonic_distance();
  Serial.println(distance);
  if(distance > 40){
    motor_forward();
    //delay(delayTime);
  }
  else{
    motor_stop();
    delay(delayTime);
    motor_left();
    delay(delayTime);
  }
  //motor_reverse();
  //delay(delayTime);

 // motor_right();
 // delay(delayTime);
 // motor_stop();
 // delay(delayTime);
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


int ultra_sonic_distance(){
  long duration, cm, inches;
  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  // Convert the time into a distance
  cm = (duration/2) / 29.1;     // Divide by 29.1 or multiply by 0.0343
  //inches = (duration/2) / 74;   // Divide by 74 or multiply by 0.0135
  return cm;
}

