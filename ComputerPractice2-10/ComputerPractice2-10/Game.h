#pragma once
#include <Windows.h>
#include <iostream>

using namespace std;

class Game {
private : 
	int x;
	int y;
	int direction;
	void gotoXY(int x, int y) {
		COORD pos = { x, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	}
public : 
	Game() {
		x = 5;
		y = 5;
		direction = 0;
	}
	void setDirection(int i) {
		direction = i;
	}
	void move() {
		if (direction == 37) {
			x--;
			if (x < 0) {
				x = 0;
			}
		}
		else if (direction == 38) {
			y--;
			if (y < 0) {
				y = 0;
			}
		}
		else if (direction == 39) {
			x++;
			if (x > 30) {
				x = 30;
			}
		}
		else if (direction == 40) {
			y++;
			if (y > 40) {
				y = 40;
			}
		}
		system("cls");
		this->gotoXY(x, y);
		cout << x << " " << y;
		cout << "бс";
	}
	int getX() {
		return this->x;
	}
	int getY() {
		return this->y;
	}
};