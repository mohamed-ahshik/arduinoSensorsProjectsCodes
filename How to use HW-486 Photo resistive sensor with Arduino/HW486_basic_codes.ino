// Define the signal pin here
int SignalPin = A0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Since this sensor gives analog values, use analogRead
  int light = analogRead(SignalPin);
  Serial.println(light);
  delay(100);
}


