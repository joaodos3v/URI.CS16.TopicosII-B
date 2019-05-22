#include "pitches.h"
#define NO_SOUND 0

int melodia[] =    { NOTE_D5,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_A4,NOTE_D4,NO_SOUND,NOTE_D5,NOTE_B4,NOTE_A4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_A4, NO_SOUND, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_CS5, NOTE_D5, NOTE_DS5, NOTE_D5, NOTE_DS5, NOTE_FS5,  NOTE_E5, NOTE_B4, NOTE_C5, NOTE_D5, NOTE_E5, NOTE_D5, NOTE_A4, NOTE_C5, NOTE_B4, NOTE_G4};
int tempoNotas[] = {       4,      6,     16,      4,     6,      16,      4,      2,       4,      4,      6,     16,      4,     6,      16,      2,        4,       6,      16,       4,        6,      16,        4,       6,       16,        4,        2,       6,      16,       4,       6,      16,       4,        6,     16,      2 };
// Duração das Notas: Colcheia:8; Semínima: 4; Mínima:2; Semibreve:1


const int compasso = 1500; // Altera o compasso da música 

void setup() {
  for (int Nota = 0; Nota < 36; Nota++) {//o número 80 indica quantas notas tem a nossa matriz.
    int tempo = compasso/tempoNotas[Nota]; //Tempo = compasso dividido pela indicação da matriz tempoNotas.
    tone(2, melodia[Nota],tempo); //Toca a nota indicada pela matriz melodia durante o tempo.
    // Para distinguir as notas adicionamos um tempo entre elas (tempo da nota + 20%).
    delay(tempo*1.2);
  }
}
void loop(){
  //Não é necessária a repetição pois a mesma será feita pelo botão Reset.
}
