# Mechanical brief

This repo uses a simple gravity-fed product column:

- Products stack vertically in a magazine.
- A servo arm blocks the bottom product in the home position.
- During dispense, the servo rotates to clear/push one product.
- The product slides down a low-friction ramp to the retrieval hole.

## Suggested materials

- PETG for servo arm, product holder, and slide/ramp.
- PLA is acceptable for non-stressed cosmetic frames.
- 2 mm clear acrylic for the front stock window.

## Design constraints

- Make the product holder replaceable instead of one-piece with the chassis.
- Add cable channels so wires cannot touch the servo arm.
- Add a manual access hatch for clearing jams.
- Tune gate clearance for exactly one XIAO-sized box/board per cycle.

## CAD placeholders

Add CAD/STL files here when you adapt the repo to your machine:

```text
hardware/cad/product_holder.step
hardware/cad/servo_arm.step
hardware/cad/base_chute.step
hardware/cad/acrylic_window.dxf
```
