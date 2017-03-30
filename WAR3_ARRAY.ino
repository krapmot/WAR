#include <AFMotor.h>

int ultraSoundSignalPins[] = {5,3,1,2,4,0}; // Front Left,Front, Front Right, Rear Ultrasound signal pins
char *pingString[] = {"Front Left ","Front ", "Front Right ", "Rear "}; // just something to print to indicate direction

void setup()
{
 Serial.begin(9600);
}

//Ping function
unsigned long ping(int indexEcho, int indexTrig)
{
  /*
   * pinMode(trigPin, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin, INPUT);// set the echo pin to input (recieve sound waves)
  pinMode(trigPin1, OUTPUT);// set the trig pin to output (Send sound waves)
  pinMode(echoPin1, INPUT);
   */
 unsigned long echo;

 pinMode(index, OUTPUT); // Switch signalpin to output
 digitalWrite(index, LOW); // Send low pulse
 delayMicroseconds(2); // Wait for 2 microseconds
 digitalWrite(index, HIGH); // Send high pulse
 delayMicroseconds(5); // Wait for 5 microseconds
 digitalWrite(index, LOW); // Holdoff
 pinMode(index, INPUT); // Switch signalpin to input
 digitalWrite(index, HIGH); // Turn on pullup resistor
 echo = pulseIn(index, HIGH); //Listen for echo
 return (echo / 58.138) * .39; //convert to CM then to inches
}

void loop()
{
 unsigned long ultrasoundValue;
 for(int i=0; i < 4; i++){
   ultrasoundValue = ping(ultraSoundSignalPins[i], ultrasoundSignalPins[i+1]); 
   Serial.print(pingString[i]);
   Serial.print(ultrasoundValue);
   Serial.print("in, ");    
   delay(50);

 }
 Serial.println();
 delay(50); 
}
