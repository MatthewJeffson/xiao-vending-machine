# Demo Video Script

Use this script to record an original open-source demo video for the repo.

## Shot list

1. **Hero shot** - show the complete machine, Wio Terminal, RFID tap point, and product window.
2. **Boot screen** - power on Wio Terminal and show stock count.
3. **Simulation mode** - press Button A to simulate a valid paid card.
4. **Dispense action** - close-up of the servo gate releasing one product.
5. **Invalid token** - press Button B and show the rejection screen.
6. **Restock** - press Button C and show stock reset.
7. **Open build shot** - remove panel and show wiring: Wio Terminal, RFID, servo adapter, power supply.
8. **Mechanical close-up** - show the L-shaped servo arm and product holder.

## Voiceover outline

- This is an MIT-licensed Wio Terminal vending-machine starter project.
- The Wio Terminal handles the LCD UI and vending state machine.
- The default firmware runs without external hardware using the three front buttons.
- In the real build, RFID validation replaces the simulated card reader.
- The servo gate is tuned so one product drops per transaction.
- Mechanical reliability comes from PETG parts, clearance tuning, and a smooth chute.

## Acceptance criteria

A successful demo shows:

- Valid token -> one item dispensed -> stock decremented.
- Invalid token -> no movement.
- Empty stock -> no dispensing.
- Restock action works.
