/*code by Arfa Imtiyaz S
  NIM: 21/480658/TK/53036*/

bool led = false;  //boolean for blinking led
bool on = true;   //boolean for enabling/disabling blink
const int ledpin = 13;  //declaring led's pin
const int btnpin = 2;   //declaring button's pin

void setup()  //code inside here will run once
{
  pinMode(ledpin, OUTPUT);  //setting the led pin mode to output
  pinMode(btnpin, INPUT_PULLUP);  //setting the button pin mode to input, and using internal pull up resistor

  // initialize Timer1
  noInterrupts(); // disable all interrupts
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;

  OCR1A = 31250; // compare match register (16MHz/256)/2Hz
  TCCR1B |= (1 << WGM12); // CTC mode
  TCCR1B |= (1 << CS12); // use 256 prescaler
  TIMSK1 |= (1 << OCIE1A); // enable timer compare interrupt
  interrupts(); // enable all interrupts

  attachInterrupt(digitalPinToInterrupt(btnpin), disableLed, FALLING);  //call the function disableLed when the button is pressed
}

void loop()
{

}

void disableLed() { //this function will be called on button press interrupt
  on = false; //disable the blinking led
  digitalWrite(ledpin, LOW); //turning the led off
}

ISR (TIMER1_COMPA_vect) {
  if (on) { //check if blinking is enabled
    led = !led; //toggle led boolean
    digitalWrite(ledpin, led); //set led on/off depending on boolean
  }
}
