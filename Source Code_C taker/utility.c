#include "utility.h"

void Initialize() {

	system("mode con cols=66 lines=20");

	/*왜 이건 안되고 아래에 있는건 됨?
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCurosr;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);*/

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO ConsoleCursor;
	ConsoleCursor.bVisible = 0;
	ConsoleCursor.dwSize = 1;
	SetConsoleCursorInfo(consoleHandle, &ConsoleCursor);

}

void GotoXY(int x, int y) {

	COORD Pos;
	Pos.X = x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);

}

void XYPrint(int x, int y, char *sentences) {

	GotoXY(x, y);
	printf("%s", sentences);

}

void SetColor(int frontGround, int backGround) {

	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	int code = frontGround + backGround * 16;
	SetConsoleTextAttribute(consoleHandle, code);
	
}

int GetKey() {

	switch (_getch()) {
		case UP_ARROW:
			return UP;
		case DOWN_ARROW:
			return DOWN;
		case LEFT_ARROW:
			return LEFT;
		case RIGHT_ARROW:
			return RIGHT;
		case SPACE:
			return CHECK;
	}

	return FALSE;

}