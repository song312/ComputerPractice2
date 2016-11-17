#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;

enum {
	Black, D_BLUE, D_GREEN, D_SKYBLUE, D_RED,
	D_VIOLET, D_YELLOW, GRAY, D_GRAY, BLUE,
	GREEN, SKYBLUE, RED, VIOLET, YELLOW, WHITE,
};

void gotoXY(int x, int y) {
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void setColor(char color, char backGround) {
	//색만 바꾸고 싶을 때는 뒤에 background 지우기
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (backGround << 4) + color);
}

void clearConsole() {
	system("cls");
}

class KeyEvent {
private:
	HANDLE hln;
	COORD KeyWhere;
	DWORD EventCount;
	INPUT_RECORD InRec;
	DWORD NumRead;
	int downKey;
public:
	KeyEvent() {
		hln = GetStdHandle(STD_INPUT_HANDLE);
		EventCount = 1;
	}
	int getKey() {
		ReadConsoleInput(hln, &InRec, 1, &NumRead);
		if (InRec.EventType == KEY_EVENT) {
			if (InRec.Event.KeyEvent.bKeyDown) {
				downKey = InRec.Event.KeyEvent.wVirtualKeyCode;
				return downKey;
			}
			else {
				return -1;
			}
		}
		return -1;
	}
};