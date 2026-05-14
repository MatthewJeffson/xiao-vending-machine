#pragma once

#ifndef USE_SIMULATED_CARD
#define USE_SIMULATED_CARD 1
#endif

#ifndef USE_STS3215
#define USE_STS3215 0
#endif

// Inventory
static const int DEFAULT_STOCK = 3;

// Token accepted by the starter firmware.
static const char PAID_TOKEN[] = "TRUE";

// Servo tuning. For STS3215-style 0..4095 servos, tune these for your gate.
static const int SERVO_HOME_POS = 1024;
static const int SERVO_VEND_POS = 0;
static const int SERVO_SPEED = 1500;
static const int SERVO_ACC = 50;
static const int SERVO_IDS[] = {1, 2};
static const int SERVO_COUNT = 2;
static const int DISPENSE_CYCLES = 1;
static const unsigned long GATE_OPEN_MS = 900;
static const unsigned long GATE_CLOSE_MS = 900;
static const unsigned long MESSAGE_MS = 1200;
