/*
  Measuring Light
  Measure the amount of light using a photoresistor.

  Daniel Porrey
  Snap Circuits - Measuring Light
  https://www.hackster.io/porrey/sc-measuringlight
  
*/

// ***
// *** The Arduino Uno ADC's is a 10-bit ADC. The
// *** maximum value is 1023 (there are 1024 possible 
// *** values ranging from 0 to 1024).
// ***
#define MAX_ADC 1023.

// ***
// *** This is the value of resistor 1 (R1) in
// *** the voltage divider circuit. Uncomment
// *** the appropriate resistor value
// ***
#define R2 100.               // *** Snap Circuits R1 (100 Ohm)
//#define R2 1 * 1000.        // *** Snap Circuits R2 (1K Ohm)
//#define R2 5.1 * 1000.      // *** Snap Circuits R3 (5.1K Ohm)
//#define R2 10 * 1000.       // *** Snap Circuits R4 (10K Ohm)
//#define R2 100 * 1000.      // *** Snap Circuits R5 (100K Ohm)

// ***
// *** The input voltage to the voltage
// *** divider circuit.
// ***
#define VIN 5.0

// ***
// *** Define a value for infinity.
// ***
#define INFINITY 1. / 0.

// ***
// *** Specifies the pin on which the voltage is read.
// ***
int _analogPin = A0;

// ***
// *** The calculated value of R1 in the voltage 
// *** divider circuit.
// ***
float _r1;

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
  Serial.print("Reading light value from pin ");
  Serial.print(A0);
  Serial.println();
  
  // ***
  // *** Initialize _r1
  // ***
  int adc = analogRead(_analogPin);
  float vout = CalculateVout(VIN, adc);
  _r1 = CalculateR1(R2, VIN, vout);
  
  // ***
  // *** Display the values
  // ***
  DisplayValues(_r1, vout, adc);
  
  //pinMode(3, OUTPUT);
}

// ***
// *** The loop function runs over 
// *** and over again forever.
// ***
void loop()
{
  // ***
  // *** Determine the value of the resistor R1
  // *** in the voltage divider circuit. R1 is the
  // *** photoresistor.
  // ***
  int adc = analogRead(_analogPin);
  float vout = CalculateVout(VIN, adc);
  float resistance = CalculateR1(R2, VIN, vout);

  // ***
  // *** Check if the value has changed since the last reading.
  // ***
  if (resistance != _r1)
  {
    // ***
    // *** Update the stored value
    // ***
    _r1 = resistance;
    
    // ***
    // *** Display the values
    // ***
    DisplayValues(_r1, vout, adc);
  }
  
  // ***
  // *** Delay before taking the next reading.
  // ***
  delay(500);
}

// ***
// ***
// ***
void DisplayValues(float resistance, float vout, int adc)
{
    // ***
    // *** Check for Infinity
    // ***
    if (resistance == INFINITY)
    {
      // ***
      // *** Display Infinity.
      // ***
      Serial.print("Infinite");
    }
    else
    {      
      // ***
      // *** Display the new value.
      // ***
      if (resistance > 1000000)
      {
        // ***
        // *** M means "times one million"
        // ***
        Serial.print(resistance / 1000.);
        Serial.print("M ");
      }
      else if (resistance > 1000)
      {
        // ***
        // *** K means "times onen thousand"
        // ***
        Serial.print(resistance / 1000.);
        Serial.print("K ");
      }
      else
      {
        Serial.print(resistance);  
      }
      
      Serial.print(" Ohms");
    }
    
    Serial.print(", Vout = ");
    Serial.print(vout);
    Serial.print(" V, ADC = ");
    Serial.print(adc);
    Serial.print(" of ");
    Serial.println(MAX_ADC);
}

// ***
// *** Determines the resistor value R1 in the volatge
// *** divider circuit with the given value of R2 and 
// *** the circuit volatge Vin. R2 is the resistor
// *** between Vin and Vout.
// ***
// *** vin:  Value of Vin
// *** adc:  Value of adc reading
// ***
float CalculateVout(float vin, int adc)
{
  // ***
  // *** The reading from the ADC can be converted to a volatge
  // *** by taking the ADC value and dividing it by the maximum
  // *** ADC value and then multiplying that by the maximum voltage.
  // ***
  return (adc / MAX_ADC) * vin;   
}

// ***
// *** Determines the resistor value R1 in the volatge
// *** divider circuit with the given value of R2 and 
// *** the circuit volatge Vin. R2 is the resistor
// *** between Vin and Vout.
// ***
// *** r2:   Value of R2
// *** vin:  Value of Vin
// *** vout: Value of Vout
// ***
float CalculateR1(float r2, float vin, float vout)
{  
  return r2 * (( vin / vout) - 1);
}

