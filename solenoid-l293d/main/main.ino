// Tutorial:
// https://lastminuteengineers.com/l293d-motor-driver-shield-arduino-tutorial/
// This is an implementation using a solenoid + L293D
#include <AFMotor.h>

AF_DCMotor motor(4);
AF_DCMotor inSolenoid(2); // In solenoid
AF_DCMotor outSolenoid(3); // Out solenoid

void setup() 
{
  //Set initial speed of the motor & stop
  motor.setSpeed(200);
  motor.run(RELEASE);
  
  inSolenoid.setSpeed(255);
  outSolenoid.setSpeed(255);
}

void loop() 
{
  uint8_t i;

  // Turn on motor
  motor.run(FORWARD);
  
  inSolenoid.run(FORWARD);
  delay(1000);

  inSolenoid.run(RELEASE);
  outSolenoid.run(FORWARD);
  // Now change motor direction
  motor.run(BACKWARD);
  
  // Accelerate from zero to maximum speed
  delay(1000);

  // Now turn off motor
  motor.run(RELEASE);
  outSolenoid.run(RELEASE);

  delay(1000);
}
