#include <Arduino.h>
#include "ServoEasing.hpp"

/**
 * Experimental code for testing smooth head scanning for head 
 * with attached HC-SR04 type ulrasonic send/receive ping unit 
 * for calculating the distance of objects in front of the robot 
 * to avoid. This sketch doesn't use any code to interface with 
 * the ultrasonic module.
 */


ServoEasing scanner; // Use ServoEasing object

// MG90S Mini-servo (5 volt).
#define Head_Scanner 9

// The mini-servo doesn't center at 90. The variance is 8. 
int Variance      = 8; 
int Servo_Center  = 90 + Variance;
int Scan_Left     = 135 + Variance; 
int Scan_Right    = 45 + Variance;
int Scan_Delay    = 1000;

void setup() {
  // put your setup code here, to run once:

  // Attach and center head servo.
  scanner.attach(Head_Scanner);
  scanner.setSpeed(75); // Set speed (adjust as needed)
  scanner.easeTo(Servo_Center);

}

void loop() {
  // put your main code here, to run repeatedly:

  delay(Scan_Delay);

  //Scan area
  scanner.easeTo(Scan_Left);
  delay(Scan_Delay/2);
  // Add routine to check distance Left. 

  scanner.easeTo(Servo_Center);
  delay(Scan_Delay);
  // Add routine to check distance in front.

  scanner.easeTo(Scan_Right);
  delay(Scan_Delay/2);
  // Add routine to check distance Right. 

  scanner.easeTo(Servo_Center);
                                                                
}
