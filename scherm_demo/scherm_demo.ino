#include <XPT2046_Touchscreen.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

#include "hardware.h"
#include "scherm.h"

Adafruit_ILI9341 tft = Adafruit_ILI9341(cs_tft, dc, mosi, sck, rst, miso);
XPT2046_Touchscreen ts(cs_ts, irq);

void setup() {
  // put your setup code here, to run once:
  pinMode(cs_tft, OUTPUT);
  pinMode(cs_ts, OUTPUT);
  pinMode(cs_sd, OUTPUT);
  pinMode(led, OUTPUT);
  digitalWrite(cs_tft, HIGH);
  digitalWrite(cs_ts, HIGH);
  digitalWrite(cs_sd, HIGH);
  
  digitalWrite(led, HIGH);

  SPI.setRX(miso);
  SPI.setTX(mosi);
  SPI.setSCK(sck);

  tft.begin();
  tft.setRotation(rotation);
  ts.begin();
  ts.setRotation(rotation);
  
  tft.fillScreen(tft.color565(0, 100, 0));

  tft.setCursor(40, 20);
  tft.setTextSize(2);
  tft.setTextColor(tft.color565(255, 255, 255));
  tft.println("Hallo wereld!");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (ts.tirqTouched()) {
    if (ts.touched()) {
      

      int x = touch_x();
      int y = touch_y();
      
      tft.fillCircle(x, y, 4, tft.color565(235, 235, 100));

      ts.begin();

    }
  }
  ts.begin();

}
