#pragma once
#include <Arduino.h>
#include "Config.h"

#if USE_STS3215
#include "SCServo.h"
#endif

class GateActuator {
public:
  void begin() {
#if USE_STS3215
    Serial1.begin(1000000);
    st.pSerial = &Serial1;
    moveTo(SERVO_HOME_POS);
#else
    Serial.println(F("GateActuator simulation mode enabled."));
#endif
  }

  void dispense() {
    for (int i = 0; i < DISPENSE_CYCLES; i++) {
      moveTo(SERVO_VEND_POS);
      delay(GATE_OPEN_MS);
      moveTo(SERVO_HOME_POS);
      delay(GATE_CLOSE_MS);
    }
  }

private:
#if USE_STS3215
  SMS_STS st;
#endif

  void moveTo(int pos) {
#if USE_STS3215
    byte ids[SERVO_COUNT];
    s16 positions[SERVO_COUNT];
    u16 speeds[SERVO_COUNT];
    byte accs[SERVO_COUNT];
    for (int i = 0; i < SERVO_COUNT; i++) {
      ids[i] = (byte)SERVO_IDS[i];
      positions[i] = (s16)pos;
      speeds[i] = (u16)SERVO_SPEED;
      accs[i] = (byte)SERVO_ACC;
    }
    st.SyncWritePosEx(ids, SERVO_COUNT, positions, speeds, accs);
#else
    Serial.print(F("[SIM] Servo gate position -> "));
    Serial.println(pos);
#endif
  }
};
