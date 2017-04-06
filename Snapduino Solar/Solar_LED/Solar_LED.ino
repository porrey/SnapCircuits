#define LED_PIN PB4

void setup() 
{
  pinMode(LED_PIN, OUTPUT);
}

void loop() 
{
  // ***
  // *** LED on
  // ***
  digitalWrite(LED_PIN, HIGH);
  delay(1000);

  // ***
  // *** LED off
  // ***
  digitalWrite(LED_PIN, LOW);
  delay(1000);
}
