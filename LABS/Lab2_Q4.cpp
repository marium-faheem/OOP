#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class HittingGame {
private:
    int players;
    int yourHits;
    int enemyHits;

public:
    // Constructor
    HittingGame() {
        srand(time(0));
        players = rand() % 5 + 1;   // Random players between 1–5
        yourHits = 0;
        enemyHits = 0;
    }

    void playGame() {
        cout << "Total No. Of Players in your team: " << players << endl;

        for (int i = 1; i <= players; i++) {
            int num1 = rand() % 5 + 1;
            int num2 = rand() % 5 + 1;

            cout << "\nPair of numbers:\n";
            cout << "Number1: " << num1 << endl;
            cout << "Number2: " << num2 << endl;

            if (num1 == num2) {
                cout << "Enemy got hit by your team!" << endl;
                yourHits++;
            } else {
                cout << "You got hit by the enemy team!" << endl;
                enemyHits++;
            }
        }

        displayResult();
    }

    void displayResult() {
        cout << "\nGame Over!" << endl;

        if (yourHits > enemyHits)
            cout << "You won" << endl;
        else if (yourHits < enemyHits)
            cout << "Enemy won" << endl;
        else
            cout << "Match Draw" << endl;
    }
};

int main() {
    HittingGame game;
    game.playGame();
    return 0;
}