#include <AFMotor.h>
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);
char x;
String y;
int spd;
String sspd;
void setup() {
// put your setup code here, to run once:
Serial.begin(9600);
Serial.println("Rover test");
spd = 70;
motor1.setSpeed(spd);
motor2.setSpeed(spd);
motor3.setSpeed(spd);
motor4.setSpeed(spd);
delay(10);
}
void loop() {
while (!Serial.available());
y = Serial.readString();
Serial.println(y);
sspd = y.substring(1,4);
spd = sspd.toInt();
x = y[0];
if (x=='w'){
//allstop();
delay(500);
forward();
}
else if (x=='s'){
//allstop();
delay(500);
backward();
}
else if (x=='d'){
//allstop();
delay(500);
rightward();
}
else if (x=='a'){
  //allstop();
delay(500);
leftward();
}
else if (x=='f'){
allstop();
}
}
void backward(){
motor1.setSpeed(spd);
motor2.setSpeed(spd);
motor3.setSpeed(spd);
motor4.setSpeed(spd);
motor1.run(BACKWARD);
motor2.run(BACKWARD);
motor3.run(BACKWARD);
motor4.run(BACKWARD);
}
void forward(){
motor1.setSpeed(spd);
motor2.setSpeed(spd);
motor3.setSpeed(spd);
motor4.setSpeed(spd);
motor1.run(FORWARD);
motor2.run(FORWARD);
motor3.run(FORWARD);
motor4.run(FORWARD);
}
void leftward(){
motor1.setSpeed(spd);
motor4.setSpeed(spd);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor1.run(FORWARD);
motor4.run(FORWARD);
}
void rightward(){
motor2.setSpeed(spd);
motor3.setSpeed(spd);
motor1.run(RELEASE);
motor4.run(RELEASE);
motor2.run(FORWARD);
motor3.run(FORWARD);
}
void allstop(){
motor1.run(RELEASE);
motor2.run(RELEASE);
motor3.run(RELEASE);
motor4.run(RELEASE);
}
}
