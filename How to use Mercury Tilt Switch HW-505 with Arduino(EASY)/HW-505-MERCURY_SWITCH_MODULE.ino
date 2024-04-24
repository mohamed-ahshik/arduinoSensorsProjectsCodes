int mercurySwitchPin = 2; // Change to the digital pin you've connected the module's OUT pin to
int redPin = 3;   // Pin connected to the red pin of the RGB LED
void setup() {
    pinMode(mercurySwitchPin, INPUT);
 
    pinMode(redPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    boolean state = digitalRead(mercurySwitchPin);
    Serial.print("Sensor State:");
    Serial.println((state)); 
    if(state == HIGH)
      {
          // Update the RGB LED 
            digitalWrite(3, HIGH);
            Serial.println(" LED ON");
            delay(100);
      }
      else if(state == LOW){
          digitalWrite(3, LOW);
        };
      
    delay(100); // Adjust delay as needed
}
