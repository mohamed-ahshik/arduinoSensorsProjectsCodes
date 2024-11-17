#define TOUCH_PIN 3   // Digital pin connected to the sensor

void setup() {
  Serial.begin(9600);   // Initialize serial communication
  pinMode(TOUCH_PIN, INPUT); // Set the sensor pin as input
}

void loop() {
  // Read the state of the touch sensor
  int touchState = digitalRead(TOUCH_PIN);

  // Print the state to the serial monitor
  Serial.println(touchState);
//
//   You can add more logic here based on the touch state
//   For example:
   if (touchState == HIGH) {
     Serial.println("Touch detected!");
     // Perform some action
   }

  delay(500);  // Add a small delay to avoid rapid readings
}
