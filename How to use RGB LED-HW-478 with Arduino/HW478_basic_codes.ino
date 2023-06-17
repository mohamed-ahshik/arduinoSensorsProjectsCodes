//Initialise the pins to be used for each colour  
  int R_LED = 11 ;
  int G_LED = 10 ;
  int B_LED = 9 ;
void setup() {
  // put your setup code here, to run once:
  // initialize digital pin for each colour as an output.
  pinMode(R_LED, OUTPUT);
  pinMode(G_LED, OUTPUT);
  pinMode(B_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  // Use analogwrite to control the LED using PWM
  analogWrite(R_LED, 20);
  analogWrite(G_LED, 255);
  analogWrite(B_LED, 160);
  delay(1000);

}
