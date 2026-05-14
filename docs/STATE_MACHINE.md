# Vending state machine

```text
BOOT -> IDLE -> CARD_READ -> VALIDATE -> DISPENSE -> COMPLETE -> IDLE
                         \-> REJECTED -> IDLE
                         \-> SOLD_OUT -> IDLE
```

## States

- `BOOT`: LCD and serial setup.
- `IDLE`: waits for a token/card.
- `CARD_READ`: captures simulated or real token payload.
- `VALIDATE`: accepts only `TRUE` in this starter firmware.
- `DISPENSE`: opens and closes the servo gate.
- `COMPLETE`: decrements stock and confirms success.
- `REJECTED`: invalid token or unpaid card.
- `SOLD_OUT`: valid token but no remaining inventory.

## Safety assumptions

- Servo power is external.
- Wio Terminal and servo power supply share ground.
- The physical gate is tested manually before powered tests.
- Stock count is software-only until a physical sensor is added.
