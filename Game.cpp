#include "AIWorld.h"
#include "AIKinds.h"
#include "Player.h"
#include "RankingBoard.h"
#include <time.h>
#include "Notice_and_story.h"

void waitForSpaceKey() {
    while (true) {
        char key = _getch();
        if (key == ' ') {
            break;
        }
    }
}

int getDifficulty() {
	int difficulty;
	cout << "========================================\n";
	cout << "             난이도 선택                \n";
	cout << "========================================\n";
	cout << "1. 난이도 下\n";
	cout << "2. 난이도 中\n";
	cout << "3. 난이도 上\n";
	cout << "========================================\n";
	cout << "난이도를 선택하세요: ";
	cin >> difficulty;
	return difficulty;
}

void handleRankingBoard(RankingBoard& rank, const string& filename) {
    try {
        rank.load(filename);
    }
    catch (FileException e) {
        char str[80];
        string passwd, correct = "0000";
        cout << "0을 4개 누르세요";
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
}

template <typename T>
void startGame(int difficulty, const string& filename) {
    RankingBoard rank;
    handleRankingBoard(rank, filename);

    srand((unsigned int)time(NULL));
    int w = 32, h = 16;

    T game(w, h);
    game.add(new Siri("손이시려워", "§", rand() % w, rand() % h));
    game.add(new Bixby("하이빅스비", "◆", rand() % w, rand() % h));
    game.add(new Alexa("알렉사라구", "♥", rand() % w, rand() % h));
    game.add(new Watson("가로로왓슨", "↔", rand() % w, rand() % h, true));
    game.add(new Watson("세로로왓슨", "↕", rand() % w, rand() % h, false));
    if (difficulty > 1) {
        game.add(new Cotana("코타나래요", "±", rand() % w, rand() % h));
        game.add(new GigaGenie("기가지니야", "■", rand() % w, rand() % h));
    }

    Player* player = new Player("플레이어", "♀", rand() % w, rand() % h);
    game.add(player);
    game.play(1000, 10);
    printf("------게임 종료---------------------\n");

    if (player->nItem > 256) {
        cout << "승리하였습니다\n";
        cout << "당신으로 인해 지구는 평화를 찾게 되었습니다.\n";
        cout << "게임 저장을 위해 스페이스 키를 누르세요...\n";
        waitForSpaceKey();  // 스페이스 키 대기
        rank.add(player->nItem, player->nItem / player->total);
        rank.print("[게임 랭킹: 종료]");
        rank.store(filename);
    }
    else {
        cout << "패배하였습니다\n";
        cout << "아쉽게도 지구는 AI에게 정복을 당했습니다.\n";
        cout << "스페이스 키를 눌러서 게임을 종료하십시오...\n";
        waitForSpaceKey();  // 스페이스 키 대기
    }
}

int main(void) {
    Rules_Notice();
    displayStory();
    while (true) {
        int i = getDifficulty();
        string filename = "AIWorld" + to_string(i) + ".rnk";

        if (i == 1) startGame<AIWorld>(i, filename);
        else if (i == 2) startGame<AIWorld2>(i, filename);
        else startGame<AIWorld3>(i, filename);

        cout << "R키를 누르면 다시 시작하고, Q키를 누르면 종료합니다...\n";
        char key;
        do {
            key = _getche();
            if (key == 'Q' || key == 'q') return 0;
            system("cls");
        } while (key != 'R' && key != 'r');
    }
    return 0;
}