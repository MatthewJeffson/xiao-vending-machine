#pragma once
#include <Arduino.h>
#include <TFT_eSPI.h>

class DisplayUI {
public:
  void begin() {
    tft.begin();
    tft.setRotation(3);
    tft.fillScreen(TFT_BLACK);
    tft.setTextDatum(TL_DATUM);
  }

  void showBoot() {
    drawHeader("OPEN VEND");
    drawLine(50, "Wio Terminal vending machine");
    drawLine(80, "MIT open-source starter");
    drawLine(125, "A: paid token");
    drawLine(150, "B: invalid token");
    drawLine(175, "C: restock");
  }

  void showIdle(int stock) {
    drawHeader("READY");
    drawLine(55, "Tap card or press A");
    drawStock(stock);
  }

  void showReading() {
    drawHeader("READING");
    drawLine(80, "Checking payment token...");
  }

  void showRejected() {
    drawHeader("REJECTED");
    drawLine(80, "Invalid or unpaid token.");
  }

  void showSoldOut() {
    drawHeader("SOLD OUT");
    drawLine(80, "Please restock machine.");
  }

  void showDispensing() {
    drawHeader("DISPENSING");
    drawLine(80, "Opening product gate...");
  }

  void showComplete(int stock) {
    drawHeader("COMPLETE");
    drawLine(70, "Please collect your product.");
    drawStock(stock);
  }

  void showManualRestock(int stock) {
    drawHeader("RESTOCKED");
    drawLine(70, "Stock reset for demo.");
    drawStock(stock);
  }

private:
  TFT_eSPI tft;

  void drawHeader(const char *title) {
    tft.fillScreen(TFT_BLACK);
    tft.fillRect(0, 0, 320, 38, TFT_DARKGREY);
    tft.setTextColor(TFT_WHITE, TFT_DARKGREY);
    tft.setTextSize(2);
    tft.drawString(title, 12, 10);
  }

  void drawLine(int y, const char *text) {
    tft.setTextColor(TFT_WHITE, TFT_BLACK);
    tft.setTextSize(2);
    tft.drawString(text, 12, y);
  }

  void drawStock(int stock) {
    tft.setTextColor(TFT_GREEN, TFT_BLACK);
    tft.setTextSize(3);
    tft.drawString("Stock: " + String(stock), 12, 130);
  }
};
