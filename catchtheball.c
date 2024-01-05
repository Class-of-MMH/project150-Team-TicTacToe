#include <stdio.h>
#include <stdlib>
#include <time>



const char blank = ' ';
const char ball = 'O';
const char player = 'P';

int main(){
srand(time(0));

int bsz,lev ; // board size and level
scanf("Choose a level: \n 1. easy   2. medium   3. hard\n press a number 1/2/3: %d",&lev);
if(lev==3) bsz=4; else if(lev==2) bsz=6; else bsz=10;


char brd[bsz][bsz]; // board
int prow = bsz - 1;// last row te
 int pcol = bsz/ 2;// middle e nambe at first
int brow = 0;// first row te ball
 int bcol = rand() % bsz;// less than board size, array er index ball  


 for (int i= 0; i < bsz; i++) {
 
}
