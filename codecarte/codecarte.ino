
#define EN 8   
#define Y_DIR 6   
#define Y_STEP 3 
#define Z_DIR 7  
#define Z_STEP 4
#define A_DIR 13 

const int pulseWidthMicros = 500;

#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

String CommandString = "";
String InputData = "";
bool IS_Data_Complete = false;
char carac;
unsigned char inchar;
unsigned char test;
int taille;
int emplacement;
int espacementpoint = 200;
int espacementcarac = 400;




void setup() {
  Serial.begin(9600);
  pinMode(22, OUTPUT);

  lcd.begin(16, 2);
  lcd.print("impression :");

  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);

  pinMode(Y_STEP, OUTPUT);
  pinMode(Y_DIR, OUTPUT);
  pinMode(Z_STEP, OUTPUT);
  pinMode(Z_DIR, OUTPUT);



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
    test = inchar;

  lcd.setCursor(0, 1);
  lcd.print("                ");

  int car8 = test%2;
  int car7 = test%4 >> 1;
  int car6 = test%8 >> 2;
  int car5 = test%16 >> 3;
  int car4 = test%32 >> 4;
  int car3 = test%64 >> 5;

  unsigned char cartout = test;
  unsigned char car1et2 = test / 64;
  
 
    switch (car1et2)
    {
      case 0b00:
        if (car3 == 1)
          {
            lcd.setCursor(0, 1);
            lcd.print("1");
            electro();
            MoteurY(100,true);
          }
        else
          { 
            lcd.setCursor(0, 1);
            lcd.print("0");
            MoteurY(100,true);
          }
        
        if (car4 == 1)
          {
            lcd.print("1");
            electro();
            MoteurY(100,true);
            MoteurX(100,true);
          }
        else
          {
            lcd.print("0");
            MoteurY(100,true);
            MoteurX(100,true);
          }
          
        if (car5 == 1)
          {
            lcd.print("1");
            electro();
            MoteurY(100,true);
          }
        else
          {
            lcd.print("0");
            MoteurY(100,true);
          }
          
        if (car6 == 1)
          {
            lcd.print("1");
            electro();
            MoteurY(100,true);
            MoteurX(100,true);
          }
        else
          {
            lcd.print("0");
            MoteurY(100,true);
            MoteurX(100,true);
          }
          
        if (car7 == 1)
          {
            lcd.print("1");
            electro();
            MoteurY(100,true);
          }
        else
          {
            lcd.print("0");
            MoteurY(100,true);
          }

        if (car8 == 1)
          {
            lcd.print("1");
            electro();
            MoteurY(200,true);
            MoteurX(300,true);
          }
        else
          {
            lcd.print("0");
            MoteurY(200,true);
            MoteurX(300,true);
          }
        break;
      
      case 0b10:
        switch (cartout)
        {
          case 0b10100010 :
            lcd.setCursor(0, 1);
            lcd.print("fini  ");
            Serial.println("fin");
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

    delay(300);
  }
}


void MoteurY(int step,bool  sens)
{
  if(sens)
  {
    digitalWrite(Y_DIR, HIGH);
  }
  else
  {
    digitalWrite(Y_DIR, LOW);
  }

  for (int i = 0;i <= step; i++)
  {
    digitalWrite(Y_STEP, HIGH);
    delay(1);
    digitalWrite(Y_STEP, LOW);
    delay(1);
  }
  
}

void MoteurX(int step,bool  sens)
{
  if(sens)
  {
    digitalWrite(Z_DIR, HIGH);
  } 
  else
  {
    digitalWrite(Z_DIR, LOW);
  }
  for (int i = 0;i <= step; i++)
  {
    digitalWrite(Z_STEP, HIGH);
    delay(1);
    digitalWrite(Z_STEP, LOW);
    delay(1);
  }
  
}
void electro()
{
  digitalWrite(22, HIGH);
  delay(20);
  digitalWrite(22, LOW);
}




