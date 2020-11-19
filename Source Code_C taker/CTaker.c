/****************   MEMO   ***************************
* 
* 
*	1tap = 4 space;
*	//system("cls"); 화면 지우기
* 
* 
* 
* 
* ****************************************************/


#define _CRT_SECURE_NO_WARNINGS


#include <stdio.h>
#include <conio.h>

#include "game.h"
#include "utility.h"
#include "map.h"


#define TRUE 1
#define FALSE 0

typedef char mapArr[66];

int Title();
int Menu();
mapArr *StageSelect();
void Initialize();
void XYPrint(int x, int y, char *sentences);
void GotoXY(int x, int y);
void SetColor();
int GetKey();


int main() {

	Initialize();

	while (1) {

		int tmp = Title();
		
		switch (tmp) {
			case 0:		// 게임시작
				GameLoop(StageSelect());
				break;
			case 1:		// 튜토리얼
				break;
			case 2:		// 게임 종료
				return 0;
		}

		system("cls");

	}

	return 0;

}

// Title 출력, Menu에서 받아온 값(선택 확인 여부) Return
int Title() {

	printf("\n\n\n\n");
	printf("         ####         #####    ###    #  #   #####   #### \n");		// 가로 58칸
	printf("        #               #     #   #   # #    #       #   #\n");
	printf("        #               #     #####   ##     #####   #### \n");
	printf("        #               #     #   #   # #    #       # #  \n");
	printf("         ####           #     #   #   #  #   #####   #   #\n");

	return Menu();

}

// Menu 출력, GetKey()로 선택지 이동 및, 선택 확인
int Menu() {

	const int menuX = 28;		// 공백 2칸과 한글 1칸의 가로 길이가 같음.
		  int menuY = 12;

	XYPrint(menuX - 2, menuY, "> 게임시작");
	XYPrint(menuX, menuY + 1, "튜토리얼");
	XYPrint(menuX, menuY + 2, "  종료  ");

	
	while (1) {

		switch (GetKey()) {
			case UP:
				if (menuY > 12) {
					XYPrint((menuX - 2), (menuY + 0), " ");	// Remove() 로 합칠만 한가
					XYPrint((menuX - 2), (--  menuY), ">");
				}
				break;
			case DOWN:
				if (menuY < 14) {
					XYPrint((menuX - 2), (menuY + 0), " ");	// Remove() 로 합칠만 한가
					XYPrint((menuX - 2), (++  menuY), ">");
				}
				break;
			case CHECK:
				return menuY - 12;
		}
	}
}

// StageSelect 출력, GetKey()로 선택지 이동 및, 선택 확인 후 알맞은 map 주소 반환
mapArr *StageSelect() {

	system("cls");

	const int stageSelectX = 30;
		  int stageSelectY = 7;

	XYPrint(stageSelectX - 3, stageSelectY - 5,     "Stage Select");
	XYPrint(stageSelectX - 2, stageSelectY - 0,     "> Stage 1");
	XYPrint(stageSelectX - 0, stageSelectY + 2,		"Stage 2");
	XYPrint(stageSelectX - 0, stageSelectY + 4,		"Stage 3");

	while (1) {

		switch (GetKey()) {
		case UP:
			if (stageSelectY > 7) {
				XYPrint((stageSelectX - 2), (stageSelectY + 0), " ");	// Remove() 로 합칠만 한가
				XYPrint((stageSelectX - 2), (stageSelectY -= 2), ">");
			}
			break;
		case DOWN:
			if (stageSelectY < 11) {
				XYPrint((stageSelectX - 2), (stageSelectY + 0), " ");	// Remove() 로 합칠만 한가
				XYPrint((stageSelectX - 2), (stageSelectY += 2), ">");
			}
			break;
		case CHECK:

			system("mode con cols=66 lines=25");

			switch (stageSelectY - 7) {
				case 0:
					return map1;
				/*case 2:
					return map2;
				case 4:
					return map3;*/

			}
		}
	}
}
