#include <AFMotor.h>      //add Adafruit Motor Shield library


AF_DCMotor leftMotor1(3, MOTOR12_1KHZ); // create motor #1 using M1 output on Motor Drive Shield, set to 1kHz PWM frequency
AF_DCMotor leftMotor2(1, MOTOR12_1KHZ); // create motor #2, using M2 output, set to 1kHz PWM frequency
AF_DCMotor rightMotor1(4, MOTOR34_1KHZ);// create motor #3, using M3 output, set to 1kHz PWM frequency
AF_DCMotor rightMotor2(2, MOTOR34_1KHZ);// create motor #4, using M4 output, set to 1kHz PWM frequency

int leftDistance, rightDistance; //distances on either side
int curDist = 0;
String motorSet = "";
int speedSet = 0;
String readString;
int MAX_SPEED= 150;
//-------------------------------------------- SETUP LOOP ----------------------------------------------------------------------------
void setup() {
  Serial.begin(9600);
  
  delay(1000); // delay for one seconds
  
 }
//------------------------------------------------------------------------------------------------------------------------------------

//---------------------------------------------MAIN LOOP ------------------------------------------------------------------------------
void loop() {
  while(Serial.available()){
  char c = Serial.read();
  readString += c;
  Serial.println(readString);
  if(readString == "baymax")
  {
    moveForward();  // move forward
  delay(500);
  }
  if(readString == "stop"){
    moveStop();
  }
    if(readString == "turn left"){
      turnLeft();
    }
    if(readString == "turn right"){
      turnRight();
    }
    if(readString == "turn around"){
      turnAround();
    }
    readString ="";
 }
//-------------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------------


}
//-------------------------------------------------------------------------------------------------------------------------------------
void moveStop() {leftMotor1.run(RELEASE); leftMotor2.run(RELEASE); rightMotor1.run(RELEASE); rightMotor2.run(RELEASE);}  // stop the motors.
//-------------------------------------------------------------------------------------------------------------------------------------
void moveForward() {
    motorSet = "FORWARD";
    leftMotor1.run(FORWARD);      // turn it on going forward
    leftMotor2.run(FORWARD);      // turn it on going forward
    rightMotor1.run(FORWARD);     // turn it on going forward
    rightMotor2.run(FORWARD);     // turn it on going forward
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    leftMotor1.setSpeed(speedSet);
    leftMotor2.setSpeed(speedSet);
    rightMotor1.setSpeed(speedSet); 
    rightMotor2.setSpeed(speedSet);
    delay(5);
  }
}
//-------------------------------------------------------------------------------------------------------------------------------------
void moveBackward() {
    motorSet = "BACKWARD";
    leftMotor1.run(BACKWARD);     // turn it on going backward
    leftMotor2.run(BACKWARD);     // turn it on going backward
    rightMotor1.run(BACKWARD);    // turn it on going backward
    rightMotor2.run(BACKWARD);    // turn it on going backward
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) // slowly bring the speed up to avoid loading down the batteries too quickly
  {
    leftMotor1.setSpeed(speedSet);
    leftMotor2.setSpeed(speedSet);
    rightMotor1.setSpeed(speedSet); 
    rightMotor2.setSpeed(speedSet); 
    delay(5);
  }
}  
//-------------------------------------------------------------------------------------------------------------------------------------
void turnRight() {
  motorSet = "RIGHT";
  leftMotor1.run(FORWARD);      // turn motor 1 forward
  leftMotor2.run(FORWARD);      // turn motor 2 forward
  rightMotor1.run(BACKWARD);    // turn motor 3 backward
  rightMotor2.run(BACKWARD);    // turn motor 4 backward
  rightMotor1.setSpeed(speedSet+40);      
  rightMotor2.setSpeed(speedSet+40);     
  delay(1500); // run motors this way for 1500        
  motorSet = "FORWARD";
  leftMotor1.run(FORWARD);      // set both motors back to forward
  leftMotor2.run(FORWARD);
  rightMotor1.run(FORWARD);
  rightMotor2.run(FORWARD);      
}  
//-------------------------------------------------------------------------------------------------------------------------------------
void turnLeft() {
  motorSet = "LEFT";
  leftMotor1.run(BACKWARD);      // turn motor 1 backward
  leftMotor2.run(BACKWARD);      // turn motor 2 backward
  leftMotor1.setSpeed(speedSet+40);     
  leftMotor2.setSpeed(speedSet+40);    
  rightMotor1.run(FORWARD);     // turn motor 3 forward
  rightMotor2.run(FORWARD);     // turn motor 4 forward
  delay(1500); // run motors this way for 1500  
  motorSet = "FORWARD";
  leftMotor1.run(FORWARD);      // turn it on going forward
  leftMotor2.run(FORWARD);      // turn it on going forward
  rightMotor1.run(FORWARD);     // turn it on going forward
  rightMotor2.run(FORWARD);     // turn it on going forward
}  
//-------------------------------------------------------------------------------------------------------------------------------------
void turnAround() {
  motorSet = "RIGHT";
  leftMotor1.run(FORWARD);      // turn motor 1 forward
  leftMotor2.run(FORWARD);      // turn motor 2 forward
  rightMotor1.run(BACKWARD);    // turn motor 3 backward
  rightMotor2.run(BACKWARD);    // turn motor 4 backward
  rightMotor1.setSpeed(speedSet+40);      
  rightMotor2.setSpeed(speedSet+40);
  delay(1700); // run motors this way for 1700
  motorSet = "FORWARD";
  leftMotor1.run(FORWARD);      // set both motors back to forward
  leftMotor2.run(FORWARD);
  rightMotor1.run(FORWARD);
  rightMotor2.run(FORWARD);      
}  
