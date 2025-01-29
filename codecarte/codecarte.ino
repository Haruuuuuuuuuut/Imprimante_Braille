#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int LEDPIN = 13;
String CommandString = "";
String InputData = "";
bool IS_Data_Complete = false;
char carac;
unsigned char inchar;
int taille;
int emplacement;



void setup() {
  pinMode(LEDPIN, OUTPUT);
  Serial.begin(9600);

  lcd.begin(16, 2);
  lcd.print("impression :");


}

void loop() {
  Serial_Data_Events();
  

}

void Serial_Data_Events()
{

  while (Serial.available())
  {
    Serial.flush();

    inchar = (unsigned char)Serial.read();

  lcd.setCursor(0, 1);
  lcd.print("                ");

  int car8 = inchar%2;
  int car7 = inchar%4 >> 1;
  int car6 = inchar%8 >> 2;
  int car5 = inchar%16 >> 3;
  int car4 = inchar%32 >> 4;
  int car3 = inchar%64 >> 5;

  unsigned char cartout = inchar;
  unsigned char car1et2 = inchar / 64;
  

    switch (car1et2)
    {
      case 0b00:
        
        if (car3 == 1)
          {
            lcd.setCursor(0, 1);
            lcd.print("1");
          }
        else
          {
            lcd.setCursor(0, 1);
            lcd.print("0");
          }
        
        if (car4 == 1)
          {
            lcd.print("1");
          }
        else
          {
            lcd.print("0");
          }
          
        if (car5 == 1)
          {
            lcd.print("1");
          }
        else
          {
            lcd.print("0");
          }
          
        if (car6 == 1)
          {
            lcd.print("1");
          }
        else
          {
            lcd.print("0");
          }
          
        if (car7 == 1)
          {
            lcd.print("1");
          }
        else
          {
            lcd.print("0");
          }

        if (car8 == 1)
          {
            lcd.print("1");
          }
        else
          {
            lcd.print("0");
          }
        break;

      case 0b10:
        switch (cartout)
        {
          case 0b10100010 :
            lcd.setCursor(0, 1);
            lcd.print("fini  ");
            break;
          
          case 0b10100100 :
            lcd.setCursor(0, 1);
            lcd.print("saut de ligne");
        }


          
        break;

      default:
      InputData += inchar;
      lcd.setCursor(0, 1);
      lcd.print("valeur indéfinie");



    }

    delay(1000);
  }
}






