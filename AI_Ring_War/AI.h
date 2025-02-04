#pragma once
#include "Canvas.h"
#include "Point.h"

class AI { //AI 클래스
protected:  //protected로 선언하여 멤버함수를 자식 클래스가 사용할 수 있게 함
	string name, icon;
	Point q, p;
	int x;
	int y;
	int nSleep;
	int lev;
	double dist;

	void clip(int maxx, int maxy) { p(maxx, maxy); }
	void eat(int** map) {
		if (map[p.y][p.x] == 1) {
			map[p.y][p.x] = 0;
			nItem++;
		}
		dist += (double)(p - q);
		total += (double)(p - q);
		q = p;
		if (dist > 40) {
			dist = 0;
			nSleep = 10;
		}
	}
	bool isSleep() {
		if (nSleep > 0) {
			nSleep--;
			return true;
		}
		else return false;
	}
public:
	double total;
	int nItem;
	AI(string n = "이름없는AI", string i = "※", int x = 0, int y = 0)
		:name(n), icon(i), nItem(0),
		p(x, y), q(x, y), nSleep(0), dist(0.0), total(0.0) {}
	virtual ~AI() {  //재정의 가능하게 함
		cout << icon << nItem << "  거리: " << total << endl;
	}

	void draw(Canvas& canvas) { canvas.draw(p, icon); }
	virtual void move(int** map, int maxx, int maxy) { //재정의 가능하게 함
		if (!isSleep()) {
			int num = rand() % 9 + 1;
			p += Point(num % 3 - 1, num / 3 - 1);
			clip(maxx, maxy);
			eat(map);
		}
	}
	void print() { cout << "\t" << name << icon << ":" << nItem << ":" << nSleep << endl; }
};