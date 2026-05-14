#include <Arduino.h>
#include "Config.h"
#include "DisplayUI.h"
#include "CardReader.h"
#include "GateActuator.h"

DisplayUI ui;
CardReader cards;
GateActuator gate;

int stock = DEFAULT_STOCK;

enum MachineState {
  BOOT,
  IDLE,
  CARD_READ,
  VALIDATE,
  REJECTED,
  SOLD_OUT,
  DISPENSE,
  COMPLETE
};

MachineState state = BOOT;
String currentToken;
unsigned long stateStarted = 0;

void transitionTo(MachineState next) {
  state = next;
  stateStarted = millis();
}

bool tokenIsValid(const String &token) {
  return token == String(PAID_TOKEN);
}

void setup() {
  Serial.begin(115200);
  delay(200);

  pinMode(WIO_KEY_C, INPUT_PULLUP);

  ui.begin();
  cards.begin();
  gate.begin();

  ui.showBoot();
  Serial.println(F("Wio Terminal Open Vending Machine booted."));
  transitionTo(IDLE);
  delay(1000);
  ui.showIdle(stock);
}

void loop() {
  if (digitalRead(WIO_KEY_C) == LOW) {
    delay(40);
    while (digitalRead(WIO_KEY_C) == LOW) delay(10);
    stock = DEFAULT_STOCK;
    ui.showManualRestock(stock);
    delay(MESSAGE_MS);
    ui.showIdle(stock);
    transitionTo(IDLE);
  }

  switch (state) {
    case BOOT:
      transitionTo(IDLE);
      break;

    case IDLE:
      if (cards.readToken(currentToken)) {
        ui.showReading();
        transitionTo(CARD_READ);
      }
      break;

    case CARD_READ:
      if (millis() - stateStarted > 350) {
        transitionTo(VALIDATE);
      }
      break;

    case VALIDATE:
      if (!tokenIsValid(currentToken)) {
        ui.showRejected();
        transitionTo(REJECTED);
      } else if (stock <= 0) {
        ui.showSoldOut();
        transitionTo(SOLD_OUT);
      } else {
        ui.showDispensing();
        transitionTo(DISPENSE);
      }
      break;

    case DISPENSE:
      gate.dispense();
      stock--;
      ui.showComplete(stock);
      transitionTo(COMPLETE);
      break;

    case COMPLETE:
    case REJECTED:
    case SOLD_OUT:
      if (millis() - stateStarted > MESSAGE_MS) {
        ui.showIdle(stock);
        transitionTo(IDLE);
      }
      break;
  }
}
