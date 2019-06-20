#include "SevSeg.h"
#include "pitches.h"
#include <unistd.h>
#define NO_SOUND 0

SevSeg sevseg; // Instancia um objeto crontroller do display de 7 segmentos
const int compasso   = 1500; // Altera o compasso da música 
const int buzzerPort = A5; // A porta utilizada para o buzzer
int playBuzzer       = 0;

/*
* Hino do Grêmio
*/
int melodiaTricolor[]    =    { NOTE_D5,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_D4,NO_SOUND,NOTE_D5,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_A4, NO_SOUND, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_DS5, NOTE_FS5,  NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_G4};
int tempoNotasTricolor[] = {       4,      6,     16,      4,     6,      16,      4,      2,       4,      4,      6,     16,      4,     6,      16,      2,        4,       6,      16,       4,        6,      16,        4,       6,       16,        4,        2,       6,      16,       4,       6,      16,       4,        6,     16,      2 };


/*
* Hino do Brasil
*/
int melodia[] = { NOTE_C4, NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_AS4, NOTE_B4,NOTE_C5,NOTE_F4,NOTE_C4, NOTE_F4,NOTE_E4,NOTE_G4,NOTE_F4,NOTE_A4,NOTE_G4,NOTE_AS4,NOTE_A4, NOTE_FS4,NOTE_G4,NO_SOUND,NO_SOUND,NOTE_C4, NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_AS4,NOTE_A4,NOTE_AS4,NOTE_B4, NOTE_CS5,NOTE_D5,NOTE_G4,NOTE_C4, NOTE_G4,NOTE_F4,NOTE_A4,NOTE_G4,NOTE_AS4,NOTE_A4,NOTE_B4,NOTE_AS4, NOTE_GS4,NOTE_A4,NO_SOUND,NOTE_A4,NOTE_A4, NOTE_AS4,NOTE_A4,NO_SOUND,NOTE_A4,NOTE_AS4,NOTE_A4, NOTE_A4,NOTE_D5,NOTE_C5,NOTE_AS4, NOTE_AS4,NOTE_A4,NOTE_A4,NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4, NOTE_E4,NOTE_D4,NO_SOUND,NOTE_G4,NOTE_G4, NOTE_A4,NOTE_G4,NO_SOUND,NOTE_G4,NOTE_A4,NOTE_G4, NOTE_G4,NOTE_C5,NOTE_B4,NOTE_A4, NOTE_A4,NOTE_G4,NOTE_G4,NOTE_F4,NOTE_F4,NOTE_E4,NOTE_E4,NOTE_D4, NOTE_D4,NOTE_C4,NO_SOUND,NOTE_C4,NOTE_E4,NOTE_G4, NOTE_AS4,NOTE_C4,NOTE_E4,NOTE_G4,NOTE_AS4,NOTE_C4,NOTE_E4,NOTE_G4, NOTE_AS4,NOTE_AS4,NOTE_C4, NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_AS4, NOTE_B4,NOTE_C5,NOTE_F4,NOTE_C4, NOTE_F4,NOTE_E4,NOTE_G4,NOTE_F4,NOTE_A4,NOTE_G4,NOTE_AS4,NOTE_A4, NOTE_FS4,NOTE_G4,NO_SOUND,NOTE_C4, NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_AS4,NOTE_A4,NOTE_AS4,NOTE_B4, NOTE_CS5,NOTE_D5,NOTE_G4,NOTE_C4, NOTE_G4,NOTE_FS4,NOTE_A4,NOTE_G4,NOTE_AS4,NOTE_A4,NOTE_C5,NOTE_AS4, NOTE_GS4,NOTE_A4,NO_SOUND,NO_SOUND,NOTE_F4, NOTE_G4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_F4, NOTE_F4,NOTE_AS4,NOTE_AS4,NO_SOUND,NOTE_G4, NOTE_A4,NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_FS4,NOTE_G4,NOTE_A4,NOTE_G4, NOTE_G4,NOTE_C5,NOTE_C5,NO_SOUND,NOTE_A4, NOTE_AS4,NOTE_A4,NOTE_GS4,NOTE_A4,NOTE_GS4,NOTE_A4,NOTE_AS4,NOTE_A4, NOTE_A4,NOTE_D5,NOTE_C5,NOTE_AS4,NOTE_G4, NOTE_G4,NOTE_F4,NO_SOUND,NOTE_E4,NOTE_F4,NOTE_G4, NOTE_AS4,NOTE_A4,NOTE_E4,NOTE_F4,NOTE_CS4,NOTE_D4,NOTE_AS4,NOTE_G4, NOTE_G4,NOTE_F4,NO_SOUND,NOTE_G4,NOTE_A4,NOTE_AS4, NOTE_B4,NOTE_C5,NOTE_A4,NOTE_F4,NOTE_D4,NOTE_AS4, NOTE_A4,NOTE_F4,NOTE_D4,NOTE_C4,NOTE_D4,NOTE_E4, NOTE_F4 };
int tempoNotas[] = { 4,6,16,6,16,6,16,6,16,3,8,4,4,6,16,6,16,6,16,6,16,4,4,4,16,8,6,16,6,16,6,16,6,16,3,8,4,4,6,16,6,16,6,16,6,16,4,4,4,6,16,4,4,8,8,6,16,4,2,8,8,8,8,8,8,8,8,8,8,4,4,4,6,16,4,4,8,8,6,16,4,2,8,8,8,8,8,8,8,8,8,8,4,4,8,8,8,8,8,8,8,8,8,8,8,8,2,4,4,6,16,6,16,6,16,6,16,3,8,4,4,6,16,6,16,6,16,6,16,4,4,4,4,6,16,6,16,6,16,6,16,3,8,4,4,6,16,6,16,6,16,6,16,4,4,4,8,16,6,16,6,16,6,16,6,16,3,8,4,8,8,6,16,6,16,6,16,6,16,3,8,4,8,8,6,16,6,16,6,16,6,16,4,3,8,8,8,4,4,8,8,8,8,8,8,8,8,8,8,8,8,4,4,8,8,8,8,8,8,8,8,4,4,4,6,16,4,6,16,2 };
// Duração das Notas: Colcheia:8; Semínima: 4; Mínima:2; Semibreve:1





