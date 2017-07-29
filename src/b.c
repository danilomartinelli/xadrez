#include <stdio.h>
#include <conio.h>

int left;            //left edge of board
int right;          //right edge of board
int width;        //width of square in cols
int top;	      //top row
int bottom;     //bottom row
int row;
int col;
int board[8][10]; 	//the current playing board-it is 10 columns wide to allow the
//use of pairs of digits for representing the board in this array see page 159 in
//How Computers Play Chess
int number;

int main(void)  {
  void Newboard();
  int i;

  left=2;               //left edge of board
  right=left+40;     //right edge of board
  width=5;            //width of square in cols
  top=2;	           //top row
  bottom=top+16; //bottom row

   Newboard();
   i = getchar(); ++i;
   return 0;
 }
void Newboard() {
  void Drawsq(char sqr, int col, int row);
  void Putpieces();
  const unsigned char bsqr = '\xB0';  	//black square
  const unsigned char wsqr = '\xB2';	//white square
  unsigned char sqr= wsqr;
  int j, color = 0;

  for(row=0;row<8;row++) {
    for(col=0;col<10;col++)
	    board[row][col] = 0;
      if(row==0) {
        board[row][0]=4;board[row][1]=2;board[row][2]=3;
        board[row][3]=5;board[row][4]=6;board[row][5]=3;
        board[row][6]=2;board[row][7]=4;board[row][8]=99;
        board[row][9]=99;
      }
      if(row==1) {
        board[row][0]=1;board[row][1]=1;board[row][2]=1;
        board[row][3]=1;board[row][4]=1;board[row][5]=1;
        board[row][6]=1;board[row][7]=1;board[row][8]=99;
        board[row][9]=99;
      }
      if(row==6) {
        board[row][0]=-1;board[row][1]=-1;board[row][2]=-1;
        board[row][3]=-1;board[row][4]=-1;board[row][5]=-1;
        board[row][6]=-1;board[row][7]=-1;board[row][8]=99;
        board[row][9]=99;
      }
      if(row==7) {
        board[row][0]=-4;board[row][1]=-2;board[row][2]=-3;
        board[row][3]=-5;board[row][4]=-6;board[row][5]=-3;
        board[row][6]=-2;board[row][7]=-4;board[row][8]=99;
        board[row][9]=99;
      }
  } //end of for row (for col is not braced)
  clrscr();
  for(row=top;row<bottom;row+=2) {
    if (color>0) {	//swap color of sqr every row
     color=0;
     if(sqr==wsqr)
       sqr=bsqr;
     else
       sqr=wsqr;
    }
    for(col=left;col<right;col+=5) {
      gotoxy(col,row);
      Drawsq(sqr, col, row);
      color ++;
	    if (color>0) {
        color=0;
	      if(sqr==wsqr) 		//swap color of sqr every col too
	        sqr=bsqr;
	      else
	        sqr=wsqr;
	    }//end of if
	  } //end of for col
    color ++;
  } //end of for row
  Putpieces();
}
void Drawsq(char sqr, int col, int row)  {
  int j;
  gotoxy(col, row);  	            //top half of sqr
  for(j=0; j<5; j++)
    putch(sqr); 	                   //each square is 5 cols X 2 rows
  gotoxy(col,row+1);
  for(j=0; j<5; j++)		//lower half of sqr
    putch(sqr);

   number++;
   gotoxy(30,20);
     printf("Been Here %d Times", number);
  }
void Putpieces()  {
  int j, k, midrow, midcol;
  midrow=bottom-2;
  midcol=left+2;
  for(k=0;k<8;k++) {
    for(j=0;j<8;j++) {
      gotoxy(midcol,midrow);
    	if(board[k][j]!=0)
        printf("%d",board[k][j]);
    	midcol+=width;
    }
    midcol=midcol-(8*width);
    midrow-=2;
  }
}
