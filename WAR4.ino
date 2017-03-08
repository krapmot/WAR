#include <AFMotor.h> //import your motor shield library
#define trigPin A5// define the pins of your sensor
#define echoPin A3
 #define trigPin1 A0
 #define echoPin1 A2
 #define trigPin2 A1
 #define echoPin2 A4 
 
AF_DCMotor motor1(1,MOTOR12_64KHZ); // set up motors.
AF_DCMotor motor2(2, MOTOR12_8KHZ);
 
void setup() {
  Serial.begin(9600); // begin serial communication  
  Serial.println("Motor test!");
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
pinMode(trigPin1, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin2, INPUT);
  
  motor1.setSpeed(105); //set the speed of the motors, between 0-255
  motor2.setSpeed (130);  
}

void moveStraight() {
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  }

 void turn() {
  Serial.print ("Reorienting");
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  delay(450);
  }

void loop() {

  long duration, duration1, duration2, distance, distance1, distance2; // start the scan
  
  digitalWrite(trigPin, LOW);  
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);
  digitalWrite(trigPin1, HIGH);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(5); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;// convert the distance to centimeters.
  duration1 = pulseIn(echoPin1, HIGH);
  distance1 = (duration1/2) / 29.1;
  duration2 = pulseIn(echoPin2, HIGH);
  distance2 = (duration2/2) / 29.1;
  
 if (distance <= 15 && distance1 <= 15 && distance2 <= 15  )/*if there's an obstacle 25 centimers, ahead, do the following: */ {   
  Serial.print(duration);
  Serial.println ("Close Obstacle detected!" );
  Serial.println ("Obstacle Details:");
  Serial.print ("Distance From Robot is " );
  Serial.print ( distance);
  Serial.print ( " CM!");// print out the distance in centimeters.

  Serial.println (" \n ");
  turn();
}
  else {
   moveStraight();
}
}
