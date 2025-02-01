#include <VarSpeedServo.h>
VarSpeedServo servo1;
VarSpeedServo servo2;
VarSpeedServo servo3;
VarSpeedServo servo4;
VarSpeedServo servo5;
VarSpeedServo servo6;

  int SPEED = 20;
  int SPEED2 = 50;


void setup() {
servo1.attach(8);
servo2.attach(9);
servo3.attach(10);
servo4.attach(11);
servo5.attach(12);
servo6.attach(13);
int pos;
Serial.begin(9600);
}

void loop() {


char i= Serial.read();
switch(i){




case 'E':

servo6.slowmove(0,SPEED);
delay(1000);
break;

case 'F':

servo6.slowmove(70,SPEED);
delay(1000);
break;

case 'A':
servo1.slowmove(30,SPEED);
servo2.slowmove(90,SPEED);
servo3.slowmove(90,SPEED2);
servo4.slowmove(50,SPEED2);
servo5.slowmove(20,SPEED2);
delay(1000);
break;
  
case 'B':
servo1.write(90,SPEED);
servo2.write(90,SPEED);
servo3.write(80,SPEED);
servo4.write(100,SPEED);
servo5.write(40,SPEED);
//servo6.write(50);
delay(1000);
break;


case 'C':
servo1.write(140);
servo2.write(20);
servo3.write(30);
servo4.write(100);
servo5.write(40);
//servo6.write(50);
delay(1000);
break;


case 'D':
servo1.write(90);
servo2.write(150);
servo3.write(60);
servo4.write(0);
servo5.write(100);
//servo6.write(50);
delay(1000);
break;

case 'G':
//syphax
servo1.write(170);
servo2.write(150);
servo3.write(120);
servo4.write(0);
servo5.write(100);
delay(1000);
break;



case 'H':
//syphax
servo1.write(100);
servo2.write(150);
servo3.write(60);
servo4.write(0);
servo5.write(100);
delay(100);
servo6.write(70);
delay(100);
servo4.write(90);
delay(1000);
break;

case 'K':
//syphax
servo1.write(100,SPEED);
servo2.write(150,SPEED);
servo3.write(120,SPEED);
servo4.write(0,SPEED);
servo5.write(100,SPEED);
delay(1000);
break;



case 'Y':
servo1.write(140,SPEED);
servo2.write(20,SPEED);
servo3.write(30,SPEED);
servo4.write(100,SPEED);
servo5.write(40,SPEED);

delay(1000);
servo5.write(80);
delay(100);

servo5.write(60);
delay(100);
servo5.write(80);
delay(100);

servo5.write(60);
delay(100);

servo5.write(80);
delay(100);

servo5.write(60);
delay(100);

servo5.write(80);
delay(100);

servo5.write(60);
//servo6.write(50);
delay(1000);
break;





case 'V':
servo1.write(90);
servo2.write(150);
servo3.write(30);
servo4.write(0);
servo5.write(100);
//servo6.write(50);c

delay(1000);
break;


case 'X':
servo5.write(20,SPEED);
servo4.write(50,SPEED);
servo3.write(70,SPEED);
servo2.write(10,SPEED);
servo1.write(30,SPEED);

delay(1000);
break;

case 'Z':
servo5.write(60,SPEED);
servo4.write(170,SPEED);
servo3.write(170,SPEED);
servo2.write(70,SPEED);
servo1.write(30,SPEED);

delay(1000);
break;

case 'Q':

servo3.write(150,SPEED);
servo2.write(50,SPEED);
delay(100);

servo5.write(0,SPEED);
servo4.write(150,SPEED);
servo3.write(170,SPEED);
servo2.write(70,SPEED);
servo1.write(30,SPEED);

delay(1000);
break;


case 'P':

servo3.write(150,SPEED2);
servo2.write(50,SPEED2);
delay(100);

servo5.write(0,SPEED);
servo4.write(150,SPEED);
servo3.write(170,SPEED);
servo2.write(70,SPEED2);
servo1.write(30,SPEED2);
delay(100);
servo3.write(90,SPEED);
servo2.write(50,SPEED2);
servo1.write(30,SPEED2);
delay(1000);
break;

case 'l':



servo5.write(180,SPEED);
servo4.write(90,SPEED);

servo3.write(120,SPEED);
servo2.write(50,SPEED2);
servo1.write(30,SPEED2);
delay(1000);
break;









}}
