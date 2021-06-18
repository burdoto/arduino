#include <TimerOne.h>
//#include <Wire.h>
#include <MultiFuncShield.h>

int count;
bool down;

void setup() {
  Timer1.initialize();
  MFS.initialize(&Timer1);

  count = 0;
  down = false;
}
 
void loop(){
  //setLEDs(0);
  if (!digitalRead(A1)) {
    if (down) {
      return;
    }
    count = count - 1;
    down = true;
//    setLEDs(0b100);
  } else if (!digitalRead(A2)) {
    if (down) {
      return;
    }
    count = 0;
    down = true;
//    setLEDs(0b010);
  } else if (!digitalRead(A3)) {
    if (down) {
      return;
    }
    count = count + 1;
    down = true;
//    setLEDs(0b001);
  } else {
    down = false;
  }

  Serial.println(count);
  MFS.write(count);
  setLEDs(count);
  
  //WriteNumber(count);
}

bool setLEDs(int status){
  //Serial.print("setting status: 0b");Serial.println(status, BIN);
  digitalWrite(13, (status & 0b1000) != 0 ? OFF : ON);
  digitalWrite(12, (status & 0b0100) != 0 ? OFF : ON);
  digitalWrite(11, (status & 0b0010) != 0 ? OFF : ON);
  digitalWrite(10, (status & 0b0001) != 0 ? OFF : ON);
  return status < 15;
}
