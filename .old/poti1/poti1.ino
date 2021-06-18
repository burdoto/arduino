#define potentiometer 0
#define latch 4
#define clk 7
#define data 8
/* Mapping der Adressen für die Zahlen 0 bis 9 */
const byte SEGMENT_MAP[] = {0xC0,0xF9,0xA4,0xB0,0x99,0x92,0x82,0xF8,0X80,0X90};
/* Mapping für die Segmente 0 bis 3 */
const byte SEGMENT_SELECT[] = {0xF1,0xF2,0xF4,0xF8};
/* letzter Zeitpunkt der Ausführung.*/
unsigned long previousMillis = 0;
/* Interval der Ausführung.*/
const long interval = 550;   
 
void setup(){
  Serial.begin(9600);
  pinMode(latch,OUTPUT);
  pinMode(clk,OUTPUT);
  pinMode(data,OUTPUT);
}
 
void loop(){
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) { 
    int value = analogRead(potentiometer);
    Serial.println(value);
  
    WriteNumberToSegment(0 , value / 1000); 
    WriteNumberToSegment(1 , (value / 100) % 10);
    WriteNumberToSegment(2 , (value / 10) % 10);
    WriteNumberToSegment(3 , value % 10);
  }
}
/**
 * Schreibt eine Zahl (value) auf ein Segment (segment).
 */
void WriteNumberToSegment(byte segment, byte value){
  digitalWrite(latch,LOW);
  shiftOut(data, clk, MSBFIRST, SEGMENT_MAP[value]);
  shiftOut(data, clk, MSBFIRST, SEGMENT_SELECT[segment]);
  digitalWrite(latch,HIGH);
}
