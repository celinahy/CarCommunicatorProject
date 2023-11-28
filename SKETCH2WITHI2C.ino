#include <IRremote.h>
#include <Adafruit_PWMServoDriver.h>


IRrecv IR(3);
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40); 

int servoMin =  125;       
int servoMax =  575;  
int pulse = map(90, 0, 180, servoMin, servoMax);
int enable1 = 0;
int enable2 = 0;
int enable3 = 0;
int enable4 = 0;

void setup() {
  // put your setup code here, to run once:
  pwm.begin();
  pwm.setPWMFreq(60);  // Makes servos run at 60 Hz rate.  
  IR.enableIRIn();
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(IR.decode()) {
    Serial.println(IR.decodedIRData.decodedRawData, HEX);

    if(IR.decodedIRData.decodedRawData == 0xED127F80) {
      enable1 = !enable1;
      if (enable1) {
        for (int pulseLength = servoMin ; pulseLength <= pulse ; pulseLength++)    //Move each servo from servoMin to servoMax
        {
          pwm.setPWM(0, 0, pulseLength);  
        }
        delay(100);
      }
      else {
        for (int pulseLength = pulse ; pulseLength >= servoMin ; pulseLength--)    ////Move each servo from servoMax to servoMin
        {
          pwm.setPWM(0, 0, pulseLength);     
        }
        delay(100);
      }
      delay(15);
    }

    else if(IR.decodedIRData.decodedRawData == 0xE51A7F80) {
      enable2 = !enable2;
      if (enable2) {
        for (int pulseLength = servoMin ; pulseLength <= pulse ; pulseLength++)    //Move each servo from servoMin to servoMax
        {
          pwm.setPWM(4, 0, pulseLength);           
        }
        delay(100);
      }
      else {
        for (int pulseLength = pulse ; pulseLength >= servoMin ; pulseLength--)    ////Move each servo from servoMax to servoMin
        {
          pwm.setPWM(4, 0, pulseLength);          
        }
        delay(100);
      }
      delay(15);
    }

    else if(IR.decodedIRData.decodedRawData == 0xFE017F80) {
      enable3 = !enable3;
      if (enable3) {
        for (int pulseLength = servoMin ; pulseLength <= pulse ; pulseLength++)    //Move each servo from servoMin to servoMax
        {
          pwm.setPWM(8, 0, pulseLength);           
        }
        delay(100);
      }
      else {
        for (int pulseLength = pulse ; pulseLength >= servoMin ; pulseLength--)    ////Move each servo from servoMax to servoMin
        {
          pwm.setPWM(8, 0, pulseLength);          
        }
        delay(100);
      }
      delay(15);
    }

    else if(IR.decodedIRData.decodedRawData == 0xFD027F80) {
      enable4 = !enable4;
      if (enable4) {
        for (int pulseLength = servoMin ; pulseLength <= pulse ; pulseLength++)    //Move each servo from servoMin to servoMax
        {
          pwm.setPWM(12, 0, pulseLength);           
        }
        delay(100);
      }
      else {
        for (int pulseLength = pulse ; pulseLength >= servoMin ; pulseLength--)    ////Move each servo from servoMax to servoMin
        {
          pwm.setPWM(12, 0, pulseLength);          
        }
        delay(100);
      }
      delay(15);
    }

    delay(30);
    IR.resume();
  }
}
