#include <PsxControllerBitBang.h>
#include <DigitalIO.h>
#include <AccelStepper.h>
#include <Servo.h>

#include <avr/pgmspace.h>
typedef const __FlashStringHelper * FlashStr;
typedef const byte* PGM_BYTES_P;
#define PSTR_TO_F(s) reinterpret_cast<const __FlashStringHelper *> (s)

#define X_STEP_PIN 2
#define X_DIR_PIN 5
//#define X_MIN_PIN A0
#define X_MAX_PIN 9

#define Y_STEP_PIN 3
#define Y_DIR_PIN 6
//#define Y_MIN_PIN A2
#define Y_MAX_PIN 10

#define Z_STEP_PIN 2
#define Z_DIR_PIN 5
//#define Z_MIN_PIN A4
#define Z_MAX_PIN 11

#define PIN_PS2_ATT A3
#define PIN_PS2_DAT 13
#define PIN_PS2_CMD 12
#define PIN_PS2_CLK A0
#define PIN_PS2_ACK A1

//#define SERVO_1_PIN 12

AccelStepper stepper1(1, X_STEP_PIN, X_DIR_PIN);
AccelStepper stepper2(1, Y_STEP_PIN, Y_DIR_PIN);
AccelStepper stepper3(1, Z_STEP_PIN, Z_DIR_PIN);

Servo clawServo;
const char buttonSelectName[] PROGMEM = "Select";
const char buttonL3Name[] PROGMEM = "L3";
const char buttonR3Name[] PROGMEM = "R3";
const char buttonStartName[] PROGMEM = "Start";
const char buttonUpName[] PROGMEM = "Up";
const char buttonRightName[] PROGMEM = "Right";
const char buttonDownName[] PROGMEM = "Down";
const char buttonLeftName[] PROGMEM = "Left";
const char buttonL2Name[] PROGMEM = "L2";
const char buttonR2Name[] PROGMEM = "R2";
const char buttonL1Name[] PROGMEM = "L1";
const char buttonR1Name[] PROGMEM = "R1";
const char buttonTriangleName[] PROGMEM = "Triangle";
const char buttonCircleName[] PROGMEM = "Circle";
const char buttonCrossName[] PROGMEM = "Cross";
const char buttonSquareName[] PROGMEM = "Square";
const int stepsPerRevolution = 200;

const char* const psxButtonNames[PSX_BUTTONS_NO] PROGMEM = {
  buttonSelectName,
  buttonL3Name,
  buttonR3Name,
  buttonStartName,
  buttonUpName,
  buttonRightName,
  buttonDownName,
  buttonLeftName,
  buttonL2Name,
  buttonR2Name,
  buttonL1Name,
  buttonR1Name,
  buttonTriangleName,
  buttonCircleName,
  buttonCrossName,
  buttonSquareName
};

byte psxButtonToIndex (PsxButtons psxButtons) {
  byte i;

  for (i = 0; i < PSX_BUTTONS_NO; ++i) {
    if (psxButtons & 0x01) {
      break;
    }

    psxButtons >>= 1U;
  }

  return i;
}

FlashStr getButtonName (PsxButtons psxButton) {
  FlashStr ret = F("");
  
  byte b = psxButtonToIndex (psxButton);
  if (b < PSX_BUTTONS_NO) {
    PGM_BYTES_P bName = reinterpret_cast<PGM_BYTES_P> (pgm_read_ptr (&(psxButtonNames[b])));
    ret = PSTR_TO_F (bName);
  }

  return ret;
}

void dumpButtons (PsxButtons psxButtons) {
  static PsxButtons lastB = 0;

  if (psxButtons != lastB) {
    lastB = psxButtons;     // Save it before we alter it
    
    Serial.print (F("Pressed: "));

    for (byte i = 0; i < PSX_BUTTONS_NO; ++i) {
      byte b = psxButtonToIndex (psxButtons);
      if (b < PSX_BUTTONS_NO) {
        PGM_BYTES_P bName = reinterpret_cast<PGM_BYTES_P> (pgm_read_ptr (&(psxButtonNames[b])));
        Serial.print (PSTR_TO_F (bName));
      }
      psxButtons &= ~(1 << b);
      if (psxButtons != 0) {
        Serial.print (F(", "));
      }
    }
    Serial.println ();
  }
}

