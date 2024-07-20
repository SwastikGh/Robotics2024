#include <AFMotor.h>

//defining pins and variables
#define left A0
#define right A1

//defining motors
AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);



void setup() {
  //declaring pin types
  pinMode(left,INPUT);
  pinMode(right,INPUT);
  //begin serial communication
  Serial.begin(9600);
  
}

void loop(){
  //printing values of the sensors to the serial monitor
  Serial.println(digitalRead(left));
  
  Serial.println(digitalRead(right));

  //line detected by both
  if(!digitalRead(left)==0 && !digitalRead(right)==0){
    //both on black
    motor1.run(FORWARD);
    motor1.setSpeed(70);
    motor2.run(FORWARD);
    motor2.setSpeed(70);
    motor3.run(FORWARD);
    motor3.setSpeed(70);
    motor4.run(FORWARD);
    motor4.setSpeed(70);
  }
  else if(digitalRead(left)==0 && digitalRead(right)==0){
    //both on white
    motor1.run(BACKWARD);
    motor1.setSpeed(60);
    motor2.run(BACKWARD);
    motor2.setSpeed(60);
    motor3.run(BACKWARD);
    motor3.setSpeed(60);
    motor4.run(BACKWARD);
    motor4.setSpeed(60);
  }

  else {
  //line detected by left sensor
    if(!digitalRead(left)==0 && digitalRead(right)==0){
    //turn left
    motor1.run(FORWARD);
    motor1.setSpeed(100);
    motor2.run(FORWARD);
    motor2.setSpeed(255);
    motor3.run(BACKWARD);
    motor3.setSpeed(255);
    motor4.run(BACKWARD);
    motor4.setSpeed(100);
    
  }
  //line detected by right sensor
    else if(digitalRead(left)==0 && !analogRead(right)==0){

    //turn right
    motor1.run(BACKWARD);
    motor1.setSpeed(100);
    motor2.run(BACKWARD);
    motor2.setSpeed(255);
    motor3.run(FORWARD);
    motor3.setSpeed(255);
    motor4.run(FORWARD);
    motor4.setSpeed(100);
   
  }
  //line detected by none
  
  }
}