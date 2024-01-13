#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>

using namespace std;

const int bsz = 16;

const int brdcol=16;
const int brdrow=20;
const char blank = ' ';
const char ball = 'o';
const char player = 'U';


void playSound(const char* soundFile, DWORD flags = SND_FILENAME | SND_ASYNC) {
    PlaySound(TEXT(soundFile), NULL, flags);
}

int main() {
    srand(time(0));

    
   playSound("backsound.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);

    int rst = 1;
    char move = 's';


    while (rst && move == 's') { //restart

             playSound("backsound.wav", SND_FILENAME | SND_ASYNC | SND_LOOP);// bgm


        move=' ';
       int lev ; // board size and level
          cout <<"Choose a level: \n 1. easy   2. medium   3. hard\n press a number 1/2/3: ";
           cin >>lev;
//if(lev==1) bsz=4; else if(lev==2) bsz=6; else bsz=10;

          int speed=lev;

char brd[brdrow][brdcol]; // board
int prow = brdrow - 2;// last row te
 int pcol = 10;// middle e nambe at first
int brow = 2;// first row te ball
 int bcol = (rand() % 10)+5;// less than board size, array er index ball

       for (int row = 0; row < brdrow; ++row) {
       for (int col = 0; col < brdcol; ++col) {// column ar row same size
                 if (row==0){ brd[row][col] = ' ';} // ek line faka
                  else if ((row==1  &&col>3)){brd[row][col] = '~';}// upore cloud
                    else if ((row==brdrow-1  &&col>3)){brd[row][col] = 219;}// rasta down e
                       else if(col==4 || col==15) {brd[row][col] = 186;}// nice deyal side e
                             else{
                              brd[row][col] = ' ';} // at first empty kora
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
                   brow = 2;// abar ball porbe
                   bcol = (rand() % 10)+5;
                    brd[brow][bcol] = ball; // ball set
                  playSound("nocatchsound.wav");
                }

                while (gameRunning) { // jotokkon true
                    system("cls");      // notun kore

                    for (int row = 0; row < brdrow; ++row) {
                        for (int col = 0; col < brdcol; ++col) {
                            cout << brd[row][col] << " "; // print kora
                        }
                        cout << endl;
                    }

                    cout << endl << "Your score: " << score << endl;
                    cout << "life left: " << 3 - pl << " ( ";
                    for (int ii = 0; ii < (3 - pl); ii++) {
                        cout << "<3  ";
                    }
                    for (int ii = 0; ii < (pl); ii++) {
                        cout << "X  ";
                    }
                    printf(")\n  ");
                    cout << "Enter your move (l - left, r- right, n- no move, s- restart, e- exit): ";
                    cin >> move; // left right input

                    // Play move sound for each move
                    playSound("movesound.wav");

                    brd[prow][pcol] = blank; // nw position e jabe ager position empty




                   if (brow >= prow-2) { //move er jonno, last er dui ta er jonno na

  if (move == 'l' && pcol > 5) { // karon board 5 theke
 --pcol;// bame
 } else if (move == 'r' && pcol < brdcol-2) {// laste e deyal ase tai 2, move er jonno
 ++pcol;// daane
 }
 }

  else
    {
  speed=lev;// speed barano, level shoman ghor jabe
while(speed--)// ek e kaj koyrkbar, speed
 {
 if (move == 'l' && pcol > 5) {
 --pcol;// bame
 } else if (move == 'r' && pcol < brdcol- 2) {
 ++pcol;// daane
 }
 }
    }


if (move=='s') { score=-1; pl=0; }


 brd[prow][pcol] = player;// new position

 brd[brow][bcol] = blank;//ager positon e ball nei




  if (brow >= prow-2) { // direction cng according to speed, not last two step
 ++brow;
 } else {
  speed=lev;// speed barano, level shoman ghor jabe
while(speed--) // ball o druto jabe    // speed and direction cng
 {


 int direction = rand() % 2;
 if (direction == 0 && bcol > 5) {
--bcol;
 }
 else if (direction == 1 && bcol < brdcol - 2 ) {
++bcol;
 }
 ++brow;
 }
 }
                    if (brow == prow && bcol == pcol) {
                        ++score;
                         brow = 2;// abar ball porbe
                          bcol = (rand() % 10)+5; // rand jaiga theke porbe
                        playSound("catchsound2.wav");//catch korar pore
                    }
                    brd[brow][bcol] = ball;

                    if (brow == brdrow - 2 || move == 'e' || move == 's') {

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
                    if(replay)
                    {
                    brd[prow][bcol] = ' '; // ager ta clean korbo
                     brow = 2;
                     bcol = (rand() % 10)+5;
                    brd[brow][bcol] = ball; // ball set

                }
                }
            }
            system("cls");
        }
    }

    return 0;
}
