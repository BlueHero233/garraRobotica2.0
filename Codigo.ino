//#include <PS2X_lib.h>
//PS2X ps2x;
//int error = 0;
//byte type = 0;
#include <AccelStepper.h>
#include <Servo.h>
#define xStep 2   //step, pinMode = OUTPUT, HIGH for 1 step = 1.8°, LOW to disable, must be written in a for loop in order to create a rotation
// delays in microseconds determine how fast it spins
#define yStep 3
#define zStep 4
#define xDir 5    //dir, pinMode = OUTPUT, HIGH for clockwise, LOW for anticlockwise
#define yDir 6
#define zDir 7
// pin 8 connects on all shared enable pins
#define xEnd 9    //endstops for calibration to avoid overreaching 
#define yEnd 10
#define zEnd 11   //shares MOSI
#define spnen 12  //spindle enable, shares MISO
#define spndir 13 //spindle direction, shares SCK
#define clk A0    //pinMode = INPUT
#define cmd A1    //pinMode = INPUT
#define att A2    //pinMode = INPUT
#define dat A3    //coolant enable
#define sda A4    //unused
#define scl A5    //unused 
const int stepsByRev = 200; //360° / 1.8° = 200 full steps, is microstepping enabled, number is higher
int rXVal;        //right analog stick x axis controls z rotation
int rYVal;        //~                ~ y axis controls y flexion
int lYVal;        //left analog stick y axis controls x extension
AccelStepper x(1, xStep, xDir);  //define the steppers
AccelStepper y(1, yStep, yDir);
AccelStepper z(1, zStep, zDir);
void setup(){
  Serial.begin(57600);
  delay(300);
  x.setMaxSpeed(500);
  y.setMaxSpeed(500);
  z.setMaxSpeed(500);
  x.setAcceleration(2000);
  y.setAcceleration(2000);
  z.setAcceleration(2000);
  /*error=ps2x.config_gamepad(clk,cmd,att,dat,false,false);  //setup pins and settings:  GamePad(clock, command, attention, data, Pressures?, Rumble?) check for error
  if(error == 0)
    Serial.println("Found Controller, configured successful");
  else if(error == 1)
    Serial.println("No controller found, check wiring, see readme.txt to enable debug. visit www.billporter.info for troubleshooting tips");
  else if(error == 2)
    Serial.println("Controller found but not accepting commands. see readme.txt to enable debug. Visit www.billporter.info for troubleshooting tips");
  else if(error == 3)
    Serial.println("Controller refusing to enter Pressures mode, may not support it. ");
  type = ps2x.readType(); 
     switch(type) {
      case 0:
        Serial.println("Unknown Controller type");
      break;
      case 1:
        Serial.println("DualShock Controller Found");
      break;
     }*/
}
void loop(){
//ps2x.read_gamepad(false, vibrate);  //read controller and set large motor to spin at 'vibrate' speed
//int zVal = ps2x.Analog(PSS_RX);
//int yVal = ps2x.Analog(PSS_RY);
//int xVal = ps2x.Analog(PSS_LY);
if (analogRead(clk) > 524) {  //  If joystick is moved Left
    //if (!digitalRead(Y_MAX_PIN)) {  // check if limit switch is activated
    //}
    //else {  //  if limit switch is not activated, move motor clockwise
    x.move(30);
    x.run();
    //}      
}
  
if (analogRead(clk) < 500) {  // If joystick is moved right
    x.move(-30);
    x.run(); 
Serial.print(analogRead(clk));
}
  /*if (analogRead(JOY_2_PIN) > 1012) {  //  If joystick is moved Left
    stepper3.move(30);
    stepper3.run();
      }      
  }
  
    if (analogRead(JOY_2_PIN) < 212) {  // If joystick is moved right
    
   if (!digitalRead(Y_MIN_PIN)) {  // check if limit switch is activated
   // delay(5000);
    }
      else {  //  if limit switch is not activated, move motor counter clockwise
          stepper3.move(-30);
    stepper3.run();
    }
    }
     if (analogRead(JOY_1_PIN) > 1012) {  //  If joystick is moved Left
    if (!digitalRead(Y_MAX_PIN)) {  // check if limit switch is activated
   // delay(5000);
    }
      else {  //  if limit switch is not activated, move motor clockwise
          stepper2.move(30);
    stepper2.run();
      }      
  }
  
    if (analogRead(JOY_1_PIN) < 212) {  // If joystick is moved right
    
    if (!digitalRead(Y_MIN_PIN)) {  // check if limit switch is activated
  // delay(5000);
    }
      else {  //  if limit switch is not activated, move motor counter clockwise
          stepper2.move(-30);
    stepper2.run();
    } 
  }
        0-124 anticlockwise with speed variable to analog value
        130-255 clockwise with speed variable to analog value 
        3000 microseconds = low speed
        300 microseconds = high speed 
do {
  digitalWrite(zDir, LOW);
  digitalWrite(zStep, HIGH);
  delayMicroseconds(300 + rXVal * 21, 7);  //analog stick can be zero, so the fastest it will go is 300 and can vary up to 3000
  digitalWrite(zStep, LOW);
} while (rXVal < 124);
do {
  digitalWrite(zDir, HIGH);
  digitalWrite(zStep, HIGH);
  delayMicroseconds(300 + (rXVal - 130) * 21, 7);
  digitalWrite(zStep, LOW);
} while (rXVal <= 255 && rXVal > 130);

do {
  digitalWrite(yDir, LOW);
  digitalWrite(yStep, HIGH);
  delayMicroseconds(300 + rYVal * 21, 7);  //analog stick can be zero, so the fastest it will go is 300 and can vary up to 3000
  digitalWrite(yStep, LOW);
} while (rYVal < 124);
do {
  digitalWrite(yDir, HIGH);
  digitalWrite(yStep, HIGH);
  delayMicroseconds(300 + (rYVal - 130) * 21, 7);
  digitalWrite(yStep, LOW);
} while (rYVal <= 255 && rXVal > 130);

do {
  digitalWrite(xDir, LOW);
  digitalWrite(xStep, HIGH);
  delayMicroseconds(300 + lYVal * 21, 7);  //analog stick can be zero, so the fastest it will go is 300 and can vary up to 3000
  digitalWrite(xStep, LOW);
} while (lYVal < 124);
do {
  digitalWrite(xDir, HIGH);
  digitalWrite(xStep, HIGH);
  delayMicroseconds(300 + (lYVal - 130) * 21, 7);
  digitalWrite(xStep, LOW);
} while (lYVal <= 255 && rXVal > 130);
*/

delay(50);
}
