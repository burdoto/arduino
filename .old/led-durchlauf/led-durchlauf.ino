//LEDs an den digitalen PINs 10,11,12,13
const byte LED[] = {13,12,11,10};
int state = 1;
long last = 0;
 
#define Btn1 A1 //Taster S1
#define Btn2 A2 //Taster S2
#define Btn3 A3 //Taster S3

#define ON LOW
#define OFF HIGH

void setup(){
  Serial.begin(9600);
  pinMode(LED[0], OUTPUT); //LED1 am digitalen PIN 13
  pinMode(LED[1], OUTPUT); //LED2 am digitalen PIN 12
  pinMode(LED[2], OUTPUT); //LED3 am digitalen PIN 11
  pinMode(LED[3], OUTPUT); //LED4 am digitalen PIN 10
  setLEDs(0);
}
 
void loop(){
  if (millis() - last < analogRead(0) * 3) {
    return;
  }
  
  if (setLEDs(state)) {
    state = state << 1;
    last = millis();
  } else {
    state = 1;
  }
}

bool setLEDs(int status){
  Serial.print("setting status: 0b");
  Serial.println(status, BIN);
  digitalWrite(LED[0], (status & 0b1000) != 0 ? ON : OFF);
  digitalWrite(LED[1], (status & 0b0100) != 0 ? ON : OFF);
  digitalWrite(LED[2], (status & 0b0010) != 0 ? ON : OFF);
  digitalWrite(LED[3], (status & 0b0001) != 0 ? ON : OFF);
  return status < 9;
}
