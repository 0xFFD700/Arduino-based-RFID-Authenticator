#include <Keyboard.h>
#include <KeyboardLayout.h>
#include <SPI.h>
#include <RFID.h>
#include <SoftwareSerial.h>

#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN, RST_PIN);

int led = 3;
int serNum[5];

String RfidString = "";

void setup() {

  Serial.begin(9600);
  SPI.begin();
  rfid.init();

  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);

  Keyboard.begin();

}

void loop() {

  if (rfid.isCard()) {

    if (rfid.readCardSerial()) {

      Serial.print(rfid.serNum[0] + "");
      Serial.print(rfid.serNum[1] + "");
      Serial.print(rfid.serNum[2] + "");
      Serial.print(rfid.serNum[3] + "");
      Serial.print(rfid.serNum[4] + "");
      Serial.println("");

      RfidString = rfid.serNum;

      Serial.println(RfidString);

      blinkLed();

      Keyboard.println("3141"); key = "";
        

    }
  }

  rfid.halt();

}

void blinkLed() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, HIGH);
}

void hashRfid() {
}

void writePassword() {
  Keyboard.println("3141"); key = "";
}
