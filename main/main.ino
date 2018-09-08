int E1 = 10;
int M1 = 12;
int E2 = 11;
int M2 = 13;

int durationInSeconds = 300;

void setup()
{
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}

void loop()
{
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 255);
  analogWrite(E2, 255);

  delay(durationInSeconds * 1000);

  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  analogWrite(E1, 255);
  analogWrite(E2, 255);

  delay(durationInSeconds * 1000);

  analogWrite(E1, 0);
  analogWrite(E2, 0);

  // Wait one day
  delay(86400 * 1000);
  
}
