//LEDs an den digitalen PINs 10,11,12,13
const byte LED[] = {13,12,11,10};
 
#define BUTTON1 A1 //Taster S1
#define BUTTON2 A2 //Taster S2
#define BUTTON3 A3 //Taster S3
 
void setup(){
pinMode(LED[0], OUTPUT); //LED1 am digitalen PIN 13
pinMode(LED[1], OUTPUT); //LED2 am digitalen PIN 12
pinMode(LED[2], OUTPUT); //LED3 am digitalen PIN 11
pinMode(LED[3], OUTPUT); //LED4 am digitalen PIN 10
digitalWrite(LED[0], HIGH); //LED1 ausschalten
digitalWrite(LED[1], HIGH); //LED2 ausschalten
digitalWrite(LED[2], HIGH); //LED3 ausschalten
digitalWrite(LED[3], HIGH); //LED4 ausschalten
}
 
void loop(){
  //Wenn der Taster S1 gedrückt wird,
  //so sollen alle LEDs eingeschaltet werden.
  if(!digitalRead(BUTTON1)){
    setLEDs(LOW, LOW, LOW, LOW);
  }
  //Wenn der Taster S2 gedrückt wird, 
  //so sollen die LEDs 1,3 ausgeschaltet und 2,4 eingeschaltet werden.
  if(!digitalRead(BUTTON2)){
    setLEDs(HIGH, LOW, HIGH, LOW);
  }
  //Wenn der Taster S3 gedrückt wird,
  //so sollen alle LEDs ausgeschaltet werden.
  if(!digitalRead(BUTTON3)){
   setLEDs(HIGH, HIGH, HIGH, HIGH);
  }
}
void setLEDs(int led1Status, int led2Status, int led3Status, int led4Status){
  digitalWrite(LED[0], led1Status);
  digitalWrite(LED[1], led2Status);
  digitalWrite(LED[2], led3Status);
  digitalWrite(LED[3], led4Status);
}
