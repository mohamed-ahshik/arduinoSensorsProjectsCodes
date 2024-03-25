int buzzerPin = 8;  // Define the pin where the buzzer module is connected

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin, OUTPUT);  // Set the buzzer pin as an OUTPUT
}

void loop() {
  // Turn on the buzzer for 1 second
  digitalWrite(buzzerPin, HIGH);
  Serial.print("Buzzing\n");
  delay(1000);
  
  // Turn off the buzzer for 1 second
  digitalWrite(buzzerPin, LOW);
  Serial.print("Off\n");
  delay(1000);
}
