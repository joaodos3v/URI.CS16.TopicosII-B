#include "SevSeg.h"

SevSeg sevseg; //Instantiate a seven segment controller object

void setup() {
  byte numDigits = 4; 
  byte digitPins[] = {10, 11, 12, 13};
  byte segmentPins[] = {2, 3, 4, 5, 6, 7, 8, 9};
  
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins); 
  // If your display is common anode type, please edit comment above line and uncomment below line
  // sevseg.begin(COMMON_ANODE, numDigits, digitPins, segmentPins);
  sevseg.setBrightness(90);
}

void loop() {
  static unsigned long timer = millis();
  static int deciSeconds = 0;

  if (millis() >= timer) {
    deciSeconds++; // 1000 milliSeconds is equal to 10 deciSecond
    timer += 1000; 
  
    if (deciSeconds == 10000) { // Reset to 0 after counting for 1000 seconds.
      deciSeconds=0;
    }
    
    // sevseg.setNumber(deciSeconds, 1);
    sevseg.setChars("1  5");
  }
 
  sevseg.refreshDisplay(); // Must run repeatedly
}
