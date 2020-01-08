#include "SoftwareSerial.h"

SoftwareSerial bluetooth(2, 3); //TX, RX (do Bluetooth)
const int ledVermelho = 10;
const int ledVerde = 8;

void setup() {
  Serial.begin(38400);
  Serial.println(F("Type the AT commands:"));

  // Polarizacao invertida: 0(liga) / 1(desliga)
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledVerde, OUTPUT);

  digitalWrite(10, 1);
  digitalWrite(ledVerde,  1);
  //Initialize the software serial
  bluetooth.begin(38400);
}

void loop() {
  
  // Verifica se o monitor serial enviou dados
  if (Serial.available()) {
    char r = Serial.read(); // Lê o dado e salva em registrador
    bluetooth.print(r);  // Envia o dado recebido do serial para o Bluetooth
    Serial.print(r);  // Imprime o dado
  }
  
  // Verifica se bluetooth recebeu um dado
  if (bluetooth.available()) {
    char r = bluetooth.read(); // Lê o dado e salva em registrador
    Serial.print(r); //Imprime o dado recebido

    if(r=='0') {
      Serial.print("ACESSO NEGADO");
      digitalWrite(ledVermelho, 0);
      digitalWrite(ledVerde,  1);
    }
    else if(r=='1') {
      Serial.print("ACESSO PERMITIDO");
      digitalWrite(ledVermelho, 1);
      digitalWrite(ledVerde,  0);
    }
  }
}




