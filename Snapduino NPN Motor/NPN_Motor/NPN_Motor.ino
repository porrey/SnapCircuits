#define MOTOR_PIN PB2

void setup() 
{
  pinMode(MOTOR_PIN, OUTPUT);
}

void loop() 
{
  // ***
  // *** Motor On
  // ***
  digitalWrite(MOTOR_PIN, HIGH);
  delay(3000);

  // ***
  // *** Motor On
  // ***
  digitalWrite(MOTOR_PIN, LOW);
  delay(3000);
}
