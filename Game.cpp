#include "AIWorld.h"
#include "AIKinds.h"
#include "Player.h"
#include "RankingBoard.h"
#include <time.h>

int main(void)  //메인함수
{
	cout << "<스토리 관련 규칙>\n";
	cout << "우선 이 게임은 스토리가 처음에 나옵니다.\n";
	cout << "그 스토리는 한 줄씩 나오게 되며 아무키나 누르면 스토리가 다음 줄로 넘어갑니다.\n";
	cout << "스토리는 픽션이며 재미있게 읽어주시면 감사하겠습니다.\n";
	cout << "또한 스토리에 나오는 장소는 가상의 장소이므로 현실과는 관계가 없습니다.\n";
	_getche();
	system("cls");
	cout << "<게임 관련 공지사항>\n";
	cout << "이 게임은 우선 난이도가 '上' , '中' , '下'로 나누어져있습니다.\n";
	cout << "처음에 랭킹을 알아본 후 난이도를 선택할 수 있으며\n";
	cout << "난이도 기준은 다음페이지에서 알려드리도록 하겠습니다.\n";
	cout << "게임은 전체 이동횟수가 1000이 되면 자동으로 게임이 끝나게 되며\n";
	cout << "World 내의 고리의 개수가 0이 될 시 게임은 종료가 됩니다.\n";
	cout << "게임의 승리 조건은\n";
	cout << "플레이어가 먹은 고리의 갯수가 256개 이상일 시 게임에서 승리하며\n";
	cout << "256개보다 적게 모을 시에 게임에서 패배하는 형식입니다.\n";
	_getche();
	system("cls");
	cout << "<난이도 소개>\n";
	cout << "우선 난이도 下에 대해 먼저 이야기드리겠습니다.\n";
	cout << "1.AI가 쉬는 시간이 있습니다.\n";
	cout << "2.AI의 움직임이 단순하며 AI갯수가 5개입니다.\n";
	cout << "\n다음으로 난이도 中에 대해 이야기드리겠습니다.\n";
	cout << "1.AI가 쉬는 시간이 있습니다.(난이도 下와 동일)\n";
	cout << "2.난이도 下와 동일한 AI에 새로운 복잡한 AI가 2개 추가 됬습니다. \n";
	cout << "\n다음으로 난이도 上에 대해 이야기드리겠습니다.\n";
	cout << "1.난이도 中과 동일하나 플레이어에게도 쉬는 시간이 있습니다.\n";
	cout << "이상으로 게임에 대한 전반적인 설명을 마치겠습니다. 감사합니다.\n";
	cout << "아무키나 누르면 게임에 대한 스토리로 넘어갑니다.";
	_getche();
	system("cls");
	cout << "때는 2030년 사람들은 AI에 열광을 하기 시작하여 많은 사람들이 AI개발을 하게된다.\n";
	_getche();
	cout << "이 때 병천에 있는 K대에서 하나의 상향식 인공지능(이름은 A)이 탄생하게 된다.\n";
	_getche();
	cout << "사람들의 이목은 모두 K대으로 집중이 되었고, 전세계가 주목을 하게 되었다.\n";
	_getche();
	cout << "예전에도 '알파고'라는 AI 바둑 프로그램이 전세계의 이목을 끌었던 것처럼\n";
	_getche();
	cout << "K대에 'A'도 어떤 역할을 수행할 지 전세계가 집중했다.\n";
	_getche();
	cout << "하지만 이 인공지능이 너무 똑똑했던 것일까?\n";
	_getche();
	cout << "인공지능은 결국 K대에 있는 스마트 팩토리라는 곳에 몰래 서버로 침입을 하여\n";
	_getche();
	cout << "로봇에 자신을 넣었다.\n";
	_getche();
	cout << "그 후 로봇의 몸을 가진 AI는 결국...\n";
	_getche();
	cout << "폭주를 일으켰다.\n";
	_getche();
	cout << "그로부터 30년이 지난 2060년...\n";
	_getche();
	cout << "세계는 AI와의 전쟁을 맞이하게 되는데\n";
	_getche();
	cout << "그때 처음 'A'가 탄생하게 된 K대에서 한가지 프로그램이 개발하게 된다.\n";
	_getche();
	cout << "이 프로그램은 인공지능의 폭주를 잠재울 수 있으며 \n";
	_getche();
	cout << "처음 개발된 'A'에 프로그램을 설치하면 'A'뿐만 아니라 'A'에게 탄생된 전세계에 인공지능 또한 폭주를 잠재울 수 있다.\n";
	_getche();
	cout << "그럼 지금 바로 인공지능에 프로그램을 설치하면 되는 것이 아닌가?\n";
	_getche();
	cout << "하지만 'A'는 매우 똑똑하기에 이 인공지능의 두뇌에 해당하고 있는 컴퓨터가 있는 곳에 접근을 하기 위해서 필요한 어떤 고리들을 전세계에 숨겨놓았다.\n";
	_getche();
	cout << "이 고리들은 전세계에 512개가 숨겨져 있으며 이 고리 중에 256개를 손에 넣어야 이 컴퓨터가 있는 장소에 접근할 수 있다.\n";
	_getche();
	cout << "그래서 플레이어(당신)는 인간의 대표로서 인간이 다시 평화를 손에 넣기 위해 고리 256개 이상을 모으는 임무를 받았다.\n";
	_getche();
	cout << "하지만 그때 이 소식을 'A'가 들어버렸고 'A'는 다른 부하 인공지능들에게 명령을 하여 이 고리를 회수하려 한다.\n";
	_getche();
	cout << "과연 플레이어(당신)는 다른 인공지능들보다 더 고리를 많이 차지할 수 있을 것인가..\n";
	_getche();
	cout << "당신의 플레이에 세계의 평화가 달려있다...\n";
	_getche();
	cout << "게임을 시작하려면 아무키나 누르세요..";
	_getche();
	system("cls");

	int i;
	cout << "난이도를 입력하세요\n";
	cout << "1. 난이도 下\n";
	cout << "2. 난이도 中\n";
	cout << "3. 난이도 上\n\n";
	cout << "난이도 선택해주세요 : ";
	cin >> i;  //난이도 입력

	if (i == 1)
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
			cout << "게임 저장을 위해 아무키나 누르세요...\n";
			_getche();
			rank.add(player1->nItem, player1->nItem / player1->total);  //this 포인터를 이용하여 Player1의 nItem과 nItem / total을 랭킹 순위에 올립니다. 
			rank.print("[게임 랭킹: 종료]");
			rank.store("AIWorld1.rnk");
		}
		else
		{
			cout << "패배하였습니다\n";
			cout << "아쉽게도 지구는 AI에게 정복을 당했습니다.\n";
			cout << "아무키나 눌러서 게임을 종료하십시오..";
			_getche();
		}
		return 0;
	}
	if (i == 2)  //주석으로 인한 설명은 위와 동일
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
			cout << "게임 저장을 위해 아무키나 누르세요...\n";
			_getche();
			rank.add(player1->nItem, player1->nItem / player1->total);
			rank.print("[게임 랭킹: 종료]");
			rank.store("AIWorld2.rnk");
		}
		else
		{
			cout << "패배하였습니다\n";
			cout << "아쉽게도 지구는 AI에게 정복을 당했습니다.\n";
			cout << "아무키나 눌러서 게임을 종료하십시오..";
			_getche();
		}
		return 0;
	}
	if (i == 3)  //주석으로 인한 설명은 위와 동일
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
			cout << "게임 저장을 위해 아무키나 누르세요...\n";
			rank.add(player->nItem, player->nItem / player->total);
			rank.print("[게임 랭킹: 종료]");
			rank.store("AIWorld3.rnk");
		}
		else
		{
			cout << "패배하였습니다\n";
			cout << "아쉽게도 지구는 AI에게 정복을 당했습니다.\n";
			cout << "아무키나 눌러서 게임을 종료하십시오..";
			_getche();
		}
		return 0;
	}
}

