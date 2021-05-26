////////////////////////////////// 2048 GAME ///////////////////////////////////
////////////////// A Project by Hardik, Mridul and Jainil /////////////////////

#include <iostream.h>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <graphics.h>
#include <process.h>
#include <dos.h>
#include <stdlib.h>
#include <bios.h>
#include <time.h>

class backup  // for use in undo function
{       public:
	double B[6][6];
	int bscore;
}C[2];

class  newposn
{
	public:
	int I;
	int J;
}INSERT[16];

class
{
	public:
	char name[20];
	int score_save;
} HIGHSCORES[10];

int maxx,maxy,midx,midy,i,j,k,m,n,c,AA=0,MM=0,undo, score=0;
double A[6][6];

// A character array to use in outtextxy function
char NUM[][5]={"2","4","8","16","32","64","128","256","512","1024","2048"};
char basearray[][10]={"0","1","2","3","4","5","6","7","8","9"};
// Array to insert random numbers after each move
// Notice that probability of 2 is more than 4
int X[]={2,2,4,4,2,4,2,2,4};

int key,a,b,new1,new2,new3;
int tp=0,flag=1,over=1;

void convert()
{
	int x,X;
	int number[12],r, p1=0;
	//char numberC[10];

	x=score;
	X=C[0].bscore;

	while (x > 0)
	{
		r=x%10;
		x=x/10;
		number[p1]=r;
		p1++;
	}           /*

	while (X > 0)
	{
		R=X%10;
		X=X/10;
		number1[P1]=R;
		P1++;
	}
		      */

	gotoxy(5,15);

	for(i=0; i<p1; i++)
	   {
	   setcolor(GREEN);
	   settextstyle(0,0,2);
	  outtextxy(100,100+AA,basearray[number[p1-i-1]]);

	   setcolor(BLUE);
	   settextstyle(0,0,2);
	  outtextxy(100+MM,100+AA,basearray[number[p1-i-1]]);
	  MM+=10;
	      }
	      AA+=20;
}


void print()
{
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
		m=A[i][j];
		n=0;

			if(m!=0)
			{
			n=log10(m)/log10(2);

			setfillstyle(1,0);
			bar(midx-156+(80*j),midy-156+(80*i),midx-84+(80*j),midy-84+(80*i));

			setcolor(n);
			setfillstyle(1, n);
			bar(midx-156+(80*j),midy-156+(80*i),midx-84+(80*j),midy-84+(80*i));

			setcolor(0);
			outtextxy(midx-120+(80*j), midy-120+(80*i),NUM[n-1]);
			}

			else
			{
			setfillstyle(1,0);
			setcolor(0);
			bar(midx-156+(80*j),midy-156+(80*i),midx-84+(80*j),midy-84+(80*i));
			}
		}
	}
}

void left()     //left arrow key
{
	for(c=0;c<2;c++)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(A[i][j]==0)
				{
					for(k=j;k<4;k++)
					A[i][k]=A[i][k+1];

				A[i][3]=0;
				}
			}
		}
	}

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(A[i][j]==A[i][j+1])
			{
				A[i][j]*=2;
				score+=A[i][j];

				for(k=j+1;k<4;k++)
					A[i][k]=A[i][k+1];

				A[i][3]=0;
			}
		}
	}
    //	C[1].bscore=score;
}

void right()    ///right arrow key
{
	for(c=0;c<2;c++)

	{
		for(i=0;i<4;i++)
		{
			for(j=3;j>=0;j--)
			{
				if(A[i][j]==0)
				{
					for(k=j;k>=0;k--)
					A[i][k]=A[i][k-1];
				A[i][0]=0;
				}
			}
		}
	}

	for(i=0;i<4;i++)
	{
		for(j=3;j>=0;j--)
		{
			if(A[i][j]==A[i][j-1])
			{
			A[i][j]*=2;
			score+=A[i][j];
				for(k=j-1;k>=0;k--)
				A[i][k]=A[i][k-1];
			A[i][0]=0;
			}
		}
	}
  //	C[1].bscore=score;
}

void up()	//up arrow key
{
	for(c=0;c<2;c++)
	{
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(A[j][i]==0)
				{
					for(k=j;k<4;k++)
					A[k][i]=A[k+1][i];
				A[3][i]=0;
				}
			}
		}
	}

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(A[j][i]==A[j+1][i])
			{
			A[j][i]*=2;
			score+=A[j][i];
				for(k=j+1;k<4;k++)
				A[k][i]=A[k+1][i];
			A[3][i]=0;
			}
		}
	}
  //	C[1].bscore=score;
}

void down()	//down arrow key
{
	for(c=0;c<2;c++)
	{
		for(i=0;i<4;i++)
		{
			for(j=3;j>=0;j--)
			{
				if(A[j][i]==0)
				{
					for(k=j;k>=0;k--)
					A[k][i]=A[k-1][i];
				A[0][i]=0;
				}
			}
		}
	}

	for(i=0;i<4;i++)
	{
		for(j=3;j>=0;j--)
		{
			if(A[j][i]==A[j-1][i])
			{
			A[j][i]*=2;
			score+=A[j][i];
				for(k=j-1;k>=0;k--)
				A[k][i]=A[k-1][i];
			A[0][i]=0;
			}
		}
	}
//	C[1].bscore=score;
}

