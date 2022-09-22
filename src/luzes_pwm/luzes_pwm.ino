
/*
  Fade

  This example shows how to fade an LED on pin 9 using the analogWrite()
  function.

  The analogWrite() function uses PWM, so if you want to change the pin you're
  using, be sure to use another PWM capable pin. On most Arduino, the PWM pins
  are identified with a "~" sign, like ~3, ~5, ~6, ~9, ~10 and ~11.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Fade
*/

int led = 11;
int AZUL = 8;
int VERMELHA = 9;
int BRANCA = 13;


// the setup routine runs once when you press reset:
void setup() {
  // declare pin 9 to be an output:
  pinMode(AZUL, OUTPUT);
  pinMode(VERMELHA, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(VERMELHA, HIGH);
}

// the loop routine runs over and over again forever:
void loop() {
  digitalWrite(VERMELHA, HIGH);
  digitalWrite(AZUL, LOW);
  for(int i=0; i<255; i++){
    analogWrite(led, i);
    delay(990);
    digitalWrite(BRANCA, HIGH);
    delay(10);
    digitalWrite(BRANCA, LOW);
    Serial.println(i);
  }
  digitalWrite(led, HIGH);
  digitalWrite(AZUL, HIGH);
  digitalWrite(VERMELHA, LOW);
  for(int i=255; i>0; i--){
    analogWrite(led, i);
    delay(990);
    digitalWrite(BRANCA, HIGH);
    delay(10);
    digitalWrite(BRANCA, LOW);
    Serial.println(i);
  }
  digitalWrite(led, LOW);
  delay(500);
}
