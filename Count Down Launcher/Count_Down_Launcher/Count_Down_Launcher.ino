/*
  Count Down Launcher
  Using the Arduino, monitor a button, that when pressed, will count down 3 
  seconds by flashing the red LED and launch the disc. The green LED will 
  turn on when the disc is launched.

  Daniel Porrey
  https://www.hackster.io/snapcircuits

*/

// ***
// *** Specifies the pin on which each device is connected.
// ***
#define RELAY_PIN 2
#define BUTTON_PIN 3
#define RED_LED_PIN 4
#define GREEN_LED_PIN 5

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

  // ***
  // *** To control the LED's, set the LED_n_PIN
  // *** up for output.
  // ***
  Serial.println("Initializing LED 1 pin.");
  pinMode(RED_LED_PIN, OUTPUT);
  Serial.println("Initializing LED 2 pin.");
  pinMode(GREEN_LED_PIN, OUTPUT);

  Serial.println("Resetting circuit board.");

  // ***
  // *** Ensure the relay is off (LOW)
  // ***
  digitalWrite(RELAY_PIN, LOW);

  // ***
  // *** Ensure the LED's are off (HIGH)
  // ***
  digitalWrite(RED_LED_PIN, HIGH);
  digitalWrite(GREEN_LED_PIN, HIGH);

  Serial.println("Ready.");
}

// ***
// *** The loop function runs over
// *** and over again forever.
// ***
void loop()
{
  // ***
  // *** Check if the button is up (LOW) or down (HIGH)
  // ***
  if (digitalRead(BUTTON_PIN) == HIGH)
  {
    Serial.println("Button was pressed.");

    // ***
    // *** Turn the motor on by enabling the relay
    // ***
    Serial.println("Turning motor on.");
    digitalWrite(RELAY_PIN, HIGH);

    // ***
    // *** Flash the red LED 3 times by calling the
    // *** flashRedLed() function.
    // ***
    flashRedLed();
    flashRedLed();
    flashRedLed();

    // ***
    // *** Wait 1 second and turn the
    // *** green LED on.
    // ***
    Serial.println("Turning green LED on.");
    digitalWrite(GREEN_LED_PIN, LOW);
  
    // ***
    // *** Launch the disc by turning
    // *** the motor off.
    // ***
    Serial.println("Launch!");
    digitalWrite(RELAY_PIN, LOW);

    // ***
    // *** Wait 1 second and turn the
    // *** green LED off.
    // ***
    delay(1000);
    Serial.println("Turning green LED off.");
    digitalWrite(GREEN_LED_PIN, HIGH);
  }

  // ***
  // *** Very short delay
  // ***
  delay(5);
}

// ***
// *** This function will turn the red LED
// *** on, wait 1/2 second and then turn it off.
// ***
void flashRedLed()
{
  // ***
  // *** Turn the red LED on.
  // ***
  Serial.println("Turning red LED on.");
  digitalWrite(RED_LED_PIN, LOW);

  // ***
  // *** Wait 1/2 second
  // ***
  delay(500);

  // ***
  // *** Turn the red LED off.
  // ***
  Serial.println("Turning red LED off.");
  digitalWrite(RED_LED_PIN, HIGH);

  // ***
  // *** Wait 1/2 second
  // ***
  delay(500);
}

