#include <Wire.h>
#include <Rtc_Pcf8563.h>
#include <TimerOne.h>

//init the real time clock
Rtc_Pcf8563 rtc;
int STATUS_LED = 0;
void chooseLed() {
  if ( STATUS_LED == 0 ) {
    digitalWrite(LED_BUILTIN, HIGH);
    STATUS_LED = 1;   
  } else {
    digitalWrite(LED_BUILTIN, LOW);
    STATUS_LED = 0;   
  }
}
void setup() {
  Serial.begin(9600);
  Wire.begin();
  pinMode(LED_BUILTIN, OUTPUT);
  Timer1.initialize(1000000);
  Timer1.attachInterrupt(chooseLed);  //clear out all the registers
  //rtc.initClock();
  //set a time to start with.
  //day, weekday, month, century, year
  //rtc.setDate(21, 3, 9, 20, 22);
  //hr, min, sec
  //rtc.setTime(21, 27, 0);
}
                                                                                
void loop() {
/*
  Serial.print("Time:");
  //Serial.print(rtc.formatTime(RTCC_TIME_HM));
  Serial.print(rtc.formatTime());
  

  Serial.print("\t Date:");
  //Serial.println(rtc.formatDate(RTCC_DATE_ASIA));
  Serial.println(rtc.formatDate(RTCC_DATE_WORLD));

  
  delay(1000);
*/    
}
  