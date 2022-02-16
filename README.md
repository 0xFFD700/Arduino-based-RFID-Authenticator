## Arduino based RFID Authenticator

An Arduino based device that generates a password from the UID of your RFID card. You can set your computer's password to the generated string and automatically log in with the swipe of the RFID card.
</br>

#### Supplies:

   -  [Arduino Leonardo (needs to be HID compatible) ](https://www.arduino.cc/en/Main/Arduino_BoardLeonardo)
   -  [RFID-Modul](https://www.velleman.eu/products/view/?id=435568)
   - [LED](https://de.farnell.com/multicomp-pro/mp008247/led-rot-4mcd-629nm-5mm/dp/3796273?st=led)
   -  [220 Ohm Resistor](https://de.farnell.com/multicomp/mcmf01wjj0221a10/metal-film-resistor-220-ohm-1w/dp/1602003)
   -  [Jumper Wire (female-male and female-female)](https://www.amazon.de/Female-Female-Male-Female-Male-Male-Steckbr%C3%BCcken-Drahtbr%C3%BCcken-bunt/dp/B01EV70C78)

#### Electronic circuits:

![RFID-Auth](https://user-images.githubusercontent.com/19951276/154346148-277ce792-6b57-4db1-a37f-38227a610c7c.png)


| RFID Reader | Arduino |
| --- | --- |
| VCC | 3.3v |
| RST/Reset | RESET/ICSP-5 |
| SPI SS | Pin 10 |
| SPI MOSI | ICSP-4 |
| SPI MISO | ICSP-1 |
| SPI SCK | ICSP-3 |
| GND | GND |


| Led | Arduino |
| --- | --- |
| LED + | Pin 8 |
| LED - | GND |
