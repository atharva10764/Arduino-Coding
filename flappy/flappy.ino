#include<LiquidCrystal.h>
LiquidCrystal lcd (8,7,6,5,4,3); //RS, E, D4, D5, D6, D7
int ledPin = 13;
int buttonPin = 2;


int ledToggle;
int previousState = HIGH;
unsigned int previousPress;
volatile int buttonFlag;
int buttonDebounce = 20;
int i=0;
int pos=0;
int Speed=100;
String typea    = "                      ##          ####        ##          ###      ####       ########       #####       ##########             ";  
String typeaa   = "                 ##        ####           ##        ####        ##         ##            ###         ###                        ";

                                    
                
int  typeA[]    = {22,23,34,35,36,37,46,47,58,59,60,67,68,69,70,78,79,80,81,82,83,84,85,93,94,95,96,97,105,106,107,108,109,110,111,112,113,114};//38
int typeAA[]    = {17,18,26,27,28,29,41,42,51,52,53,54,62,63,73,74,87,88,89,99,100,101};//22


void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
  lcd.begin(16,2);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), button_ISR, CHANGE);
  while(ledToggle==0)
  {
    lcd.clear();
    delay(500);
    lcd.print("   START GAME   ");
    delay(500);
  }
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print('@');
  //lcd.print(bala.substring(1,3));
}
void loop() {
  // put your main code here, to run repeatedly:
while(1)
 {
   for(i=0;i<114;i++)//
   {
    if(pos==0)
    {
      lcd.setCursor(1,0);
      lcd.print(typea.substring(i+1,16+i));
    }
    else
    {
      lcd.setCursor(0,0);
      lcd.print(typea.substring(i,16+i));
    }

    
    if(pos==1)
    {
      lcd.setCursor(1,1);
      lcd.print(typeaa.substring(i+1,16+i));
    }
    else
    {
      lcd.setCursor(0,1);
      lcd.print(typeaa.substring(i,16+i));
    }
    
   
    
    for(int j=0;j<38;j++)
    {
      if(typeA[j]==i)
      {
        if(pos==0)
        {
          gameover();
        }
      }
    }
    for(int j=0;j<22;j++)
    {
      if(typeAA[j]==i)
      {
        if(pos==1)
        {
          gameover();
        }
      }
    }
    delay(Speed);
  }
   winner();
 }
}





void gameover (void)
{
  detachInterrupt(digitalPinToInterrupt(2));
  while(1)
  {
    lcd.clear();
    delay(500);
    lcd.print("    GAME OVER   ");
    delay(500);
  }
}
void winner (void)
{
  detachInterrupt(digitalPinToInterrupt(2));
  while(1)
  {
    lcd.clear();
    delay(500);
    lcd.print(" WINNER! WINNER!");
    lcd.setCursor(0,1);
    lcd.print(" CHICKEN DINNER ");
    delay(500);
  }
}
void button_ISR()
{
   buttonFlag = 1;
   if((millis() - previousPress) > buttonDebounce && buttonFlag)
  {
    previousPress = millis();
    if(digitalRead(buttonPin) == LOW && previousState == HIGH)
    {
      ledToggle =! ledToggle;
      digitalWrite(ledPin, ledToggle);
      previousState = LOW;
      if(ledToggle)
      {
       lcd.setCursor(0,0);
       lcd.print('@');
       lcd.setCursor(0,1);
       lcd.print(' ');
       pos=0;
      }
      else
      {
       lcd.setCursor(0,1);
       lcd.print('@');
       lcd.setCursor(0,0);
       lcd.print(' ');
       pos=1;
      }

    }
    
    else if(digitalRead(buttonPin) == HIGH && previousState == LOW)
    {
      previousState = HIGH;
    }
    buttonFlag = 0;
  }
}
