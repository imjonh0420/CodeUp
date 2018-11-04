/*
  columns
  (1,1)-13
  (1,2)-12
  (1,3)-11
  (1,4)-10
  (2,1)-9
  (2,2)-8
  (2,3)-7
  (2,4)-6
  (3,1)-5
  (3-2)-4
  (3-3)-3
  (3,4)-2
  (4,1)-1
  (4,2)-0
  (4,3)-A5
  (4,4)-A4
  Layers
  layer1-A0
  layer2-A1
  layer3-A2
  layer4-A3
*/

#include "pinSetting.h"
int time = 250;

void setup() {
  //setting columnss
  for(int i = 0; i<16; i++)
  {
    pinMode(columns[i], OUTPUT);
  }
  //setting layers
  for(int i = 0; i<4; i++)
  {
    pinMode(layer[i], OUTPUT);
  }
}

void loop() {
  turnOffAll();
  turnOnAll();
  delay(time);
  turnOffAll();
  flickerOn();
  turnOffAll();
  flickerOff();
  turnOffAll();
  delay(time);
  diagonalRectangle();
  turnOffAll();
  delay(time);
  propeller();
  turnOffAll();
  delay(time);
}


void turnOffAll() {
  for(int i = 0; i<16; i++)
   {
     digitalWrite(columns[i], HIGH);
   }
   for(int i = 0; i<4; i++)
   {
     digitalWrite(layer[i], LOW);
   }
}

void turnOnAll()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(columns[i], LOW);
  }
  //turning on layers
  for(int i = 0; i<4; i++)
  {
    digitalWrite(layer[i], HIGH);
  }
}

void turncolumnssOff()
{
  for(int i = 0; i<16; i++)
  {
    digitalWrite(columns[i], HIGH);
  }
}

void flickerOn()
{
  int i = 150;
  while(i != 0)
  {
    turnOnAll();
    delay(i);
    turnOffAll();
    delay(i);
    i-= 5;
  }
}

void flickerOff()
{
  turnOnAll();
  for(int i = 0; i!= 150; i+=5)
  {
    turnOffAll();
    delay(i+50);
    turnOnAll();
    delay(i);
  }
}

void diagonalRectangle()
{
  int x = 350;
  turnOffAll();
  for(int count = 0; count<5; count++)
  {
    //top left
    for(int i = 0; i<8; i++)
    {
      digitalWrite(columns[i], LOW);
    }
    digitalWrite(layer[3], HIGH);
    digitalWrite(layer[2], HIGH);
    delay(x);
    turnOffAll();
    //middle middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(columns[i], LOW);
    }
    digitalWrite(layer[1], HIGH);
    digitalWrite(layer[2], HIGH);
    delay(x);
    turnOffAll();
    //bottom right
    for(int i = 8; i<16; i++)
    {
      digitalWrite(columns[i], LOW);
    }
    digitalWrite(layer[0], HIGH);
    digitalWrite(layer[1], HIGH);
    delay(x);
    turnOffAll();
    //bottom middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(columns[i], LOW);
    }
    digitalWrite(layer[0], HIGH);
    digitalWrite(layer[1], HIGH);
    delay(x);
    turnOffAll();
    //bottom left
    for(int i = 0; i<8; i++)
    {
      digitalWrite(columns[i], LOW);
    }
    digitalWrite(layer[0], HIGH);
    digitalWrite(layer[1], HIGH);
    delay(x);
    turnOffAll();
    //middle middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(columns[i], LOW);
    }
    digitalWrite(layer[1], HIGH);
    digitalWrite(layer[2], HIGH);
    delay(x);
    turnOffAll();
    //top right
    for(int i = 8; i<16; i++)
    {
      digitalWrite(columns[i], LOW);
    }
    digitalWrite(layer[2], HIGH);
    digitalWrite(layer[3], HIGH);
    delay(x);
    turnOffAll();
    //top middle
    for(int i = 4; i<12; i++)
    {
      digitalWrite(columns[i], LOW);
    }
    digitalWrite(layer[2], HIGH);
    digitalWrite(layer[3], HIGH);
    delay(x);
    turnOffAll();
  }
  //top left
  for(int i = 0; i<8; i++)
  {
    digitalWrite(columns[i], LOW);
  }
  digitalWrite(layer[3], HIGH);
  digitalWrite(layer[2], HIGH);
  delay(x);
  turnOffAll();
}

void propeller()
{
  turnOffAll();
  int x = 90;
  for(int y = 4; y>0; y--)
  {
    for(int i = 0; i<6; i++)
    {
      digitalWrite(layer[y-1], HIGH);
      
      turncolumnssOff();
      digitalWrite(columns[0], LOW);
      digitalWrite(columns[5], LOW);
      digitalWrite(columns[10], LOW);
      digitalWrite(columns[15], LOW);
      delay(x);
      
      turncolumnssOff();
      digitalWrite(columns[4], LOW);
      digitalWrite(columns[5], LOW);
      digitalWrite(columns[10], LOW);
      digitalWrite(columns[11], LOW);
      delay(x);
      
      turncolumnssOff();
      digitalWrite(columns[6], LOW);
      digitalWrite(columns[7], LOW);
      digitalWrite(columns[8], LOW);
      digitalWrite(columns[9], LOW);
      delay(x);
      
      turncolumnssOff();
      digitalWrite(columns[3], LOW);
      digitalWrite(columns[6], LOW);
      digitalWrite(columns[9], LOW);
      digitalWrite(columns[12], LOW);
      delay(x);
      
      turncolumnssOff();
      digitalWrite(columns[2], LOW);
      digitalWrite(columns[6], LOW);
      digitalWrite(columns[9], LOW);
      digitalWrite(columns[13], LOW);
      delay(x);
      
      turncolumnssOff();
      digitalWrite(columns[1], LOW);
      digitalWrite(columns[5], LOW);
      digitalWrite(columns[10], LOW);
      digitalWrite(columns[14], LOW);
      delay(x);
    }
  }
  
  turncolumnssOff();
  digitalWrite(columns[0], LOW);
  digitalWrite(columns[5], LOW);
  digitalWrite(columns[10], LOW);
  digitalWrite(columns[15], LOW);
  delay(x);
}

void turnAround() {
  turnOffAll();
  digitalWrite(columns[5], HIGH);
  digitalWrite(columns[6], HIGH);
  digitalWrite(columns[9], HIGH);
  digitalWrite(columns[10], HIGH);

  
}

diagonalRectangle_my(){
  turnOn_led(1, 4, 2, 4, 2);
  blockShift(1, 0, -1);
  blockShift(1, 0, -1);
  blockShift(-1, 0, 0);
  blockShift(-1, 0, 0);
  blockShift(1, 0, 1);
  blockShift(1, 0, 1);
  blockShift(-1, 0, 0);
  blockShift(-1, 0, 0);
}
