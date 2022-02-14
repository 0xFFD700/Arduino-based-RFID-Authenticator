#include <SPI.h>
#include <Keyboard.h>
#include <MFRC522.h>

// Constants
#define RST_PIN 9
#define SS_PIN 10
#define LED_PIN 8

// Variables
String RFIDUID;

// Create MFRC522 instance
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);

  // Init SPI and MFRC522
  while (!Serial);
  SPI.begin();
  mfrc522.PCD_Init();
  delay(4);
}

void readRFID(byte *buffer, byte bufferSize)
{
  RFIDUID = "";
  for (byte i = 0; i < bufferSize; i++)
  {
    RFIDUID = RFIDUID + String(buffer[i], HEX);
  }
}

void writePass() 
{
  Keyboard.print("test");
  Keyboard.releaseAll();
  delay(100);
  Keyboard.press(KEY_RETURN);
  Keyboard.releaseAll();
  delay(1000);
}

void loop() 
{
  // Reset the loop if no new card present on the sensor/reader. This saves the entire process when idle.
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }

  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }

  readRFID(mfrc522.uid.uidByte, mfrc522.uid.size);
  writePass();
}
