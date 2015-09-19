/*
  Push Button Monitor
  Monitors a momentary push button and 
  detects when it was pushed.

  Daniel Porrey
  Snap Circuits IoT - Project 2
  https://www.hackster.io/porrey/snapcircuits-prj2
  
*/

// ***
// *** Specifies the pin on which the LED is connected.
// ***
#define BUTTON_PIN 7

// ***
// *** Specifies the amount of time (in milliseconds)
// *** to mpause between readings.
// ***
#define DEBOUNCE_TIME 50

int _previousValue = 0;

// ***
// *** The setup function runs once when you press
// *** reset or power the board.
// ***
void setup() 
{
  // ***
  // *** Display the pin number
  // ***
  Serial.begin(115200);
  Serial.print("Monitoring push button on pin ");
  Serial.println(BUTTON_PIN);
 
  // ***
  // *** Initialize the digital pin for input.
  // ***
  pinMode(BUTTON_PIN, INPUT);
  
  // ***
  // *** Get the current value of the pin
  // ***
  _previousValue = digitalRead(BUTTON_PIN);
}

// ***
// *** The loop function runs over 
// *** and over again forever.
// ***
void loop()
{
  // ***
  // *** Read the current value from the pin
  // ***
  int currentValue = digitalRead(BUTTON_PIN);
  
  // ***
  // *** Display a message if the button state
  // *** has cvhanged.
  // ***
  if (_previousValue != currentValue)
  {
    if (currentValue == HIGH)
    {
      // ***
      // *** The button is down
      // ***
      Serial.println("The button was pushed");
    }
    else
    {
      // ***
      // *** The button is up
      // ***
      Serial.println("The button was released");
    }
    
    // ***
    // *** Store the new button state
    // ***
    _previousValue = currentValue;
  }
    
  // ***
  // *** Pause for something called "debounce". This prevents
  // *** the switch from firing multiple events while it is 
  // *** going down or while going up.
  // ***
  delay(DEBOUNCE_TIME);
}
