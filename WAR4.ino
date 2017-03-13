#include <AFMotor.h> //import your motor shield library
#define trigPin A5// define the pins of your sensor
#define echoPin A3
#define trigPin1 A1
#define echoPin1 A2
#define led1 A0
#define led2 A4

// #define trigPin2 A1
// #define echoPin2 A4 




AF_DCMotor motor1(1,MOTOR12_64KHZ); // set up motors.
AF_DCMotor motor2(2, MOTOR12_8KHZ);
 
void setup() {
  Serial.begin(9600); // begin serial communication  
  Serial.println("Motor test!");
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
  pinMode(trigPin1, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin1, INPUT);
  //pinMode(trigPin2, OUTPUT);// set the trig pin to output (Send sound waves)
  //pinMode(echoPin2, INPUT);
  
  motor1.setSpeed(105); //set the speed of the motors, between 0-255
  motor2.setSpeed (130);  

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  
}

void moveStraight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  }

 void turn() {
  Serial.print ("Reorienting:\n");
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  delay(450);
  }

void led1Set() {
  digitalWrite(led1, HIGH);
  delay(100);

  digitalWrite(led1, LOW);
  delay(100);
  }

void led2Set() {
  
  digitalWrite(led2, HIGH);
  delay(100);
  digitalWrite(led2, LOW);
  delay(100);
  }


void infoMesh() {
  Serial.println ("\n \t Close Obstacle detected!" );
  Serial.println ("Obstacle Details:");
  }
  
void loop() {

  long duration, duration1, distance, distance1; // start the scan
  
  digitalWrite(trigPin, LOW);  
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;// convert the distance to centimeters.

  digitalWrite(trigPin1, LOW);  
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(5); //this delay is required as well!
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;// convert the distance to centimeters.
  
 if (distance <= 15)/*if there's an obstacle 25 centimers, ahead, do the following: */ {   
  infoMesh();
  Serial.print ("Distance in CM from left: ");
  Serial.print ( distance);
  Serial.print("\n\n");
  turn();
  led1Set();

}

 if (distance1 <= 15)/*if there's an obstacle 25 centimers, ahead, do the following: */ {   
  infoMesh();
  Serial.print ("Distance in CM from right: ");
  Serial.print ( distance1);
  Serial.print("\n\n");
  turn();
  led2Set();

}
 
  else {
   moveStraight();
}
}
