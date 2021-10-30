/*Arfa Imtiyaz Surapati
NIM: 21/480658/TK/53036 */

#include <Servo.h>          //include servo library for servo controlling
Servo servo;            //setting up the servo
const int trigPin = 5;        //declaring trig pin of the ultrasonic sensor
const int echoPin = 6;        //declaring echo pin of the ultrasonic sensor
long dist;              //distance variable for saving the distance value
long duration;            //duration variable for calculating the distance
int rot = 0;            //rotation variable for saving the servo rotation value
 
void setup() {            //the code here will run once
  servo.attach(7);          //set the servo pin to 7
  pinMode(trigPin, OUTPUT);     //set the trig pin mode to output
  pinMode(echoPin, INPUT);      //set the echo pin mode to input
}
 
void loop() {           //the code here will run indefinitely
  checkDist();            //calling the checkDist function for checking the distance
  rot = map(dist, 30, 310, 45, 135);//converting the distance value to rotation value
  servo.write(rot);         //rotating the servo to the converted value
}
 
void checkDist(){         //a function for distance checking/calculating
  digitalWrite(trigPin, LOW);   //setting the trig pin to low
  delayMicroseconds(2);       //2 microseconds delay
  digitalWrite(trigPin, HIGH);    //setting the trig pin to high
  delayMicroseconds(10);      //10 microseconds delay
  digitalWrite(trigPin, LOW);   //setting the trig pin back to low
  duration = pulseIn(echoPin, HIGH);//waiting for the sound to bounce back and got detected by the echo pin
  dist = duration*0.034/2;      //inserting the delay time to sound speed to distance conversion formula
  }
