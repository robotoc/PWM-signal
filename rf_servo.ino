#include <RCSwitch.h> // communication library
#include <Servo.h>    // servo library

Servo myservo1; 
Servo myservo2; 
Servo myservo3; 
Servo myservo4; 
RCSwitch mySwitch = RCSwitch();
int led = 13;


void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin #2
  myservo1.attach(8);
  myservo2.attach(9);
  myservo3.attach(10);
  myservo4.attach(11);
  pinMode(13,OUTPUT);
}

void loop() 
 {
  if(mySwitch.getReceivedValue() == 7) //for servo 1
  {
   myservo1.write(180);
   delay(15);
   digitalWrite(13,HIGH);
  } 
  else if(mySwitch.getReceivedValue() == 11)//for servo 2
  {
    myservo2.write(180);
    delay(15);
    digitalWrite(13,HIGH);
  }
  else if(mySwitch.getReceivedValue() == 13)//for servo 3
  {
    myservo3.write(180);
    delay(15);
    digitalWrite(13,HIGH);
  }
  else if(mySwitch.getReceivedValue() == 14)//for servo 4
  {
    myservo4.write(180);
    delay(15);
    digitalWrite(13,HIGH);
  }
  else if(mySwitch.getReceivedValue() == 15)//this value used for reset all servo at 0 position
  {
    myservo1.write(0);
    myservo2.write(0);
    myservo3.write(0);
    myservo4.write(0);
    digitalWrite(13,LOW);
    delay(15);
  }
 }
  
