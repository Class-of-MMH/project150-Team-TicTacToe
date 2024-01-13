#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

const char blank = ' ';
const char ball = 'O';
const char player = 'P';

void playSound(const char* soundFile, DWORD flags = SND_FILENAME | SND_ASYNC) {
    PlaySound(TEXT(soundFile), NULL, flags);
}

int main() {
    srand(time(0));

    // Play background sound at the beginning of the game
   playSound("backsound.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);

    int rst = 1;
    char move = 's';

    while (rst && move == 's') {
             playSound("backsound.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);
        move = ' ';
        int bsz, lev; // board size and level
        cout << "Choose a level: \n 1. easy   2. medium   3. hard\n press a number 1/2/3: ";
        cin >> lev;
        if (lev == 1)
            bsz = 4;
        else if (lev == 2)
            bsz = 6;
        else
            bsz = 10;

        char brd[10][10]; // board
        int prow = bsz - 1; // last row te
        int pcol = bsz / 2; // middle e nambe at first
        int brow = 0;       // first row te ball
        int bcol = rand() % bsz; // less than board size, array er index ball

        for (int row = 0; row < bsz; ++row) {
            for (int col = 0; col < bsz; ++col) { // column ar row same size
                brd[row][col] = ' ';                // at first empty kora
            }
        }
        brd[prow][pcol] = player; // player icon p
        brd[brow][bcol] = ball;   // ball icon o

        // game shesh na cholbe oitar jonno
        int score = 0, life = 3, replay = 1;

        while (replay) {
            if (move == 'e' || move == 's')
                break;
                int rpl=0;// repay loop er under e ami replay 1 dile replay hobe


            for (int pl = 0; pl < life; pl++) {
                bool gameRunning = true;

                if (move == 'e' || move == 's')
                    break;

                if (pl) {
                    brd[prow][bcol] = ' '; // ager ta clean korbo
                    brow = 0;              // abar ball porbe
                    bcol = rand() % bsz;
                    brd[brow][bcol] = ball; // ball set
                  playSound("nocatchsound.wav");
                }

                while (gameRunning) { // jotokkon true
                    system("cls");      // notun kore

                    for (int row = 0; row < bsz; ++row) {
                        for (int col = 0; col < bsz; ++col) {
                            cout << brd[row][col] << " "; // print kora
                        }
                        cout << endl;
                    }

                    cout << "Your score: " << score << endl;
                    cout << "life left: " << 3 - pl << " ( ";
                    for (int ii = 0; ii < (3 - pl); ii++) {
                        cout << "<3  ";
                    }
                    for (int ii = 0; ii < (pl); ii++) {
                        cout << "X  ";
                    }
                    printf(")\n  ");
                    cout << "Enter your move (l - left, r- right, n- no move, e- exit, s- restart): ";
                    cin >> move; // left right input

                    // Play move sound for each move
                    playSound("movesound.wav");

                    brd[prow][pcol] = blank; // nw position e jabe ager position empty

                    if (move == 'l' && pcol > 0) {
                        --pcol; // bame
                    } else if (move == 'r' && pcol < bsz - 1) {
                        ++pcol; // daane
                    }
                    if (move == 's') {
                        score = -1;
                        pl = 0;
                    }

                    brd[prow][pcol] = player; // new position

                    brd[brow][bcol] = blank; // ager positon e ball nei

                    if (brow >= prow - 2) {
                        ++brow;
                    } else {
                        int direction = rand() % 2;
                        if (direction == 0 && bcol > 0) {
                            --bcol;
                        } else if (direction == 1 && bcol < bsz - 1) {
                            ++bcol;
                        }
                        ++brow;
                    }

                    // Play catch sound when the ball is caught
                    if (brow == prow && bcol == pcol) {
                        ++score;
                        brow = 0;
                        bcol = rand() % bsz;
                        playSound("catchsound2.wav");//catch korar pore
                    }
                    brd[brow][bcol] = ball;

                    if (brow == bsz - 1 || move == 'e' || move == 's') {

                        gameRunning = false;
                    }
                }
            }
            system("cls");
            if (move != 's') {
                if (move != 'e') {
                    // game over howar por sound
                    playSound("gameover.wav");

                    cout << "life left : 0 " << endl
                         << "Game over! Your score: " << score << endl;
                    replay = 0;
                    cout << "Wanna play again? press 1 to replay -";
                    cin >> replay;
                    if(replay)// replay er por ball jate upore jai, replay er value 1
                    {
                    brd[prow][bcol] = ' '; // ager ta clean korbo
                    brow = 0;              // abar ball porbe
                    bcol = rand() % bsz;
                    brd[brow][bcol] = ball; // ball set

                }
                }
            }
            system("cls");
        }
    }

    return 0;
}
