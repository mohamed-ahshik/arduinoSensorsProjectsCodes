
#include "LowPower.h"
//By Rocket scream Electronics
#include <Wire.h>
#include <Rtc_Pcf8563.h>
// joe robertson from library 
/* get a real time clock object */
Rtc_Pcf8563 rtc;
/* a flag for the interrupt */
volatile int alarm_flag=0;
int RelayStatus = 13;
int WaterinPeriod = 10000; // how long you want the motor to pump. This is 10 seconds
unsigned long time_now = 0;
const int wakeUpPin = 2; // external interrupt 0 if you choose 3 its interrupt 1

 
void wakeUp()
{
  Serial.println("woke up");
  
  
}
 
void setup()
{
   Serial.begin(9600);
   pinMode(LED_BUILTIN, OUTPUT);
   digitalWrite(LED_BUILTIN, HIGH);
   
   pinMode(wakeUpPin, INPUT_PULLUP); // connected to 5v so will be high
   //RTC is high, when the alarm is triggered the interuupt becomes active low.
   digitalWrite(wakeUpPin, HIGH);       // turn on pullup resistors 
   
   
   pinMode(RelayStatus, OUTPUT);
   digitalWrite(RelayStatus,LOW);

 

   attachInterrupt(digitalPinToInterrupt(wakeUpPin), wakeUp, CHANGE);// when it detects interrupt signal from RTC, it will run the wakeup function
   
  
//    /* clear out all the registers */
//    rtc.initClock();
//    /* set a time to start with.
//     * day, weekday, month, century, year */
//    rtc.setDate(16, 7, 7, 0, 23);
//    /* hr, min, sec */
//    rtc.setTime(1, 8, 00);
//    /* set an alarm for 20 secs later...
//     * alarm pin goes low when match occurs
//     * this triggers the interrupt routine
//     * min, hr, day, weekday 
//     * 99 = no alarm value to be set
//     */
      rtc.setAlarm(13 , 1, 99, 99);
}
 
void loop()
{
  Serial.println("Going to Sleep");
  Serial.print("Hour:");
  Serial.println(rtc.getHour());
  Serial.print("Minute:");
  Serial.println(rtc.getMinute());
  Serial.print("Second:");
  Serial.println(rtc.getSecond());
  Serial.print("Weekday:");
  Serial.println(rtc.getWeekday());
  Serial.print("Day:");
  Serial.println(rtc.getDay());
  Serial.print("Month:");
  Serial.println(rtc.getMonth());
  Serial.print("Year:");
  Serial.println(rtc.getYear());
  Serial.print("AlarmHour:");
  Serial.println(rtc.getAlarmHour());
  Serial.print("AlarmMinute:");
  Serial.println(rtc.getAlarmMinute());
  delay(1000);
  digitalWrite(LED_BUILTIN, LOW);
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF);
  delay(1000);
  digitalWrite(LED_BUILTIN, HIGH);
  
  delay(1000);
  clr_alarm();
  WateringCommand();




}



void clr_alarm()
{
  //to detach the interrupt pin
  detachInterrupt(0);
  Serial.print("blink!\r\n");
  Serial.print("Hour:");
  Serial.println(rtc.getHour());
  Serial.print("Minute:");
  Serial.println(rtc.getMinute());
  Serial.print("Second:");
  Serial.println(rtc.getSecond());
  Serial.print("Weekday:");
  Serial.println(rtc.getWeekday());
  Serial.print("Day:");
  Serial.println(rtc.getDay());
  Serial.print("Month:");
  Serial.println(rtc.getMonth());
  Serial.print("Year:");
  Serial.println(rtc.getYear());
  Serial.print("AlarmHour:");
  Serial.println(rtc.getAlarmHour());
  Serial.print("AlarmMinute:");
  Serial.println(rtc.getAlarmMinute());
  delay(1000);

}

void WateringCommand(){
  
  time_now = millis();
  while(millis() < time_now +  WaterinPeriod){
    Serial.println("Watering");
    digitalWrite(RelayStatus,HIGH);
  }
  digitalWrite(RelayStatus,LOW);


}
