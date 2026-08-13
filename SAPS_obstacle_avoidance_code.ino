#include <Servo.h>
const int LeftMotorForward = 6;
const int LeftMotorBackward = 7;
const int RightMotorForward = 5;
const int RightMotorBackward = 4;
const int enA = 8;
const int enB = 3;
const int trigPin = 12;
const int echoPin = 11;

Servo servo_motor;
boolean goesForward = false;
int distance = 100;

void setup()
{
  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  servo_motor.attach(9); // Servo pin
  Serial.begin(9600);

  moveStop();
  delay(1000);
  servo_motor.write(115);
  delay(1000);

  int centerDistance = readPing(); // Check front
  delay(100);
  int distanceLeft = lookLeft(); // Check left
  delay(100);
  int distanceRight = lookRight(); // Check right
  delay(100);

  Serial.print("Center: ");
  Serial.print(centerDistance);
  Serial.print(" cm | Left: ");
  Serial.print(distanceLeft);
  Serial.print(" cm | Right: ");
  Serial.print(distanceRight);
  Serial.println(" cm");

  if (centerDistance <= 15) {
    moveStop();
    delay(1000);

    if (distanceLeft < 15 && distanceRight >= 15) {
      Serial.println("Obstacle Left - Turning Right");
      turnRight();

    } else if (distanceRight < 15 && distanceLeft >= 15) {
      Serial.println("Obstacle Right - Turning Left");
      turnLeft();

    } else if (distanceRight < 15 && distanceLeft < 15) {
      Serial.println("Obstacles on both sides - Moving Backward");
      moveBackward();
      delay(500);

    } else {
      Serial.println("Obstacle Ahead - Turning Left by Default");
      turnLeft();
    }

    moveStop();
    delay(300);

  } else {
    moveForward();
  }

  delay(100);
}

int readPing() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);
  int cm = duration * 0.034 / 2;

  if (cm == 0)
    cm = 250;

  return cm;
}
