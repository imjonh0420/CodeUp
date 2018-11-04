#include "pinSetting.h"
                // = *block_arr

int block_size[5] = {0, };
int a, b, c, d, e;
const int startPoint = 0;
const int startHeight = 1;
const int sizeX = 2;
const int sizeY = 3;
const int sizeZ = 4;

void setup(){

  Serial.begin(9600);
}

void loop(){

  turnOn_led(2, 4, 2, 2, 2);
  delay(10000);
  
}
void turnOn_led(int a, int b, int c, int d, int e){

    for(int i=0; i<5; i++){
      switch(i){
        case 0:
        block_size[i] = a;
        break;
        
        case 1:
        block_size[i] = b;
        break;
        
        case 2:
        block_size[i] = c;
        break;
        
        case 3:
        block_size[i] = d;
        break;
        
        case 4:
        block_size[i] = e;
        break;
      }
    }

    turnon_led(block_size);
    
}

int turnon_led(int blockSize[]){       //시작좌표와 X,Z,Y 축 크기를 입력받는다.

    int sizeX_plag = 0;
    int blockShape[blockSize[sizeX]*blockSize[sizeZ]] = {0, };
    int i, j;
    int height_plag = 0;
    blockSize[startPoint] --;
    blockSize[startHeight] --;

    while(blockSize[sizeY] > blockSize[startHeight]){     // 블럭이 LED큐브보다 크면 Y축 크기를 줄인다.
            blockSize[sizeY] --;
        }
    while(blockSize[startPoint]%4 + blockSize[sizeX] > 4){        // 블럭이 LED큐브보다 크면 X축 크기를 줄인다.
            blockSize[sizeX] --;
        }

    // LED 제어 시작
    int j_plag = 0;   // blockShape에 모양을 저장하기 위한 변수
    for(i=0; i<blockSize[sizeZ]; i++){     // blockShape 배열에 Y축을 제외한 블럭 모양을 저장한다.
        for(int j=0; j<blockSize[sizeX]; j++){
          blockShape[j_plag] = columns[j+blockSize[startPoint]];    // X축 좌표를 Z축 방향으로 한 칸 내린다.
          j_plag ++;
        }
        blockSize[startPoint] += 4;
    }

    //debuggin'
    for(i=0; i<blockSize[sizeX]*blockSize[sizeZ]; i++){
      Serial.print(blockShape[i]);
      Serial.print("  ");
    }

    /*
    int countOn = 0;
    for(i=0; i<16; i++){     // X,Z 축 블럭모양의 columns핀에 신호를 준다,  // 정한 모양 이외의 columns핀에는 신호를 끈다.
        for(j=0; j<blockSize[sizeX]*blockSize[sizeZ]; j++){
            if(i == blockShape[j]){
                digitalWrite(i, HIGH);
                countOn ++;
                Serial.print("cloumns Pin : ");
                Serial.print(i);
                Serial.println(" ON ");
                break;
            }
            else{
                digitalWrite(i, LOW);
                Serial.print("cloumns Pin : ");
                Serial.print(i);
                Serial.println(" OFF ");
            }
        }
        if(blockSize[sizeX]*blockSize[sizeZ] == countOn){
          break;
        }
    } */

    for(i=0; i < 16; i ++){    // 모든 columns핀의 신호를 끈다.
      digitalWrite(columns[i], HIGH);
    }
    for(i=0; i < blockSize[sizeX]*blockSize[sizeZ]; i++){   // 지정한 모양의 columns핀에만 신호를 준다.
      digitalWrite(blockShape[i], LOW);
      Serial.print("cloumns핀 : ");
      Serial.print(blockShape[i]);
      Serial.println(" ON ");
    }
    
    /*
    for(i=3; i>=0; i --){        // 읽어들인 startHeight값과 Y축 크기만큼 layer에 신호를 준다.  // 정한 모양 이외의 layer에는 신호를 끈다.
            if(i == blockSize[startHeight]){

                height_plag = i;

                for(j=0; j<blockSize[sizeY]; j++){
                    digitalWrite(layer[height_plag], LOW);
                    height_plag --;
                    i --;
                    Serial.print("layer핀 : ");
                    Serial.print(layer[height_plag]);
                    Serial.println(" ON ");
                }
            }
            else{
                digitalWrite(layer[i], HIGH);
                Serial.print("layer핀 : ");
                Serial.print(layer[i]);
                Serial.println(" OFF ");
            }
        } */

    for(i=0; i<4; i ++){
        digitalWrite(layer[i], LOW);
    }

    height_plag = blockSize[startHeight];
    for(i=0; i < blockSize[sizeY]; i++){
        digitalWrite(layer[height_plag], HIGH);
        height_plag --;
        Serial.print("layer Pin : ");
        Serial.print(layer[height_plag]);
        Serial.println(" ON ");
    }

}


void blockShift(int shiftX, int shiftZ, int shiftY){
    
    for(int i=0; i<sizeZ; i++){
        shiftX += 4;
    }

    for(int i=0; i<5; i++){
      switch(i){
        case 0:
        block_size[i] = a+shiftX;
        break;
        
        case 1:
        block_size[i] = b+shiftY;
        break;
        
        case 2:
        block_size[i] = c;
        break;
        
        case 3:
        block_size[i] = d;
        break;
        
        case 4:
        block_size[i] = e;
        break;
      }
    }
    
    turnon_led(block_size);

}
