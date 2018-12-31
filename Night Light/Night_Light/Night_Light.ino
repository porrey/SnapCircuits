/*
  Night Light
  Measure the amount of light using a photoresistor and
  tuns the night light on when it is dark and off when
  thee is enough natural light detected.

  Daniel Porrey
  Snap Circuits - Night Light
  https://www.hackster.io/porrey/sc-nightlight
  
*/

// ***
// *** Specifies the pin on which the relay is connected.
// ***
#define RELAY_PIN 13

// ***
// *** The lower threshold value used to turn the light on.
// *** When the ADC vaue falls below this value the light
// *** is turned on.
// ***
#define ADC_THRESHOLD 10

// ***
// *** Specifies the pin on which the voltage is read.
// ***
int _analogPin = A0;

// ***
// *** Stores the last state of the relay pin
// ***
int _lastState = LOW;

// ***
// *** The setup function runs once when you press
// *** reset or power the board.
// ***
void setup()
{
  // ***
  // *** Setup the serial device
  // ***
  Serial.begin(115200);
  Serial.print("Monitoring light on pin ");
  Serial.print(A0);
  Serial.println();

  // ***
  // *** Set the relay pin up for output
  // ***
  pinMode(RELAY_PIN, OUTPUT);
}

// ***
// *** The loop function runs over 
// *** and over again forever.
// ***
void loop()
{
  // ***
  // *** Read the value of the ADC.
  // ***
  int adc = analogRead(_analogPin);

  // ***
  // *** Check if the value is above our threshold. Above the
  // *** threshold means we have enough natural light and
  // *** should turn he night light off.
  // ***
  if (adc <= ADC_THRESHOLD)
  {
    // ***
    // *** Shut the light off
    // ***
    TurnLightOn();
  }
  else
  { 
    // ***
    // *** Turn the light on
    // ***
    TurnLightOff();
  }
  
  // ***
  // *** Delay before taking the next reading.
  // ***
  delay(300);
}

// ***
// *** Turns the light on
// ***
void TurnLightOn()
{
  // ***
  // *** Check if the light is already on
  // ***
  if (_lastState != HIGH)
  {
    // ***
    // *** Write the event to the Serial device
    // ***
    Serial.println("Turned light on.");
    
    // ***
    // *** Set the RELAY_PIN to HIGH
    // ***
    digitalWrite(RELAY_PIN, HIGH);
    
    // ***
    // *** Save the last state
    // ***
    _lastState = HIGH;
  }
}

// ***
// *** Turns the light off
// ***
void TurnLightOff()
{
  // ***
  // *** Check if the light is already off
  // ***
  if (_lastState != LOW)
  {
    // ***
    // *** Write the event to the Serial device
    // ***
    Serial.println("Turned light off.");
    
    // ***
    // *** Set the RELAY_PIN to LOW
    // ***
    digitalWrite(RELAY_PIN, LOW);
    
    // ***
    // *** Save the last state
    // ***
    _lastState = LOW;
  }
}
