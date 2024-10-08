#include <AccelStepper.h>
#include <Servo.h>

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

#define JOY_1_PIN          13   // ANALOG NUMBERING
#define JOY_2_PIN          14   // ANALOG NUMBERING
#define JOY_3_PIN          15   // ANALOG NUMBERING

#define JOY_1_BTN          11
#define JOY_2_BTN          6  

#define SERVO_1_PIN        4
#define SERVO_2_PIN        5
AccelStepper stepper1(AccelStepper::DRIVER, X_STEP_PIN, X_DIR_PIN);
AccelStepper stepper2(AccelStepper::DRIVER, Y_STEP_PIN, Y_DIR_PIN);
AccelStepper stepper3(AccelStepper::DRIVER, Z_STEP_PIN, Z_DIR_PIN);

Servo clawServo;
Servo armServo;

int button1State = -1;
int button2State = -1;
int clawClosed = 0;
int clawRot = 0;
void setup() {
  Serial.begin(115200);//sets the baud rate
  clawServo.attach(SERVO_1_PIN);
  armServo.attach(SERVO_2_PIN);
  pinMode(X_ENABLE_PIN, OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  pinMode(Z_ENABLE_PIN, OUTPUT);
  pinMode(Y_MIN_PIN, INPUT);
  pinMode(Y_MAX_PIN, INPUT);
  pinMode(JOY_1_BTN, INPUT);
  pinMode(JOY_2_BTN, INPUT);
  digitalWrite(X_ENABLE_PIN, LOW);
  digitalWrite(Y_ENABLE_PIN, LOW);
  digitalWrite(Z_ENABLE_PIN, LOW);
  stepper1.setMaxSpeed(500);
  stepper2.setMaxSpeed(500);
  stepper3.setMaxSpeed(500);
  stepper1.setAcceleration(2000);
  stepper2.setAcceleration(2000);
  stepper3.setAcceleration(2000);
  stepper1.run();
  stepper2.run();
  stepper3.run();
  clawServo.write(90);
  armServo.write(90);

}
void loop() {
button1State = digitalRead(JOY_1_BTN);
button2State = digitalRead(JOY_2_BTN);
Serial.print(button1State);
Serial.println(button2State);

if (analogRead(JOY_3_PIN) > 1012) {  //  If joystick is moved Left
    if (!digitalRead(Y_MAX_PIN)) {  // check if limit switch is activated
    }
    else {  //  if limit switch is not activated, move motor clockwise
    stepper1.move(30);
    stepper1.run();
    }      
}
  
if (analogRead(JOY_3_PIN) < 212) {  // If joystick is moved right
    stepper1.move(-30);
    stepper1.run();
    } 
}
  if (analogRead(JOY_2_PIN) > 1012) {  //  If joystick is moved Left
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

 if (button2State == 1){
 
    switch (clawRot){
      case 0:
      clawRot = 1;
      armServo.write(90);
      delay(300);
      break;
      
    case 1:
      clawRot = 0;
      armServo.write(0);  
      delay(300);
      break;
    }
  }

 
 if (button1State == 1){
 
    switch (clawClosed){
      case 0:
      clawClosed = 1;
      clawServo.write(90);
      delay(300);
      break;
      
    case 1:
      clawClosed = 0;
      clawServo.write(0);  
      delay(300);
      break;
    }
  }  
}

