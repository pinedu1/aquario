//Programa: Display LCD 16x2
//Autor: FILIPEFLOP
 
//Carrega a biblioteca LiquidCrystal
#include <stdarg.h>
#include <LiquidCrystal.h>

#include <Rtc_Pcf8563.h>
#include <TimerOne.h>

#include <OneWire.h>
#include <DallasTemperature.h>
//
//OneWire  ds(10);  // on pin 10 (a 4.7K resistor is necessary)

//Define os pinos que serão utilizados para ligação ao display
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
Rtc_Pcf8563 rtc;
int STATUS_LED = 0;

#define PORTA_SENSOR 8 /*o pino de dados do sensor está ligado na porta 2 do Arduino*/

OneWire oneWire(PORTA_SENSOR);  /*Protocolo OneWire*/
DallasTemperature sensors(&oneWire); /*encaminha referências OneWire para o sensor*/


String formataDDMM() {
  char strDate[10];
  sprintf(strDate, "%02d/%02d", rtc.getDay(), rtc.getMonth());
  return strDate; 
}
String formataDDMMAAAA() {
  char strDate[10];
  sprintf( strDate, "%02d/%02d/%04d", rtc.getDay(), rtc.getMonth(), rtc.getYear() );
  return strDate; 
}
String formataTempertura() {
  char strC[10];
  sensors.requestTemperatures(); /* Envia o comando para leitura da temperatura */
  float temp = sensors.getTempCByIndex( 0 );
  dtostrf( (double)temp, 2, 1, strC );
  strC[2] = ',';
  strC[4] = 'c';
  strC[5] = 0;
  return strC ;
}
void chooseSensor() {
  if (false) {
    Serial.print(" Requerimento de temperatura..."); 
    Serial.println("Pronto");  /*Printa "Pronto" */
    /********************************************************************/
    Serial.print("A temperatura é: "); /* Printa "A temperatura é:" */
    Serial.print(formataTempertura()); /* Endereço do sensor */
 } else {
    lcd.setCursor(10, 1);
    lcd.print(formataTempertura());
 }
}

void chooseLcdDisplay() {
 if (false) {
    Serial.println(rtc.formatTime(RTCC_TIME_HM));
    Serial.println(formataDDMM()); 
    //Serial.println(rtc.formatDate(RTCC_DATE_WORLD)); 
  } else {
    lcd.setCursor(0, 0);
    lcd.print(formataDDMM());    
    lcd.setCursor(10, 0);
    lcd.print(rtc.formatTime(RTCC_TIME_HM));
    //lcd.print(rtc.formatDate(RTCC_DATE_WORLD));    
  }
}
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
  //Define o número de colunas e linhas do LCD
  Serial.begin(9600);  
  lcd.begin(16, 2);
  lcd.clear();
  sensors.begin(); /*inicia biblioteca*/
  sensors.setResolution(12);
}
 
void loop() {
  chooseLcdDisplay();
  chooseLed();
  chooseSensor();
  delay(1000);
  //searchSensor();  
}