#include <AFMotor.h> //import your motor shield library
#define trigPin A5// define the pins of your sensor
#define echoPin A3

 
AF_DCMotor motor1(1,MOTOR12_64KHZ); // set up motors.
AF_DCMotor motor2(2, MOTOR12_8KHZ);
 
void setup() {
  Serial.begin(9600); // begin serial communication  
  Serial.println("Motor test!");
  pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
  
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
  delayMicroseconds(2); // delays are required for a succesful sensor operation.
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(5); //this delay is required as well!
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;// convert the distance to centimeters.
 
 if (distance <= 15)/*if there's an obstacle 25 centimers, ahead, do the following: */ {   
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
