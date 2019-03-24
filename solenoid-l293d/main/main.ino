// Tutorial:
// https://lastminuteengineers.com/l293d-motor-driver-shield-arduino-tutorial/
// This is an implementation using a solenoid + L293D
#include <AFMotor.h>

AF_DCMotor motor(4);
AF_DCMotor inSolenoid(3); // In solenoid
AF_DCMotor outSolenoid(2); // Out solenoid

long STEP_TIME = 1000L * 60 * 5;
long DAY_TIME = 1000L * 60 * 60 * 24;
long DAY_TIME_WITH_OFFSET = DAY_TIME - (STEP_TIME * 2);

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
  inSolenoid.run(FORWARD);
  // Turn on motor
  motor.run(BACKWARD);
  
  delay(STEP_TIME);

  inSolenoid.run(RELEASE);
  
  outSolenoid.run(FORWARD);
  // Now change motor direction
  motor.run(FORWARD);
  
  delay(STEP_TIME);

  // Now turn off motor
  motor.run(RELEASE);
  outSolenoid.run(RELEASE);

  delay(DAY_TIME_WITH_OFFSET);
}
