// Non solenoid automatic Arduino UNO water changer
// Uses check-valve
// L298P Motor driver
int E1 = 10;
int M1 = 12;
int E2 = 11;
int M2 = 13;

long durationInSeconds = 600;

long durationInMilliseconds = durationInSeconds * 1000;
long dayInMilliseconds = 86400 * 1000;
long dayInMillisecondsOffsetted = dayInMilliseconds - (durationInMilliseconds * 2);

void setup()
{
  Serial.begin(9600);
  Serial.println("Starting...");
  
  pinMode(M1, OUTPUT);
  pinMode(M2, OUTPUT);
}

void loop()
{
  Serial.println("Running motor forwards...");
  digitalWrite(M1, HIGH);
  digitalWrite(M2, HIGH);
  analogWrite(E1, 255);
  analogWrite(E2, 255);

  Serial.print("Delaying for (ms): ");
  Serial.println(durationInMilliseconds);

  delay(durationInMilliseconds);

  Serial.println("Running motor backwards...");
  digitalWrite(M1, LOW);
  digitalWrite(M2, LOW);
  analogWrite(E1, 255);
  analogWrite(E2, 255);

  delay(durationInMilliseconds);

  Serial.println("Stopping motor...");
  analogWrite(E1, 0);
  analogWrite(E2, 0);

  Serial.print("Wait for one day with offset (ms): ");
  Serial.println(dayInMillisecondsOffsetted);
  delay(dayInMillisecondsOffsetted);
  
}
