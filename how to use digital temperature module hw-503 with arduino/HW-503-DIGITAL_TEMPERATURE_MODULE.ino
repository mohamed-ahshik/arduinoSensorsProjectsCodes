// Declaration and initialization of the input pins
int Analog_Input = A0; // Analog output of the sensor
int Digital_Input = 3; // Digital output of the sensor
  
void setup ()
{
  pinMode (Analog_Input, INPUT);
  pinMode (Digital_Input, INPUT);
       
  Serial.begin (9600); // Serial output with 9600 bps
}
  
// The program reads the current values of the input pins
// and outputs them on the serial output
void loop ()
{
  float Analog;
  int Digital;
    
  //Actual values are read, converted to the voltage value....
  Analog = analogRead (Analog_Input) * (5.0 / 1023.0); 
  Digital = digitalRead (Digital_Input);
    
  //... and output at this position
  Serial.print ("Analog voltage value:"); 
  Serial.print (Analog, 4); 
  Serial.print ("V, ");
  Serial.print ("Limit value:");
  
  if(Digital==1)
  {
      Serial.println (" reached");
  }
  else
  {
      Serial.println (" not yet reached");
  }
  Serial.println ("----------------------------------------------------------------");
  delay (1000);
}
