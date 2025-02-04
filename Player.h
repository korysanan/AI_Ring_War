#pragma once
#include "AI.h"
#include <conio.h>
enum Direction { Left = 75, Right = 77, Up = 72, Down = 80 };

class Player1 : public AI {  //난이도 中, 下에서의 플레이어 클래스
public:
	Player1(string n = "미래인류", string i = "♀", int px = 0, int py = 0)
		: AI(n, i, px, py) {}
	~Player1() { cout << "[Player1]  "; }
	int getDirkey() { return _getche() == 224 ? _getche() : 0; }
	void move(int** map, int maxx, int maxy) {
		if (_kbhit()) { //키가 입력이 되었는지 확인
			char ch = getDirkey();
			if (ch == Left) p[0]--;
			else if (ch == Right)p[0]++;
			else if (ch == Up)p[1]--;
			else if (ch == Down)p[1]++;
			else return;
			clip(maxx, maxy);
			eat(map);
		}
	}
};
class Player : public AI { // 난이도 上에서의 플레이어 클래스
public:
	Player(string n = "미래인류", string i = "♀", int px = 0, int py = 0)
		: AI(n, i, px, py) {}
	~Player() { cout << "[Player1]  "; }
	int getDirkey() { return _getche() == 224 ? _getche() : 0; }
	void move(int** map, int maxx, int maxy) {
		if (_kbhit()) { //키가 입력이 되었는지 확인
			if (!isSleep()) {  //난이도 上의 경우 AI들과 같이 멈추는 시간이 있음
				char ch = getDirkey();
				if (ch == Left) p[0]--;
				else if (ch == Right)p[0]++;
				else if (ch == Up)p[1]--;
				else if (ch == Down)p[1]++;
				else return;
				clip(maxx, maxy);
				eat(map);
			}
		}
	}
};