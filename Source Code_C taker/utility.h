#include <windows.h>
#include <stdlib.h>

#define PLAYER 38		// &
#define WALL 64			// @
#define STONE 69		// %
#define MONSTER 74		// *
#define ACT_TRAP 65		// !
#define DEACT_TRAP 78	// .

#define UP_ARROW 72			// ก่
#define DOWN_ARROW 80		// ก้
#define LEFT_ARROW 75		// ก็
#define RIGHT_ARROW 77		// กๆ
#define SPACE 32			// SpaceBar

#define UP 8
#define DOWN 2
#define LEFT 4
#define RIGHT 6
#define CHECK 5

#define WIDTH 66
#define HEIGTH 20

enum {
	black,
	blue,
	green,
	cyan,
	red,
	purple,
	brown,
	lightgray,
	darkgray,
	lightblue,
	lightgreen,
	lightcyan,
	lightred,
	lightpurple,
	yellow,
	white
};

void GotoXY(int x, int y);
void XYPrint(int x, int y, char* sentences);
void Initialize();
void SetColor();
int GetKey();