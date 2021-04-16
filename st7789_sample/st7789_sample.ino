#include "Arduino_ST7789_my.h"

#define TFT_DC 22   // ?
#define TFT_RST 21  // LCDのリセット用（SPI関係ない）
#define TFT_CS -1   // blank SS
#define TFT_MOSI 23 // SDA for hardware SPI data pin (all of available pins)
#define TFT_SCLK 18 // SCL for hardware SPI sclk pin (all of available pins)

Arduino_ST7789 tft = Arduino_ST7789(TFT_DC, TFT_RST, TFT_MOSI, TFT_SCLK, TFT_CS); //for display with CS pin


void setup()
{
    delay(1000);

    Serial.begin(115200);

    tft.init(135, 240);
    delay(1000);
    tft.fillScreen(GREEN);
    delay(1000);

    Serial.printf("size: %D %D\n", tft.width(), tft.height());
}


void loop()
{
    int i;
    tft.fillScreen(BLUE);
    delay(1000);
    for (i=0; i<10; i++) {
        tft.drawLine(10, (i * 20) + 20, 110, (i * 20) + 20, GREEN);
        tft.drawLine(10, (i * 20) + 30, 110, (i * 20) + 30, GREEN);
        tft.drawLine(10, (i * 20) + 20, 10, (i * 20) + 30, GREEN);
        tft.drawLine(110, (i * 20) + 20, 110, (i * 20) + 30, GREEN);
        delay(30);
    }
    delay(1000);
    for (i=0; i<10; i++) {
        tft.drawLine(10, (i * 20) + 20, 110, (i * 20) + 20, RED);
        tft.drawLine(10, (i * 20) + 30, 110, (i * 20) + 30, RED);
        tft.drawLine(10, (i * 20) + 20, 10, (i * 20) + 30, RED);
        tft.drawLine(110, (i * 20) + 20, 110, (i * 20) + 30, RED);
        
        delay(30);
    }
    delay(1000);
    tft.fillScreen(GREEN);
    delay(1000);
    tft.fillScreen(RED);
    delay(1000);
    tft.fillScreen(WHITE);
    delay(1000);
    tft.fillScreen(CYAN);
    delay(1000);
    tft.fillScreen(MAGENTA);
    delay(1000);
    
}
