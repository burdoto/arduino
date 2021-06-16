#include <TimerOne.h>
#include <Wire.h>
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
  
  //WriteNumber(count);
}
