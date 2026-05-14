#pragma once
#include <Arduino.h>
#include "Config.h"

class CardReader {
public:
  void begin() {
    pinMode(WIO_KEY_A, INPUT_PULLUP);
    pinMode(WIO_KEY_B, INPUT_PULLUP);
  }

  // Returns true when a token has been read into outToken.
  bool readToken(String &outToken) {
#if USE_SIMULATED_CARD
    if (digitalRead(WIO_KEY_A) == LOW) {
      debounce();
      outToken = PAID_TOKEN;
      Serial.println(F("Simulated paid token: TRUE"));
      return true;
    }
    if (digitalRead(WIO_KEY_B) == LOW) {
      debounce();
      outToken = "FALSE";
      Serial.println(F("Simulated invalid token: FALSE"));
      return true;
    }
    return false;
#else
    // Hook your open-source RFID driver here.
    // Expected behavior: read the agreed block/payload and return it as a String.
    // Example: outToken = readMifareBlock4(); return true;
    (void)outToken;
    return false;
#endif
  }

private:
  void debounce() {
    delay(40);
    while (digitalRead(WIO_KEY_A) == LOW || digitalRead(WIO_KEY_B) == LOW) {
      delay(10);
    }
  }
};
