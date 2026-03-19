#include <Adafruit_NeoPixel.h>
#include <LiquidCrystal_I2C.h>

#define pin  38
#define num_pixel  1
#define pinA 41
#define pinB 2
#define pinC 42

LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_NeoPixel pixels(num_pixel, pin, NEO_RGB + NEO_KHZ800);

void setup() {
  lcd.setCursor(0, 0);
  lcd.backlight();
  lcd.init();
  pixels.begin();
  pixels.setBrightness(50);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
}

void loop() {
  for(long theFirdtPixel = 0; theFirdtPixel < 65536; theFirdtPixel += 256) {
    pixels.setPixelColor(0, pixels.gamma32(pixels.ColorHSV(theFirdtPixel)));
    pixels.show();
    lcd.print(String(theFirdtPixel));
    digitalWrite(pinA, HIGH);
    delay(50);
    digitalWrite(pinA, LOW);
    digitalWrite(pinB, HIGH);
    delay(50);
    digitalWrite(pinB, LOW);
    digitalWrite(pinC, HIGH);
    delay(50);
    digitalWrite(pinC, LOW);
    delay(10);
    lcd.clear();
  }
}