void loadscreen()
{
	cleardevice();
	int endangle,radius=110,t=0,x;
	setcolor(2);
	settextjustify(CENTER_TEXT,CENTER_TEXT);
	char h[][40]={"defining variables","loading header files...",
		    "#include<iostream.h>","#include<conio.h>","#include<string.h>",
		    "#include<stdio.h>","#include<math.h>","#include<graphics.h>",
		    "#include<process.h>","#include<dos.h>","#include<stdlib.h>",
		    "creating functions","loading 2048","defining database","extracting directory",
		    "printing virtual grid","loading homescreen"};

	setcolor(4);
	settextstyle(6,HORIZ_DIR,6);
	for(i=0;i<=4;i++)
	outtextxy(midx-2+i,midy+170,"...LOADING...");

	settextstyle(0,HORIZ_DIR,4);
	outtextxy(midx,50,"A VENTURE BY");


	setcolor(2);
	settextstyle(0,HORIZ_DIR,4);
	outtextxy(midx,midy-35,"HaMrJ");

	settextstyle(6,HORIZ_DIR,3);
	outtextxy(midx,midy,"PRODUCTIONS");


	for(endangle=90;endangle<=450;endangle++)
	{
		delay(8);
		setcolor(2);
		arc(midx, midy-30,90, endangle, radius);

		for(i=0;i<=10;i++)
			arc(midx, midy-30,90, endangle, radius-i);

		x=endangle%20;

		if(x==0)
		{
			setfillstyle(1,0);
			bar(midx-150,midy+100,midx+150,midy+140);
			setcolor(2);
			settextstyle(6,HORIZ_DIR,3);
			outtextxy(midx,midy+120,h[t]);
			t++;x++;
		}

	}

	setcolor(2);
	settextstyle(6,HORIZ_DIR,5);
	for(i=0;i<=4;i++)
	outtextxy(midx-2+i,midy+120,"READY!");
	delay(800);
}

void initialize()
{
	for(i=0;i<4;i++)                      // to clear the grid
	{
		for(j=0;j<4;j++)
		{
			A[i][j]=0;
			C[1].B[i][j]=0;
			C[0].B[i][j]=0;
			C[1].bscore=0;
			C[0].bscore=0;
		}
	}

	for(i=0;i<16;i++)
	{
		INSERT[i].I=0;
		INSERT[j].J=0;
	}

      //	loadscreen();
	setfillstyle(1,15);

	cleardevice();



	// for grid
	for(i=-2;i<=2;i++)                                       //columns
		bar(midx+(80*i)-1,midy-161,midx+(80*i)+1,midy+161);
	for(i=-2;i<=2;i++)                                       // rows
		bar(midx-161,midy+(80*i)-1,midx+161,midy+(80*i)+1);

	settextjustify(1,1);
	setcolor(2);
	settextstyle(0,0,4);
	outtextxy(midx,midy-15-210,"2048");
	settextstyle(0,0,2);

	for(i=0;i<2;i++)
	{
	new1=random(4);
	new2=random(4);
	new3=random(9);

	A[new1][new2]=X[new3];
	C[1].B[new1][new2]=X[new3];
	C[1].bscore=score;

	print();
	}
}

void UNDO()
{

	undo=0;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			A[i][j]=C[0].B[i][j];
	}
	score=C[0].bscore;
	C[1].bscore=C[0].bscore;


	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
			C[1].B[i][j]=C[0].B[i][j];
	}
	print();
}

void game( int decider )
{

	while(tp==0)
	{
	       convert();
		flag=0;
		undo=1;

		while (bioskey(1) == 0);
		key = bioskey(0);

		if(key==19200)  		//left arrow
			left();

		else if(key==19712)  	 	//right arrow key
			right();

		else if(key==18432)     	//up arrow key
			up();

		else if(key==20480)  		//down arrow key
			down();

		else if((key==5749||key==5717) && decider==0)	//undo: U or u
			UNDO();

		else if(key==7181 || key==283)	 //exit: enter key or esc
			exit(0);

		else
			goto end;

		if(undo!=0)
		{
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				{
					if(C[1].B[i][j]!=A[i][j])
						flag++;

				}
			}
		}

		a=0;
		over=0;

		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			{
				if(A[i][j]==0)
				{
					INSERT[a].J=j;
					INSERT[a].I=i;
					a++;
				}
			}
		}


		if(a!=0 && undo!=0)
		{
			if(flag!=0)
			{
				new1=random(9);
				new2=random(a);

				A[INSERT[new2].I][INSERT[new2].J]=X[new1];

				for(i=0;i<4;i++)
				{
					for(j=0;j<4;j++)
						C[0].B[i][j]=C[1].B[i][j];
				}

				C[0].bscore=C[1].bscore;
				C[1].bscore=score;

				for(i=0;i<4;i++)
				{
					for(j=0;j<4;j++)
						C[1].B[i][j]=A[i][j];
				}

				print();
			}


		}

		for(i=0;i<4;i++)  //to check end of game
		{
			for(j=0;j<4;j++)
			{
				if(A[i][j]==0)
					over++;

				if(A[i][j]==A[i][j+1] || A[i][j]==A[i+1][j])
					over++;

			}
		}

		if(over==0)
		{
			getch();
			break;
		}

		end:
	}
}


void main()
{
	/* request auto detection */
	int gdriver = DETECT, gmode, errorcode;

	/* initialize graphics and local variables */
	initgraph(&gdriver, &gmode, "c:\\turboc3\\bgi");

	/* read result of initialization */
	errorcode = graphresult();

	if (errorcode != grOk)  /* an error occurred */
	{
		   printf("Graphics error: %s\n", grapherrormsg(errorcode));
		   printf("Press any key to halt:");
		   getch();
		   exit(1); /* terminate with an error code */
	}
	randomize();

	maxx=getmaxx();
	maxy=getmaxy();
	midx=maxx/2;
	midy=(maxy/2)+15;

	initialize();

	game(0);

	cleardevice();
	cout<<"GAME OVER!!!";
	getch();
	closegraph();
}