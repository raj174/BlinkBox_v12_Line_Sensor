//Test Code for LSS05 from cytron
void setup() {
  // put your setup code here, to run once:
  pinMode(5,INPUT_PULLUP);
  pinMode(7,INPUT_PULLUP);
  pinMode(8,INPUT_PULLUP);
  pinMode(10,INPUT_PULLUP);
  pinMode(12,INPUT_PULLUP);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  int v = digitalRead(5);
  int w = digitalRead(7);
  int x = digitalRead(8);
  int y = digitalRead(10);
  int z = digitalRead(12);
  Serial.print(v);
  Serial.print(",");
  Serial.print(w);
  Serial.print(",");
  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.println(z);
}
