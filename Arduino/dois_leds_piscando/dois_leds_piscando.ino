void setup()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
}

void loop()
{
  digitalWrite(2, HIGH);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(2, LOW);
  delay(100); // Wait for 1000 millisecond(s)
  
  digitalWrite(4, HIGH);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(4, LOW);
  delay(100); // Wait for 1000 millisecond(s)
}
