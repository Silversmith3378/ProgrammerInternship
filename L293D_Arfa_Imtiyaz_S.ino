/* code by Arfa Imtiyaz Surapati 
NIM: 21/480658/TK/53036 */

const int mpin1 = 5;  //declaring 1st pin of the L293D (cw rotation)
const int mpin2 = 6;  //declaring 2nd pin of the L293D (ccw rotation)
int speed = 0;      //setting up speed integer for speed adjusting purposes

void setup()      //code inside here will run once
{
  pinMode(mpin1, OUTPUT);//set 1st pin as output
  pinMode(mpin2, OUTPUT);//set 2nd pin as output
  Serial.begin(9600);  //start Serial function for speed input
  Serial.setTimeout(50); //set the serial timeout to 50ms for faster parseInt reading
}

void loop()        //code inside here will run indefinitely
{
  if(Serial.available()) {//checking if there's any input from the user
    speed=Serial.parseInt();//put the inputted value into the integer speed
    if(speed>=0) {      //check if the inputted speed is greater than or equal to 0
      digitalWrite(mpin2, LOW);//set the 2nd pin to low to clear any previous usage
      analogWrite(mpin1,speed);//set the 1st pin to the speed value (determined by the input earlier)
    }
    else {          //check if the value is less than 0
      digitalWrite(mpin1, LOW);//set the 1st pin to low to clear any previous usage
      analogWrite(mpin2,-speed);//set the 2nd pin to the speed value (determined by the input earlier)
    }
  }
}
