#pragma once
#include "Canvas.h"
#include "AIKinds.h"
#include "Matrix.h"
#include "Player.h"
#include <Windows.h>
#define MAXMONS 8

class AIWorld  //AIWorld 클래스 선언   난이도 下용
{
	Matrix world;
	int xMax, yMax, nMon, nMove;
	AI* pMon[MAXMONS];
	Canvas canvas;

	int& Map(int x, int y) { return world.elem(x, y); }
	bool isDone() { return countItems() == 0; }
	int countItems() {
		int nItems = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) nItems++;
		return nItems;
	}
	void print() {
		canvas.clear(". ");
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) canvas.draw(x, y, "@ ");
		for (int i = 0; i < nMon; i++)
			pMon[i]->draw(canvas);
		canvas.print("[ AI World (AI로부터 지구를 지켜라) ]");

		cerr << " 전체 이동 횟수 = " << nMove << endl;
		cerr << " 남은 아이템 수 = " << countItems() << endl;
		for (int i = 0; i < nMon; i++)
			pMon[i]->print();
	}
public:
	AIWorld(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h) {
		nMon = 0;
		nMove = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++) Map(x, y) = 1;
	}
	~AIWorld() {
		for (int i = 0; i < nMon; i++)
			delete pMon[i];
	}
	void add(AI* m) {
		if (nMon < MAXMONS)
			pMon[nMon++] = m;
	}
	void play(int maxwalk, int wait) {
		print();
		cerr << " 엔터를 누르세요...";
		getchar();
		for (int i = 0; i < maxwalk; i++) {
			((Siri*)pMon[0])->move(world.Data(), xMax, yMax);  //this 포인터 사용
			((Bixby*)pMon[1])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((Alexa*)pMon[2])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((Watson*)pMon[3])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((Watson*)pMon[4])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((Player1*)pMon[5])->move(world.Data(), xMax, yMax); //this 포인터 사용
			nMove++;
			print();
			if (isDone()) break;
			Sleep(wait);
		}
	}
};


class AIWorld2 //AIWorld2 클래스 선언   난이도 中용
{
	Matrix world;
	int xMax, yMax, nMon, nMove;
	AI* pMon[MAXMONS];
	Canvas canvas;

	int& Map(int x, int y) { return world.elem(x, y); }
	bool isDone() { return countItems() == 0; }
	int countItems() {
		int nItems = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) nItems++;
		return nItems;
	}
	void print() {
		canvas.clear(". ");
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) canvas.draw(x, y, "◎");
		for (int i = 0; i < nMon; i++)
			pMon[i]->draw(canvas);
		canvas.print("[ AI World (AI로부터 지구를 지켜라) ]");

		cerr << " 전체 이동 횟수 = " << nMove << endl;
		cerr << " 남은 아이템 수 = " << countItems() << endl;
		for (int i = 0; i < nMon; i++)
			pMon[i]->print();
	}

public:
	AIWorld2(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h) {
		nMon = 0;
		nMove = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++) Map(x, y) = 1;
	}
	~AIWorld2() {
		for (int i = 0; i < nMon; i++)
			delete pMon[i];
	}
	void add(AI* m) {
		if (nMon < MAXMONS)
			pMon[nMon++] = m;
	}
	void play(int maxwalk, int wait) {
		print();
		cerr << " 엔터를 누르세요...";
		getchar();
		for (int i = 0; i < maxwalk; i++) {
			((Siri*)pMon[0])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((Bixby*)pMon[1])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((Alexa*)pMon[2])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((Watson*)pMon[3])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((Watson*)pMon[4])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((Player1*)pMon[5])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((Cotana*)pMon[6])->move(world.Data(), xMax, yMax);  //this 포인터 사용
			((GigaGenie*)pMon[7])->move(world.Data(), xMax, yMax); //this 포인터 사용
			nMove++;
			print();
			if (isDone()) break;
			Sleep(wait);
		}
	}
};

class AIWorld3  ////AIWorld3 클래스 선언   난이도 上용
{
	Matrix world;
	int xMax, yMax, nMon, nMove;
	AI* pMon[MAXMONS];
	Canvas canvas;

	int& Map(int x, int y) { return world.elem(x, y); }
	bool isDone() { return countItems() == 0; }
	int countItems() {
		int nItems = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) nItems++;
		return nItems;
	}
	void print() {
		canvas.clear(". ");
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++)
				if (Map(x, y) > 0) canvas.draw(x, y, "◎");
		for (int i = 0; i < nMon; i++)
			pMon[i]->draw(canvas);
		canvas.print("[ AI World (AI로부터 지구를 지켜라) ]");

		cerr << " 전체 이동 횟수 = " << nMove << endl;
		cerr << " 남은 아이템 수 = " << countItems() << endl;
		for (int i = 0; i < nMon; i++)
			pMon[i]->print();
	}

public:
	AIWorld3(int w, int h) : world(h, w), canvas(w, h), xMax(w), yMax(h) {
		nMon = 0;
		nMove = 0;
		for (int y = 0; y < yMax; y++)
			for (int x = 0; x < xMax; x++) Map(x, y) = 1;
	}
	~AIWorld3() {
		for (int i = 0; i < nMon; i++)
			delete pMon[i];
	}
	void add(AI* m) {
		if (nMon < MAXMONS)
			pMon[nMon++] = m;
	}
	void play(int maxwalk, int wait) {
		print();
		cerr << " 엔터를 누르세요...";
		getchar();
		for (int i = 0; i < maxwalk; i++) {
			((Siri*)pMon[0])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((Bixby*)pMon[1])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((Alexa*)pMon[2])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((Watson*)pMon[3])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((Watson*)pMon[4])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((Player*)pMon[5])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((Cotana*)pMon[6])->move(world.Data(), xMax, yMax); //this 포인터 사용
			((GigaGenie*)pMon[7])->move(world.Data(), xMax, yMax); //this 포인터 사용
			nMove++;
			print();
			if (isDone()) break;
			Sleep(wait);
		}
	}
};