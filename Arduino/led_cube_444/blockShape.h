#include "ctrl_ledBlock.h"

void flickerOn(){   // 켜진 시간과 꺼진 시간이 같은 깜빡임을 점점 빠르게 반복하는 깜빡이.
  
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

void flickerOff(){    // 잠깐 켜지는걸 점점 느리게 반복하는 깜빡이
  
  turnOnAll();
  for(int i = 0; i != 150; i+=5)
  {
    turnOffAll();
    delay(i+50);
    turnOnAll();
    delay(i);
  }
}

void diagonalRectangle(){   // 2*4 모양의 직사각형이 튕기면서 움직임.
  
  turnOn_led(1, 4, 2, 4, 2);
  delay(350);
  turnOn_led(2, 3, 2, 4, 2);
  delay(350);
  turnOn_led(3, 2, 2, 4, 2);
  delay(350);
  turnOn_led(2, 2, 2, 4, 2);
  delay(350);
  turnOn_led(1, 2, 2, 4, 2);
  delay(350);
  turnOn_led(2, 3, 2, 4, 2);
  delay(350);
  turnOn_led(3, 4, 2, 4, 2);
  delay(350);
  turnOn_led(2, 4, 2, 4, 2);
  delay(350);
}

void propeller(){   //프로펠러 모양으로 점점 층수가 낮아지며 돌아감.    // 8*8*8 큐브에서도 동작할 수 있도록 더 범용성 높은 코드를 구현해야 함.
  turnOffAll();
  int x = 90;
  for(int y = 4; y>0; y--){
    for(int i = 0; i<6; i++){
      digitalWrite(layer[y-1], HIGH);
      
      turnColumnsOff();
      digitalWrite(columns[0], LOW);
      digitalWrite(columns[5], LOW);
      digitalWrite(columns[10], LOW);
      digitalWrite(columns[15], LOW);
      delay(x);
      
      turnColumnsOff();
      digitalWrite(columns[4], LOW);
      digitalWrite(columns[5], LOW);
      digitalWrite(columns[10], LOW);
      digitalWrite(columns[11], LOW);
      delay(x);
      
      turnColumnsOff();
      digitalWrite(columns[6], LOW);
      digitalWrite(columns[7], LOW);
      digitalWrite(columns[8], LOW);
      digitalWrite(columns[9], LOW);
      delay(x);
      
      turnColumnsOff();
      digitalWrite(columns[3], LOW);
      digitalWrite(columns[6], LOW);
      digitalWrite(columns[9], LOW);
      digitalWrite(columns[12], LOW);
      delay(x);
      
      turnColumnsOff();
      digitalWrite(columns[2], LOW);
      digitalWrite(columns[6], LOW);
      digitalWrite(columns[9], LOW);
      digitalWrite(columns[13], LOW);
      delay(x);
      
      turnColumnsOff();
      digitalWrite(columns[1], LOW);
      digitalWrite(columns[5], LOW);
      digitalWrite(columns[10], LOW);
      digitalWrite(columns[14], LOW);
      delay(x);
    }
  }
  
  turnColumnsOff();
  digitalWrite(columns[0], LOW);
  digitalWrite(columns[5], LOW);
  digitalWrite(columns[10], LOW);
  digitalWrite(columns[15], LOW);
  delay(x);
}