void setup() {
  byte numDigits = 4; 
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
  
  playBuzzer = 0;      // 0 = não toca o buzzer | 1 = Hino do Imortal Tricolor | 2 = Hino do Brasil 
  Serial.begin(9600);  // opens serial port, sets data rate to 9600 bps
  
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
}



void loop(){
  static unsigned long timer = millis();
  static int deciSeconds = 0;

  if (millis() >= timer) {
    deciSeconds++; // 1000 milliSeconds is equal to 10 deciSecond
    timer += 1000; 
  
    if (deciSeconds == 10000) { // Reset to 0 after counting for 1000 seconds.
      deciSeconds=0;
    }

    // Aqui eu pretendo chamar 'atualizaPlacar', mas não chamei pra facilitar nos testes
    sevseg.setChars("3 2 ");

    // Verifica se a porta serial recebeu alguma informação para, então, saber qual dos hinos deve tocar.
    if (Serial.available() > 0) {
      playBuzzer = Serial.read() - 48; // Lê o byte recebido e diminui 48, que é 0 na tabela ASCII
      Serial.print("Valor recebido: ");
      Serial.println(playBuzzer);

      if (playBuzzer > 0) {
        if(playBuzzer == 2) {
          tocarHinoBrasileiro();
        } else {
          tocarHinoTricolor();
        }
      }
    }

  }  
 
  sevseg.refreshDisplay(); // Must run repeatedly
}



void atualizarPlacar() {
  
}


void tocarHinoTricolor() {
  for (int Nota = 0; Nota < 36; Nota++) {           // O número 36 indica quantas notas tem a nossa matriz.
    int tempo = compasso/tempoNotasTricolor[Nota];  // Tempo = compasso dividido pela indicação da matriz tempoNotas.
    tone(buzzerPort, melodiaTricolor[Nota],tempo);  // Toca a nota indicada pela matriz melodia durante o tempo.
    
    // Para distinguir as notas adicionamos um tempo entre elas (tempo da nota + 20%).
    delay(tempo*1.2);
  }
}


void tocarHinoBrasileiro() {
  for (int Nota = 0; Nota < 108; Nota++) {  // O número 230 indica quantas notas tem a nossa matriz (108 vai até antes de "Brasil de um sonho intenso...).
    int tempo = compasso/tempoNotas[Nota];  // Tempo = compasso dividido pela indicação da matriz tempoNotas.
    tone(buzzerPort, melodia[Nota],tempo);  // Toca a nota indicada pela matriz melodia durante o tempo.
    
    // Para distinguir as notas adicionamos um tempo entre elas (tempo da nota + 20%).
    delay(tempo*1.2);
  }
}

//Fim de Programa
