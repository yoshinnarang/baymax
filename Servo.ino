#include<Servo.h> // include server library
Servo servo_base,servo_mov,servo_finger; // create servo object to control a servo
 // initial position of server

//int BUTTON = 4;
int led1=8;
int led2=9;
int led3=10;
int led4=11;
String readString;


void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
  pinMode(led4,OUTPUT);
  digitalWrite(led1,LOW);
  
  digitalWrite(led2,LOW);
  digitalWrite(led3,LOW);
  digitalWrite(led4,LOW);
  
  Serial.begin(9600); // Serial comm begin at 9600bps
  servo_base.attach(3);// server is connected at pin 9
  servo_mov.attach(5);
  servo_finger.attach(6);
  servo_base.write(0);
  servo_finger.write(0);
  servo_mov.write(0);
  //pinMode(BUTTON,INPUT);
}

void loop() {
  
  while(Serial.available()){// if serial value is available 
    delay(3);
    char c = Serial.read();
    readString += c;
    Serial.println(readString);
  
    if (readString == "Crocin")
    {
      digitalWrite(led1,HIGH);
      servo_finger.write(180);
      delay(500);
      servo_base.write(40);
      delay(300);
      servo_mov.write(12),
      delay(200);
      servo_finger.write(70);
      delay(100);
      servo_mov.write(20);
      servo_finger.write(60);
      delay(200);
      servo_base.write(50);
      delay(50);

  // push
     // servo_finger.write(69);
     // delay(500);
      //servo_finger.write(180);
      //delay(200);
     // servo_base.write(0);
     // servo_finger.write(0);
     // servo_mov.write(0);
      readString = "";
    }
    
    else if((readString == "Volini")||(readString == "boli ne")||(readString == "bowling")||(readString == "volini")||(readString == "volume")) //if value input is equals to d
    {
      digitalWrite(led2,HIGH);
      servo_finger.write(180);
      delay(500);
      servo_base.write(130);
      delay(500);
      servo_mov.write(18);
      delay(500);
      servo_finger.write(70);
      delay(500);
      servo_mov.write(50);
      servo_finger.write(10); // push
      delay(3000);//delay time
      servo_finger.write(35);//pull
      servo_mov.write(35);
      delay(500);
      servo_mov.write(12);
      servo_finger.write(69);
      delay(500);
      servo_finger.write(180);
      delay(200);
      servo_base.write(0);
      servo_finger.write(0);
      servo_mov.write(0);
      readString = "";
    }
    else if(readString =="antibiotic")
    {
      digitalWrite(led3,HIGH);
      servo_finger.write(180);
      delay(500);
      servo_base.write(70);
      delay(500);
      servo_mov.write(0);
      delay(500);
      servo_finger.write(90);
      delay(500);
      servo_mov.write(7);
      delay(170);
      servo_finger.write(76);
      delay(200);
      servo_finger.write(50);
      servo_mov.write(19);//push
      delay(5000);
      servo_finger.write(90);//pull
      delay(100);
      servo_mov.write(5);
      servo_finger.write(90);
      delay(1000);
      servo_finger.write(85);
      servo_mov.write(0);
      servo_finger.write(80);
      delay(1000);
      servo_finger.write(180);
      delay(1000);
      servo_base.write(0);
      servo_mov.write(0);
      servo_finger.write(0);
      readString = "";
    }
    else if(readString == "Paracetamol")
    {
      digitalWrite(led4,HIGH);
      servo_finger.write(180);
      delay(500);
      servo_base.write(102);
      delay(500);
      servo_mov.write(0);
      delay(500);
      servo_finger.write(90);
      delay(500);
      servo_mov.write(7);
      delay(170);
      servo_finger.write(76);
      delay(200);
      servo_finger.write(60);
      servo_mov.write(19);//push
      delay(5000);
      servo_finger.write(90);//pull
      delay(50);
      servo_mov.write(0);
      servo_finger.write(95);
      delay(1000);
      servo_finger.write(180);
      delay(1000);
      servo_base.write(0);
      servo_mov.write(0);
      servo_finger.write(0);
      readString = ""; 
    }
  }
    readString = ""; 
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    digitalWrite(led4,LOW);
    
    
}
