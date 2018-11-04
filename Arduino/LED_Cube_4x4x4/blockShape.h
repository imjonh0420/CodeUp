#include <stdlib.h>
#include <time.h>
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


void blockDrop(){

  int order = 0;    // 구조체 배열에 접근하기 위한 변수 order 선언 및 초기화.
  
  struct randomBlock {    // 구조체 선언.
      int block_shape[5] = {0, 4, 2, 2, 1};
  };    // 선언과 동시에 배열로 정의.

  struct randomBlock _randomBlock[5];
  
  
  // 시분할 제어로 LED block을 표시함
  for(unsigned int i = 0; ; i ++){    // 음수부 i는 사용하지 않음.
    if(i % 1000){   // 1초마다

      do{   //  난수(randPoint) 생성.
      i = random(11)+1;
      } while ( (i != 1) && (i != 3) && (i != 9) && (i != 11) );   // 1, 3, 9, 11인 난수만 선택함.

      
      _randomBlock[order].block_shape[0] = i;     // 구조체 요소에 블럭 모양을 저장한 배열을 저장.   

      for(i=0; i<5; i++){
        Serial.print(_randomBlock[order].block_shape[i]);
        Serial.println("  ");
        delay(500);
      }
      if(order < 4){        // 구조체 배열의 모든 요소에 값이 저장되지 않았다면
        order ++;           // 다음 배열의 요소에 값을 저장하기 위해 order를 1 늘림.
      }
      else if(order >= 5){   // 구조체 배열의 모든 요소에 값이 저장되었다면
        order = 0;           // 쓸모없어진 구조체 배열의 첫번째 값에 다시 값을 저장함.
      }
      
    }

    

  delay(1);
  }
  free(_randomBlock);
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
}
