// Define the signal pin here
int SignalPin = A0;
int Threshold = 300;
int LightPin = A1;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(LightPin, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  //Since this sensor gives analog values, use analogRead
  int light = analogRead(SignalPin);
  Serial.println(light);
  if (light > Threshold)
  {
    Serial.println("Bright");
    analogWrite(LightPin, 0);
  }
  else
  {
    analogWrite(LightPin, 255);
    Serial.println("Low Light");
    //digitalWrite(LightPin, HIGH);
  }
  delay(100);
}


