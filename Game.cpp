#include "AIWorld.h"
#include "AIKinds.h"
#include "Player.h"
#include "RankingBoard.h"
#include <time.h>
#include "Notice_and_story.h"
#include "Start_Game.h"

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

int main(void) {
    Rules_Notice();
    displayStory();
    while (true) {
        int i = getDifficulty();
        Start_Game(i);

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