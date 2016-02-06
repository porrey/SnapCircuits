/*
  Light Controlled Launcher
  Using the Arduino, launch the fan when light is detected.

  Daniel Porrey
  https://www.hackster.io/snapcircuits
  
*/

// ***
// *** Specifies the pin on which each device is connected.
// ***
#define RELAY_PIN 2
#define RP_PIN 3

// ***
// *** Used to track when the button was pressed.
// ***
bool _lightDetected = false;

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
  // *** To monitor the photo resistor, set the RP_PIN
  // *** up for input.
  // ***
  Serial.println("Initializing photo resistor pin.");
  pinMode(RP_PIN, INPUT);

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
  int value = digitalRead(RP_PIN);

  // ***
  // *** Check if the button is up (LOW) or down (HIGH)
  // ***
  if (!_lightDetected &&  value == HIGH)
  {
    _lightDetected = true;
    Serial.println("Light detected.");

    // ***
    // *** Turn the motor on by enabling the relay
    // ***
    Serial.println("Turning motor on.");
    digitalWrite(RELAY_PIN, HIGH);
  }
  else if (_lightDetected &&  value == LOW)
  {
    _lightDetected = false;

    Serial.println("Light NOT detected.");

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
