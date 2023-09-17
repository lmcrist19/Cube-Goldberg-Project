#include <Servo.h>

/*
  Author: Lauren Crist
  Project: Cube Goldberg Project 2019
  Date: 3/14/19
  Description: This Arduino code controls various components of a Rube Goldberg machine, including a servo, sensors, and LEDs, to release a marble and trigger a photocell-based mechanism.
*/

Servo marbleRelease;
int marbleCatch = 2;
int carBumper = 3;
int carPulley = 4;
int L1 = 5;
int L2 = 6;
int laser = 7;
int photocell = A0;

int flag = 3;
int photocellReading = 0;

void setup() {
  Serial.begin(9600);
  
  // Set pin modes for various components
  pinMode(marbleCatch, INPUT);
  pinMode(carBumper, INPUT);
  pinMode(laser, OUTPUT);
  pinMode(carPulley, OUTPUT);
  pinMode(L1, OUTPUT);
  pinMode(L2, OUTPUT);
  
  // Initialize the initial states of components
  digitalWrite(carPulley, LOW);
  digitalWrite(L1, HIGH);
  digitalWrite(L2, LOW);
  
  // Attach the servo and set it to the initial position
  marbleRelease.attach(9);
  marbleRelease.write(0);
}

void loop() {
  // Read the state of the marble catch and car bumper
  int marbleCaught = digitalRead(marbleCatch);
  int carPulled = digitalRead(carBumper);
  
  // Read the analog value from the photocell
  int photocellReading = analogRead(photocell);
  
  // Print sensor values to Serial Monitor for debugging
  Serial.print("marble: ");
  Serial.println(marbleCaught);
  Serial.print("car: ");
  Serial.println(carPulled);
  Serial.print("photo: ");
  Serial.println(photocellReading);
  
  // Turn off the laser
  digitalWrite(laser, LOW);
  
  // Control the car pulley and laser based on sensor readings and flags
  if (marbleCaught == HIGH) {
    flag = 1;
  }
  if (carPulled == HIGH) {
    flag = 0;
  }
  if (flag == 1) {
    digitalWrite(carPulley, HIGH);
  } else if (flag == 0) {
    digitalWrite(carPulley, LOW);
    digitalWrite(laser, HIGH);
    Serial.println(photocellReading);
  }
  
  // Trigger the mechanism when the photocell reading exceeds a threshold
  if (photocellReading > 800) {
    Serial.println("triggered");
    digitalWrite(laser, LOW);
    marbleRelease.write(90);
  }
}
