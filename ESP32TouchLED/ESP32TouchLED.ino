// ESP32 Touch LED Example Code
// By Kreezy(KRosa) 1.28.2018

// Connect a male to male jumper to Pin D4 for touch sensing


int pinValue = 0;     // Variable to store the touch value
int ledPin = 2;       // Onboard LED on Pin 2
int sendPin = 5;      // Connect LED (or anything you please) to Pin 5 
int switchState = 0;  // Variable to store the switch state for our switch case code

void setup()
{
  Serial.begin(115200);         // starts serial monitor 
  pinMode(ledPin, OUTPUT);      // declaring our pins as outputs
  pinMode(sendPin, OUTPUT);
  
}

void loop()
{
  Serial.println(touchRead(T0));  // prints the touch value (T0 = Touch 0 = Pin D4)
  
  pinValue = touchRead(T0);       // we store that value to pinValue variable 

  if (pinValue < 50) {            // if the value is less than 50
  switchState = 1;                // we set switchState to 1
  } else {
  switchState = 0;                // if the value is over 50
  }                               // we set switchState to 0

  switch (switchState) {          // this is our switch case

    case 0:                         // if switchState is 0 both pins or OFF
      digitalWrite(ledPin, LOW);
      digitalWrite(sendPin, LOW);
      break;
    case 1:                         // if switchState is 1 than both pins are ON
      digitalWrite(ledPin, HIGH);
      digitalWrite(sendPin, HIGH);
      break;  
  } 
  
}  // The END :} Kreezy..

