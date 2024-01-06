#include <stdio.h>
#include <stdlib.h>
#include <time.h>



const char blank = ' ';
const char ball = 'O';
const char player = 'P';

int main(){
srand(time(0));
int rst=1;
char move='s';

while(rst && move=='s')
{

move=' ';
int bsz,lev ; // board size and level
printf("Choose a level: \n 1. easy   2. medium   3. hard\n press a number 1/2/3:");
scanf("%d",&lev);
if(lev==1) bsz=4; else if(lev==2) bsz=6; else bsz=10;


char brd[bsz][bsz]; // board
int prow = bsz - 1;// last row te
 int pcol = bsz/ 2;// middle e nambe at first
int brow = 0;// first row te ball
 int bcol = rand() % bsz;// less than board size, array er index ball


 for (int i= 0; i < bsz; i++) {
 for (int j = 0; j < bsz; j++) {// column ar row same size
brd[i][j] = ' '; // at first empty kora
 }
}

brd[prow][pcol] = player;// player icon p
 brd[brow][bcol] = ball; // ball icon o

// game shesh na cholbe oitar jonno
int score=0, life=3, replay=1;



while(replay)
{

 if(move== 'e' ||move== 's' ) break;
for(int pl=0;pl<life;pl++){
        int gameRunning= 1;

if(move== 'e' ||move== 's' ) break;

if(pl){
    brd[prow][bcol] = ' ';// ager ta clean korbo
        brow = 0;// abar ball porbe
 bcol = rand() % bsz;
brd[brow][bcol] = ball; // ball set
 }
 while(gameRunning){ // jotokkon true


 system("cls");// notun kore screen

for (int ii = 0; ii < bsz; ii++) {
 for (int jj = 0; jj < bsz; jj++) {
 printf("%c ",brd[ii][jj]) ;// print kora
 }
 printf("\n");
 }

 printf("Your score: %d \n",score); // protibar score update
 printf("life left:  %d  (",3-pl); // life kombe

 for (int ii = 0; ii <(3-pl) ; ii++) { printf(" <3  "); }
 for (int ii = 0; ii <(pl) ; ii++) { printf("X  "); }
 printf(")\n  ");
   printf( "Enter your move (l - left, r- right, n- no move, e- exit, s- restart): ");
  scanf("%c",&move); // left right input

  brd[prow][pcol] = blank;// nw position e jabe ager position empty

 if (move == 'l' && pcol > 0) { //left command jokhon player left most e nai
 pcol--;// bame
 } else if (move == 'r' && pcol < bsz - 1) { // right most e max index eita
 pcol++;// daane
 }
if (move=='s') { score=-1; pl=0; } // restart er jonno
 brd[prow][pcol] = player;// new position

 brd[brow][bcol] = blank;//ager positon e ball nei


 if (brow >= prow-2) {
 ++brow;
 } else {

 int direction = rand() % 2;
 if (direction == 0 && bcol > 0) {
--bcol;
 }
 else if (direction == 1 && bcol < bsz - 1) {
++bcol;
 }
 ++brow;
 }

 if (brow == prow && bcol == pcol  ) { // point peyeche as dhorse
score++;
 brow = 0;
 bcol = rand() % bsz;
 }
brd[brow][bcol] = ball;// abar shuru


if (brow == bsz - 1 || move=='e'|| move=='s') { // exit dile or miss hole
 gameRunning = 0; // while loop bhangte, life kmbe
 }


}
}

system("cls");
 if (move!='s')
 {
  if (move!='e')

{printf("life left : 0  \n Game over! Your score: %d\n" , score );
replay=0;
printf("Wanna play again? press 1 to replay -" ) ;
scanf("%d",&replay);}}

system("cls");
}
}

return 0;

}
