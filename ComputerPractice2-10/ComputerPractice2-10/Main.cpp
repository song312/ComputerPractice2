#include <process.h>
#include "KeyEvent.h"
#include "Game.h"

using namespace std;

Game* game = new Game();

unsigned int __stdcall mythread(void*) {
	int i = 0;
	while (1) {
		//cout << GetCurrentThreadId() << ": " << i++ << endl;
		game->move();
		Sleep(500);
	}
	return 0;
}

unsigned int __stdcall keyEvent(void*) {
	KeyEvent k;
	int i;
	while (1) {
		i = k.getKey();
		/*switch (i) {
			case 37 : 
				cout << "Left key is pressed" << endl;
				break;
			case 38:
				cout << "Up key is pressed" << endl;
				break;
			case 39:
				cout << "Right key is pressed" << endl;
				break;
			case 40:
				cout << "Down key is pressed" << endl;
				break;
		}*/
		if (i != -1) {
			game->setDirection(i);
		}
		
	}
	return 0;
}

int main() {
	HANDLE handleA, handleB;

	handleA = (HANDLE)_beginthreadex(0, 0, &mythread, (void*)0, 0, 0);
	handleB = (HANDLE)_beginthreadex(0, 0, &keyEvent, (void*)0, 0, 0);

	WaitForSingleObject(handleA, INFINITE);
	WaitForSingleObject(handleB, INFINITE);

	CloseHandle(handleA);
	CloseHandle(handleB);

	return 0;
}