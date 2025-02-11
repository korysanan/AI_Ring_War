#pragma once
#include <iostream>

void Start_Game(int difficulty) {
	if (difficulty == 1)
	{
		RankingBoard rank;
		try {  //예외처리
			rank.load("AIWorld1.rnk");
		}
		catch (FileException e) {
			char str[80];
			string passwd, correct = "22";
			cout << "AI의 풀네임에서 알파벳 갯수는 총 몇개일까?: ";
			for (int i = 0;; i++) {
				str[i] = _getch();
				putchar('*');
				if (str[i] == '\r') {
					str[i] = '\0';
					passwd = str;
					cout << "\n";
					break;
				}
			}
			if (passwd != correct) {
				cout << "비밀번호가 맞지 않습니다. 게임 종료.\n\n";
				exit(0);
			}
		}
		rank.print("[게임 랭킹: 시작]");
		_getche();

		srand((unsigned int)time(NULL));
		int w = 32, h = 16;  //맵은 32*16 이다. 총 아이템의 갯수는 512개

		AIWorld game(w, h);
		game.add(new Siri("손이시려워", "§", rand() % w, rand() % h));
		game.add(new Bixby("하이빅스비", "◆", rand() % w, rand() % h));
		game.add(new Alexa("알렉사라구", "♥", rand() % w, rand() % h));
		game.add(new Watson("가로로왓슨", "↔", rand() % w, rand() % h, true));
		game.add(new Watson("세로로왓슨", "↕", rand() % w, rand() % h, false));

		Player1* player1 = new Player1("플레이어  ", "♀", rand() % w, rand() % h);
		game.add(player1);
		game.play(1000, 10);
		printf("------게임 종료---------------------\n");
		if (player1->nItem > 256)  //Player1의 아이템의 개수가 256 이상이면
		{
			cout << "승리하였습니다\n";
			cout << "당신으로 인해 지구는 평화를 찾게 되었습니다.\n";
			cout << "게임 저장을 위해 스페이스 키를 누르세요...\n";
			waitForSpaceKey();
			rank.add(player1->nItem, player1->nItem / player1->total);  //this 포인터를 이용하여 Player1의 nItem과 nItem / total을 랭킹 순위에 올립니다. 
			rank.print("[게임 랭킹: 종료]");
			rank.store("AIWorld1.rnk");
		}
		else
		{
			cout << "패배하였습니다\n";
			cout << "아쉽게도 지구는 AI에게 정복을 당했습니다.\n";
			cout << "스페이스 키를 눌러서 게임을 종료하십시오..";
			waitForSpaceKey();
		}
	}

	if (difficulty == 2)  //주석으로 인한 설명은 위와 동일
	{
		RankingBoard rank;
		try {
			rank.load("AIWorld2.rnk");
		}
		catch (FileException e) {
			char str[80];
			string passwd, correct = "22";
			cout << "AI의 풀네임에서 알파벳 갯수는 총 몇개일까?: ";
			for (int i = 0;; i++) {
				str[i] = _getch();
				putchar('*');
				if (str[i] == '\r') {
					str[i] = '\0';
					passwd = str;
					cout << "\n";
					break;
				}
			}
			if (passwd != correct) {
				cout << "비밀번호가 맞지 않습니다. 게임 종료.\n\n";
				exit(0);
			}
		}
		rank.print("[게임 랭킹: 시작]");
		_getche();

		srand((unsigned int)time(NULL));
		int w = 32, h = 16;

		AIWorld2 game(w, h);
		game.add(new Siri("손이시려워", "§", rand() % w, rand() % h));
		game.add(new Bixby("하이빅스비", "◆", rand() % w, rand() % h));
		game.add(new Alexa("알렉사라구", "♥", rand() % w, rand() % h));
		game.add(new Watson("가로로왓슨", "↔", rand() % w, rand() % h, true));
		game.add(new Watson("세로로왓슨", "↕", rand() % w, rand() % h, false));
		game.add(new Cotana("코타나래요", "±", rand() % w, rand() % h));
		game.add(new GigaGenie("기가지니야", "■", rand() % w, rand() % h));

		Player1* player1 = new Player1("플레이어  ", "♀", rand() % w, rand() % h);
		game.add(player1);
		game.play(1000, 10);
		printf("------게임 종료---------------------\n");

		if (player1->nItem > 256)
		{
			cout << "승리하였습니다\n";
			cout << "당신으로 인해 지구는 평화를 찾게 되었습니다.\n";
			cout << "게임 저장을 위해 스페이스 키를 누르세요...\n";
			waitForSpaceKey();
			rank.add(player1->nItem, player1->nItem / player1->total);
			rank.print("[게임 랭킹: 종료]");
			rank.store("AIWorld2.rnk");
		}
		else
		{
			cout << "패배하였습니다\n";
			cout << "아쉽게도 지구는 AI에게 정복을 당했습니다.\n";
			cout << "스페이스 키를 눌러서 게임을 종료하십시오..";
			waitForSpaceKey();
		}
	}

	if (difficulty == 3)  //주석으로 인한 설명은 위와 동일
	{
		RankingBoard rank;
		try {
			rank.load("AIWorld3.rnk");
		}
		catch (FileException e) {
			char str[80];
			string passwd, correct = "22";
			cout << "AI의 풀네임에서 알파벳 갯수는 총 몇개일까?: ";
			for (int i = 0;; i++) {
				str[i] = _getch();
				putchar('*');
				if (str[i] == '\r') {
					str[i] = '\0';
					passwd = str;
					cout << "\n";
					break;
				}
			}
			if (passwd != correct) {
				cout << "비밀번호가 맞지 않습니다. 게임 종료.\n\n";
				exit(0);
			}
		}
		rank.print("[게임 랭킹: 시작]");
		_getche();

		srand((unsigned int)time(NULL));
		int w = 32, h = 16;

		AIWorld3 game(w, h);
		game.add(new Siri("손이시려워", "§", rand() % w, rand() % h));
		game.add(new Bixby("하이빅스비", "◆", rand() % w, rand() % h));
		game.add(new Alexa("알렉사라구", "♥", rand() % w, rand() % h));
		game.add(new Watson("가로로왓슨", "↔", rand() % w, rand() % h, true));
		game.add(new Watson("세로로왓슨", "↕", rand() % w, rand() % h, false));
		game.add(new Cotana("코타나래요", "±", rand() % w, rand() % h));
		game.add(new GigaGenie("기가지니야", "■", rand() % w, rand() % h));

		Player* player = new Player("플레이어  ", "♀", rand() % w, rand() % h);
		game.add(player);
		game.play(1000, 10);
		printf("------게임 종료---------------------\n");

		if (player->nItem > 256)
		{
			cout << "승리하였습니다\n";
			cout << "당신으로 인해 지구는 평화를 찾게 되었습니다.\n";
			cout << "게임 저장을 위해 스페이스 키를 누르세요...\n";
			waitForSpaceKey();
			rank.add(player->nItem, player->nItem / player->total);
			rank.print("[게임 랭킹: 종료]");
			rank.store("AIWorld3.rnk");
		}
		else
		{
			cout << "패배하였습니다\n";
			cout << "아쉽게도 지구는 AI에게 정복을 당했습니다.\n";
			cout << "스페이스 키를 눌러서 게임을 종료하십시오..";
			waitForSpaceKey();
		}
	}
}