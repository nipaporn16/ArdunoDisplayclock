#include <Arduino.h>
#include <Wire.h>              //for ESP8266 use bug free i2c driver https://github.com/enjoyneering/ESP8266-I2C-Driver
#include <LiquidCrystal_I2C.h>


// CODE EDITED BY MANOJ DREXLER 
// 12 - 1 - 2022
#define COLUMS 16
#define ROWS   2

#define PAGE   ((COLUMS) * (ROWS))

LiquidCrystal_I2C lcd(PCF8574_ADDR_A21_A11_A01, 4, 5, 6, 16, 11, 12, 13, 14, POSITIVE);

//PLEASE CHANGE VALUES BEFORE UPLOAD 
// THIS CODE WILL WORK WITH OR WITH OUT THE PUSH BUTTON 


int h=10; //current hour in 12 hour format
int m = 59; //current minute 
int s = 55; //current second 
int flag = 23;  // current hour in 24 hour format
int TIME;

const int hs=8;
const int ms=9;

int state1;
int state2;

void setup()
{
  lcd.begin(PAGE);
  pinMode(hs,INPUT_PULLUP);
  pinMode(ms,INPUT_PULLUP);
}

void loop()
{

 lcd.setCursor(0,0);
 s=s+1;
 lcd.print("TIME:");
 lcd.print(h);
 lcd.print(":");
 lcd.print(m);
 lcd.print(":");
 lcd.print(s);



 if(flag<12)lcd.print("AM");
 if(flag==12)lcd.print("PM");
 if(flag>12)lcd.print("PM");
 if(flag==24)flag=0;



 delay(1000);
 lcd.clear();
 if(s==60){
  s=0;
  m=m+1;
 }
 if(m==60)
 {
  m=0;
  h=h+1;
  flag=flag+1;
 }
 if(h==13)
 {
  h=1;
 }
 lcd.setCursor(0,1);

 //lcd.print("HAVE A NICE DAY");

 //-------Time
// setting-------//
 state1=digitalRead(hs);

 if(state1==0)
{
  h=h+1;
  flag=flag+1;
  if(flag<12)lcd.print("AM");
  if(flag==12)lcd.print("PM");
  if(flag>12)lcd.print("PM");
  if(flag==24)flag=0;
  if(h==13)h=1;
}
state2=digitalRead(ms);
if(state2==0){
  s=0;
  m=m+1;
}

  
}