const int verde = 9;
const int azul = 10;
const int vermelho = 11;
void setup()
{
  pinMode(azul, OUTPUT);
   pinMode(verde, OUTPUT);
   pinMode(vermelho, OUTPUT);

}

void loop()
{
  digitalWrite(azul, LOW);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, HIGH);

  delay(1000); // Wait for 1000 millisecond(s)
  
  digitalWrite(azul, HIGH);
  digitalWrite(verde, LOW);
  digitalWrite(vermelho, LOW);

  delay(1000); // Wait for 1000 millisecond(s)

  digitalWrite(azul, LOW);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, LOW);
  
  delay(1000); // Wait for 1000 millisecond(s)

  analogWrite(azul, 0);
  analogWrite(verde, 50);
  analogWrite(vermelho, 255);

  delay(1000); // Wait for 1000 millisecond(s)
  
  analogWrite(azul, 207);
  analogWrite(verde, 0);
  analogWrite(vermelho, 255);
 
  delay(1000); // Wait for 1000 millisecond(s)

  digitalWrite(azul, HIGH);
  digitalWrite(verde, HIGH);
  digitalWrite(vermelho, HIGH);
      
  delay(1000); // Wait for 1000 millisecond(s)
}