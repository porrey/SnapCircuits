/*
  Button Controlled Launcher
  Using the Arduino, monitor a button, that when pressed, will launch the fan.

  Daniel Porrey
  https://www.hackster.io/snapcircuits

*/

// ***
// *** Specifies the pin on which each device is connected.
// ***
#define RELAY_PIN 2
#define BUTTON_PIN 3

// ***
// *** Used to track when the button was pressed.
// ***
bool _buttonPressed = false;

// ***
// *** The setup function runs once when you press
// *** reset or power the board.
// ***
void setup()
{
  // ***
  // *** Initialize the serial port to see messages
  // ***
  Serial.begin(115200);

  // ***
  // *** To control the relay, set the RELAY_PIN
  // *** up for output.
  // ***
  Serial.println("Initializing relay pin.");
  pinMode(RELAY_PIN, OUTPUT);

  // ***
  // *** To monitor the button, set the BUTTON_PIN
  // *** up for input.
  // ***
  Serial.println("Initializing button pin.");
  pinMode(BUTTON_PIN, INPUT);

  Serial.println("Resetting circuit board.");

  // ***
  // *** Ensure the relay is off (LOW)
  // ***
  digitalWrite(RELAY_PIN, LOW);

  Serial.println("Ready.");
}

// ***
// *** The loop function runs over
// *** and over again forever.
// ***
void loop()
{
  int value = digitalRead(BUTTON_PIN);

  // ***
  // *** Check if the button is up (LOW) or down (HIGH)
  // ***
  if (!_buttonPressed &&  value == HIGH)
  {
    _buttonPressed = true;
    Serial.println("Button was pressed.");

    // ***
    // *** Turn the motor on by enabling the relay
    // ***
    Serial.println("Turning motor on.");
    digitalWrite(RELAY_PIN, HIGH);
  }
  else if (_buttonPressed &&  value == LOW)
  {
    _buttonPressed = false;

    Serial.println("Button was released.");

    // ***
    // *** Turn the motor on by enabling the relay
    // ***
    Serial.println("Turning motor off.");
    digitalWrite(RELAY_PIN, LOW);
  }

  // ***
  // *** Very short delay
  // ***
  delay(5);
}
