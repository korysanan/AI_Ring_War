#pragma once
#include "AI.h"

class Siri : public AI {  //siri 클래스는 AI클래스의 자식클래스이다.
public:
	Siri(string n = "애플", string i = "§", int x = 0, int y = 0) //디폴트 매개변수
		: AI(n, i, x, y) {} //멤버 초기화 리스트
	~Siri() { cout << "[Siri]     "; } //재정의
};

class Bixby : public AI { //Bixby 클래스는 AI클래스의 자식클래스이다.
public:
	Bixby(string n = "삼성", string i = "◆", int x = 0, int y = 0) //디폴트 매개변수
		: AI(n, i, x, y) {} //멤버 초기화 리스트
	~Bixby() { cout << "[Bixby]    "; } //재정의

	void move(int** map, int maxx, int maxy) { //재정의
		if (!isSleep()) {
			int dir = rand() % 4;
			if (dir == 0) p[0]--;
			else if (dir == 1) p[0]++;
			else if (dir == 2) p[1]--;
			else p[1]++;
			clip(maxx, maxy);
			eat(map);
		}
	}
};

class  Alexa : public AI { //Alexa 클래스는 AI클래스의 자식클래스이다.
public:
	Alexa(string n = "아마존", string i = "♥", int x = 0, int y = 0) //디폴트 매개변수
		: AI(n, i, x, y) {} //멤버 초기화 리스트
	~Alexa() { cout << "[Alexa]    "; } //재정의

	void move(int** map, int maxx, int maxy) { //재정의
		if (!isSleep()) {
			p = Point(rand() % maxx, rand() % maxy);
			clip(maxx, maxy);
			eat(map);
		}
	}
};

class Watson : public AI { //Watson 클래스는 AI클래스의 자식클래스이다.
protected:
	bool bHori;
public:
	Watson(string n = "IBM", string i = "↔", int x = 0, int y = 0, bool bH = true) //디폴트 매개변수
		: AI(n, i, x, y), bHori(bH) {} //멤버 초기화 리스트
	~Watson() { cout << "[Watson]   "; } //재정의

	void move(int** map, int maxx, int maxy) { //재정의
		if (!isSleep()) {
			int dir = rand() % 2;
			int jump = rand() % 2 + 1;
			if (bHori)
				p[0] += ((dir == 0) ? -jump : jump);
			else
				p[1] += ((dir == 0) ? -jump : jump);
			clip(maxx, maxy);
			eat(map);
		}
	}
};

class Cotana : public Watson { //Cotana 클래스는 Watson클래스의 자식클래스이다.
	int count;
public:
	Cotana(string n = "MS", string i = "±", int x = 0, int y = 0, bool bH = true) //디폴트 매개변수
		: Watson(n, i, x, y, bH), count(30) {} //멤버 초기화 리스트
	~Cotana() { cout << "[Cotana]   "; } //재정의

	void move(int** map, int maxx, int maxy) { //재정의
		if (!isSleep()) {
			Watson::move(map, maxx, maxy);
			count--;
			if (count == 0) {
				bHori = !bHori;
				count = 30;
			}
			clip(maxx, maxy);
			eat(map);
		}
	}
};

class GigaGenie : public Bixby { //GigaGenie 클래스는 Bixby클래스의 자식클래스이다.
	int count2 = 30;
public:
	GigaGenie(string n = "KT", string i = "■", int x = 0, int y = 0) //디폴트 매개변수
		: Bixby(n, i, x, y) {} //멤버 초기화 리스트
	~GigaGenie() { cout << "[GigaGenie]"; } //재정의

	void move(int** map, int maxx, int maxy) { //재정의
		if (!isSleep()) {
			if (count2 > 30 && count2 <= 60)
			{
				Bixby::move(map, maxx, maxy);
				count2--;
			}
			else if (count2 <= 30) {
				switch (rand() % 4) {
				case 0: p[0]++; p[1]--; break;
				case 1: p[0]++; p[1]++; break;
				case 2: p[0]--; p[1]++; break;
				case 3: p[0]--; p[1]--; break;
				}
				count2--;
				if (count2 == 0) {
					count2 = 60;
				}
			}
			clip(maxx, maxy);
			eat(map);
		}
	}
};