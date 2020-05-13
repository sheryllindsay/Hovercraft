/* Assembly and code to control an Hovercraft
Designed for Summer Program 2018
@ICAM Paris Campus 2018
*/
// include the servo library
#include <Servo.h>
Servo myServo;  // create a servo object

int const potPin = A0; // analog pin used to connect the potentiometer
int potVal=2;  // variable to read the value from the analog pin
int angle;   // variable to hold the angle for the servo motor

// named constants for the switch and motor pins
//const int switchPin = 2; // the number of the switch pin
//const int motorPin = 10; // the number of the motor pin

//int switchState = 0;  // variable for reading the switch's status

void setup() {

//Servo  
  myServo.attach(9); // attaches the servo on pin 9 to the servo object
  myServo.write(90); // Initializing the servo position
  
//Motor  
  // identify the INPUTs and OUTPUTs:
  //pinMode(motorPin,OUTPUT);
  //pinMode(switchPin,INPUT);
 pinMode(potPin,INPUT);

//Serial connection  
 Serial.begin(9600); // open a serial connection to your computer

}

void loop() {
  
//Mapping the angle of the servo using the value of the potentiometer  
  potVal = analogRead(potPin); // read the value of the potentiometer
 //  print out the value to the serial monitor
 Serial.print("Message to write the value of the potentiometer");
  Serial.print(potVal);

  // scale the numbers from the potentiometer
 angle = map(potVal, 0, 1023, 0, 180);

  // print out the angle for the servo motor
 Serial.print("Message to write the angle you want the servo to move");
 Serial.println(angle);

  // set the servo position
 myServo.write(angle);

  
// Controlling the motors using the state of the switch  
    // read the state of the switch value:
 // switchState = digitalRead(switchPin);

  // check if the switch is pressed.
  //if (switchState == 1) {
    // turn motor on:
    //digitalWrite(motorPin,1);
  //} else {
    // turn motor off:
    //    digitalWrite(motorPin,0);

  //}

  // wait for the servo to get there
 delay(15);
}


