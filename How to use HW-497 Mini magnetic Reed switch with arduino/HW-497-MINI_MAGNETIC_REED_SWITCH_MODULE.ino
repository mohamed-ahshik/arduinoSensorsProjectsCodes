int reedSwitchPin = 2; // Pin connected to reed switch
int redPin = 3;   // Pin connected to the red pin of the RGB LED



void setup() {
    pinMode(reedSwitchPin, INPUT);
    pinMode(redPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    boolean state = digitalRead(reedSwitchPin);
    Serial.print("Sensor State:");
    Serial.println((state)); 
    if(state == LOW)
      {
          // Update the RGB LED 
            digitalWrite(3, HIGH);
            Serial.println(" LED ON");
            delay(100);
      }
      else if(state == HIGH){
          digitalWrite(3, LOW);
        };
      
    delay(500); // Adjust delay as needed
}
