
#define BETWEEN 2579
#define DURATION 43
#define TIMES 7
// 3, 5, 6, 9, 10, 11
#define BRANCA_FRIA_0 11
#define BRANCA_FRIA_1 10
#define BRANCA_10k 9
#define AMARELA 6
#define AZUL 5
#define VERMELHA 3
long TEMPO_OCASO = ( 12 * 60000 );   // minutos
int TEMPO_PWM  = ( TEMPO_OCASO / 12 );

void setup() {
  configura();
  apaga_todas();
  //TEMPO_PWM = 1000;
  //amanhecer();
  acende_todas();
  delay( 60000 );
  ocaso();
  apaga_todas();
  delay( 60000 );
  Serial.begin(9600);
}
void loop() {
}
void relampago() {
  int flashCount = random (1, 25);        // Min. and max. number of flashes each loop
  int flashBrightnessMin =  1;           // LED flash min. brightness (0-255)
  int flashBrightnessMax =  255;          // LED flash max. brightness (0-255)

  int flashDurationMin = 1;               // Min. duration of each seperate flash
  int flashDurationMax = 150;              // Max. duration of each seperate flash

  int nextFlashDelayMin = 1;              // Min, delay between each flash and the next
  int nextFlashDelayMax = 150;            // Max, delay between each flash and the next

  for ( int flash = 0 ; flash <= flashCount; flash += 1 ) { // Flashing LED strip in a loop, random count
    ajusta_brilho( random ( flashBrightnessMin, flashBrightnessMax ) ); // Turn LED strip on, random brightness
    delay( random( flashDurationMin, flashDurationMax ) ); // Keep it tured on, random duration

    apaga_todas();

    delay( random( nextFlashDelayMin, nextFlashDelayMax) ); // Random delay before next flash
  }
}
void piscar() {
  for ( int i = 0; i < 5; i++ ) {
    apaga_todas();
    delay( 100 );
    acende_todas();
    delay( 100 );
  }
}
void amanhecer() {
  Serial.println( "############  Amanhecer" );
  for ( int i = 1; i < 255; i++ ) {
    ajusta_brilho( i );
    Serial.print( "Valor:" );
    Serial.println( i );
    delay( TEMPO_PWM );
  }
  acende_todas();
}
void ocaso() {
  Serial.println( "############  Ocaso" );
  for ( int i = 255; i > 0; i-- ) {
    ajusta_brilho( i );
    Serial.print( "Valor:" );
    Serial.println( i );
    delay( TEMPO_PWM );
  }
  apaga_todas();
}
void configura() {
  pinMode(BRANCA_FRIA_0 , OUTPUT);
  pinMode(BRANCA_FRIA_1 , OUTPUT);
  pinMode(BRANCA_10k , OUTPUT);
  pinMode(AMARELA , OUTPUT);
  pinMode(AZUL, OUTPUT);
  pinMode(VERMELHA, OUTPUT);
}
void apaga_todas() {
  digitalWrite(BRANCA_FRIA_0, LOW);
  digitalWrite(BRANCA_FRIA_1, LOW);
  digitalWrite(BRANCA_10k, LOW);
  digitalWrite(AMARELA, LOW);
  digitalWrite(AZUL, LOW);
  digitalWrite(VERMELHA, LOW);
}
void apaga_frias() {
  digitalWrite(BRANCA_FRIA_0, LOW);
  digitalWrite(BRANCA_FRIA_1, LOW);
  digitalWrite(BRANCA_10k, LOW);
  digitalWrite(AZUL, LOW);
}
void acende_todas() {
  digitalWrite(BRANCA_FRIA_0, HIGH);
  digitalWrite(BRANCA_FRIA_1, HIGH);
  digitalWrite(BRANCA_10k, HIGH);
  digitalWrite(AMARELA, HIGH);
  digitalWrite(AZUL, HIGH);
  digitalWrite(VERMELHA, HIGH);
}
void acende_frias() {
  digitalWrite(BRANCA_FRIA_0, HIGH);
  digitalWrite(BRANCA_FRIA_1, HIGH);
  digitalWrite(BRANCA_10k, HIGH);
  digitalWrite(AZUL, HIGH);
}
void ajusta_brilho(int brilho) {
  analogWrite(BRANCA_FRIA_0, brilho);
  analogWrite(BRANCA_FRIA_1, brilho);
  analogWrite(BRANCA_10k, brilho);
  analogWrite(AMARELA, brilho);
  analogWrite(AZUL, brilho);
  analogWrite(VERMELHA, brilho);
}