void dumpAnalog (const char *str, const byte x, const byte y) {
  Serial.print (str);
  Serial.print (F(" analog: x = "));
  Serial.print (x);
  Serial.print (F(", y = "));
  Serial.println (y);
}

const char ctrlTypeUnknown[] PROGMEM = "Unknown";
const char ctrlTypeDualShock[] PROGMEM = "Dual Shock";
const char ctrlTypeDsWireless[] PROGMEM = "Dual Shock Wireless";
const char ctrlTypeGuitHero[] PROGMEM = "Guitar Hero";
const char ctrlTypeOutOfBounds[] PROGMEM = "(Out of bounds)";

const char* const controllerTypeStrings[PSCTRL_MAX + 1] PROGMEM = {
  ctrlTypeUnknown,
  ctrlTypeDualShock,
  ctrlTypeDsWireless,
  ctrlTypeGuitHero,
  ctrlTypeOutOfBounds
};

PsxControllerBitBang<PIN_PS2_ATT, PIN_PS2_CMD, PIN_PS2_DAT, PIN_PS2_CLK> psx;

boolean haveController = true;
 
void setup() {
  Serial.begin(115200);//sets the baud rate
  Serial.println (F("Ready!"));
  //clawServo.attach(SERVO_1_PIN);
  pinMode(X_MAX_PIN, INPUT);
  pinMode(Y_MAX_PIN, INPUT);
  pinMode(Z_MAX_PIN, INPUT);
  stepper1.setMaxSpeed(200);
  stepper1.setAcceleration(100);
  stepper2.setMaxSpeed(200);
  stepper2.setAcceleration(100);
  stepper3.setMaxSpeed(200);
  stepper3.setAcceleration(100);
  clawServo.write(90);
}
void loop() {
  static byte slx, sly, srx, sry;
    
  if (!haveController) {
    if (psx.begin ()) {
      Serial.println (F("Controller found!"));
      delay (300);
      if (!psx.enterConfigMode ()) {
        Serial.println (F("Cannot enter config mode"));
      } else {
        PsxControllerType ctype = psx.getControllerType ();
        PGM_BYTES_P cname = reinterpret_cast<PGM_BYTES_P> (pgm_read_ptr (&(controllerTypeStrings[ctype < PSCTRL_MAX ? static_cast<byte> (ctype) : PSCTRL_MAX])));
        Serial.print (F("Controller Type is: "));
        Serial.println (PSTR_TO_F (cname));

        if (!psx.enableAnalogSticks ()) {
          Serial.println (F("Cannot enable analog sticks"));
        }
        
        //~ if (!psx.setAnalogMode (false)) {
          //~ Serial.println (F("Cannot disable analog mode"));
        //~ }
        //~ delay (10);
        
        if (!psx.enableAnalogButtons ()) {
          Serial.println (F("Cannot enable analog buttons"));
        }
        
        if (!psx.exitConfigMode ()) {
          Serial.println (F("Cannot exit config mode"));
        }
      }
      
      haveController = true;
    }
  } 
  else {
    if (!psx.read ()) {
      Serial.println (F("Controller lost :("));
      haveController = false;
    } 
    else {
      dumpButtons (psx.getButtonWord ());

      byte lx, ly;
      psx.getLeftAnalog (lx, ly);
      if (lx != slx || ly != sly) {
        //dumpAnalog ("Left", lx, ly);
        slx = lx;
        sly = ly;
      }

      byte rx, ry;
      psx.getRightAnalog (rx, ry);
      if (rx != srx || ry != sry) {
        dumpAnalog ("Right", rx, ry);
        srx = rx;
        sry = ry;
      }
    }
  }  
  int speed1 = map(slx, 0, 255, 100, -100);
  stepper1.setSpeed(speed1);
  stepper1.runSpeed();
  delay (1000 / 60);
}
