#include "game.h"
#include "utility.h"


char tmpMap[25][66];

/*
struct mapInfo {

	int scores;
	int leftMove;
	int leftLife;

};*/

/*
struct PlayerInfo {

	int stages;
};*/

void GameLoop(char (*map)[WIDTH]) {

	int isPlaying = 1;

	int playerX = 0;
	int playerY = 0;

	DisplayMap(map, &playerX, &playerY);

	// 초기 플레이어 출력
	SetColor(blue, blue);
	XYPrint(playerX+1, playerY, " ");
	SetColor(white, black);		// ResetColor

	while (isPlaying) {

		
		Sleep(50);
		system("cls");

		for (int i = 0; i < HEIGTH; i++) {
			for (int j = 0; j < WIDTH; j++) {
				printf("%c", tmpMap[i][j]);
			}
		}

		GotoXY(50, 21);
		printf("x, y : %2d, %2d", playerX, playerY);

		GotoXY(30, 22);
		printf("%c", tmpMap[playerX][playerY]);

		GotoXY(30, 21);
		printf("%c", tmpMap[playerX][playerY - 1]);

		GotoXY(30, 23);
		printf("%c", tmpMap[playerX][playerY + 1]);

		GotoXY(28, 22);
		printf("%c", tmpMap[playerX - 2][playerY]);

		GotoXY(32, 22);
		printf("%c", tmpMap[playerX + 2][playerY]);



		switch (GetKey()) {
			case UP:
				move(&playerX, &playerY, UP);
				break;
			case DOWN:
				move(&playerX, &playerY, DOWN);
				break;
			case LEFT:
				move(&playerX, &playerY, LEFT);
				break;
			case RIGHT:
				move(&playerX, &playerY, RIGHT);
				break;
		}
	}
}

// 플레이어 좌표와 움직일 방향을 받는다. 기존 플레이어를 지운다. 움직일 방향으로 플레이어의 좌표를 옮기고, 그 위치에 플레이어를 출력한다
void move(int* x, int* y, int direction) {

		switch (direction) {
		case UP:
			if (tmpMap[*x][(*y) - 1] != '@') {
				XYPrint(*x, *y, " ");
				XYPrint((*x) + 1, *y, " ");
				SetColor(blue, blue);
				XYPrint((*x) += 0, (*y) -= 1, "&");
				XYPrint((*x) + 1, (*y) - 0, "&");
			}
			break;
		case DOWN:
			if (tmpMap[*x][(*y) + 1] != '@') {
				XYPrint(*x, *y, " ");
				XYPrint((*x) + 1, *y, " ");
				SetColor(blue, blue);
				XYPrint((*x) += 0, (*y) += 1, "&");
				XYPrint((*x) + 1, (*y) + 0, "&");
			}
			break;
		case LEFT:
			if (tmpMap[(*x) - 2][*y] != '@') {
				XYPrint(*x, *y, " ");
				XYPrint((*x) + 1, *y, " ");
				SetColor(blue, blue);
				XYPrint((*x) -= 2, (*y) += 0, "&");
				XYPrint((*x) + 1, (*y) + 0, "&");
			}
			break;
		case RIGHT:
			if (tmpMap[(*x) + 2][*y] != '@') {
				XYPrint(*x, *y, " ");
				XYPrint((*x) + 1, *y, " ");
				SetColor(blue, blue);
				XYPrint((*x) += 2, (*y) += 0, "&");
				XYPrint((*x) + 1, (*y) + 0, "&");
			}
			break;
	}

	SetColor(white, black);		// ResetColor

}

void DisplayMap(char(*map)[WIDTH], int* playerX, int* playerY) {

	system("cls");

	memcpy(tmpMap, map, sizeof(tmpMap));

	for (int i = 0; i < HEIGTH; i++) {
		for (int j = 0; j < WIDTH; j++) {

			char tmp = tmpMap[i][j];

			
			/*if (tmp == '@') {
				SetColor(white, white);
				printf("%c", tmp);
			}
			else if (tmp == ' ') {
				SetColor(white, black);
				printf("%c", tmp);
			}*/
			if (tmp == '&') {
				SetColor(blue, blue);
				//printf("%c", tmp);

				*playerX = j;
				*playerY = i;
			}

			SetColor(white, black);
			printf("%c", tmpMap[i][j]);

		}
		if (i < HEIGTH - 1) printf("\n");	// 줄바꿈 20번하면 맨 윗 줄 사라짐.
	}

	SetColor(white, black);		// ResetColor

}