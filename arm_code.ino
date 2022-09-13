#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define USMIN 500 // This is the rounded 'minimum' microsecond length based on the minimum pulse of 150
#define USMAX 1800 // This is the rounded 'maximum' microsecond length based on the maximum pulse of 600
#define SERVO_FREQ 50 // Analog servos run at ~50 Hz updates
int servonum;
String x;
String arm;
String spos;
int pos1;
int pos2;
void setup() {
Serial.begin(9600);
Serial.println("6 DOF arm test!");
pwm.begin();
pwm.setOscillatorFrequency(27000000);
pwm.setPWMFreq(SERVO_FREQ);
delay(10);
}
void loop() {
while (!Serial.available());
x = Serial.readString();
Serial.println(x);
arm = x[0];
spos = x.substring(1,5);
pos1 = spos.toInt();
spos = x.substring(5);
pos2 = spos.toInt();
servonum = arm.toInt();
Serial.println(pos1);
Serial.println(pos2);
if (servonum==1){
servonum = 0;
moveServo(servonum, pos1, pos2);
}
else if (servonum==2){
servonum = 2;
pos1 = map(pos1, 600, 1800, 600, 1250);
pos2 = map(pos2, 600, 1800, 600, 1250);
moveServo(servonum, pos1, pos2);
}
else if (servonum==3){
servonum = 4;
moveServo(servonum, pos1, pos2);
}
else if (servonum==4){
servonum = 6;
moveServo(servonum, pos1, pos2);
}
else if (servonum==5){
servonum = 8;
moveServo(servonum, pos1, pos2);
}
else if (servonum==6){
servonum = 15;
pos1 = map(pos1, 600, 1800, 750, 1400);
pos2 = map(pos2, 600, 1800, 750, 1400);
moveServo(servonum, pos1, pos2);
}
else if (x[0]=='r'){
// go to rest position
pwm.writeMicroseconds(0, 1200);
pwm.writeMicroseconds(2, 1250);
pwm.writeMicroseconds(4, 1350);
pwm.writeMicroseconds(6, 1150);
pwm.writeMicroseconds(8, 1150);
pwm.writeMicroseconds(15, 1150);
}
}
void moveServo(int servo, int pos1, int pos2){
// Drive each servo one at a time using writeMicroseconds(), it's not precise due to calculation rounding!
// The writeMicroseconds() function is used to mimic the Arduino Servo library writeMicroseconds() behavior.
if (pos1<pos2){
for (uint16_t microsec = pos1; microsec < pos2; microsec++) {
pwm.writeMicroseconds(servo, microsec);
}
delay(500);
}
else if (pos1>pos2){
for (uint16_t microsec = pos1; microsec > pos2; microsec--) {
pwm.writeMicroseconds(servo, microsec);
}
delay(500);
}
}
void moveServo1(int servo){
for (uint16_t microsec = USMAX; microsec > USMIN; microsec--) {
pwm.writeMicroseconds(servo, microsec);
}
delay(500);
}
