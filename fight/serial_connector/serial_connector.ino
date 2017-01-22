void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}
int x=0;
void loop() {
  Serial.println(x);
  x=x+1;
  delay(100);
}
