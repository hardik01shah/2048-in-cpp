#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<math.h>
#include<graphics.h>
#include<process.h>
#include<dos.h>
#include<stdlib.h>
#include<bios.h>
#include<time.h>

struct backup
{
double B[6][6];
}C[2];

struct
{
int I;
int J;
}INSERT[16];

int maxx,maxy,midx,midy,i,j,k,m,n,c,undo;
double A[6][6];
char NUM[][5]={"2","4","8","16","32","64","128","256","512","1024","2048"};

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
			bar(midx-196+(100*j),midy-196+(100*i),midx-104+(100*j),midy-104+(100*i));

			setcolor(n);
			setfillstyle(1, n);
			bar(midx-196+(100*j),midy-196+(100*i),midx-104+(100*j),midy-104+(100*i));

			setcolor(0);
			outtextxy(midx-150+(100*j), midy-150+(100*i),NUM[n-1]);
			}

			else
			{
			setfillstyle(1,0);
			setcolor(0);
			bar(midx-196+(100*j),midy-196+(100*i),midx-104+(100*j),midy-104+(100*i));
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

				for(k=j+1;k<4;k++)
				A[i][k]=A[i][k+1];

			A[i][3]=0;
			}
		}
	}
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
				for(k=j-1;k>=0;k--)
				A[i][k]=A[i][k-1];
			A[i][0]=0;
			}
		}
	}
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
				for(k=j+1;k<4;k++)
				A[k][i]=A[k+1][i];
			A[3][i]=0;
			}
		}
	}
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
				for(k=j-1;k>=0;k--)
				A[k][i]=A[k-1][i];
			A[0][i]=0;
			}
		}
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
midy=maxy/2;

int X[]={2,2,4,4,2,4,2,2,4};
int key,a,b,new1,new2,new3;
int tp=0,flag=1,over;

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
		A[i][j]=0;
		C[1].B[i][j]=0;
		C[0].B[i][j]=0;
		}
	}

	for(i=0;i<16;i++)
	{
	INSERT[i].I=0;
	INSERT[j].J=0;
	}

setfillstyle(1,15);

	// for grid
	for(i=-2;i<=2;i++)                                       //columns
	bar(midx+(100*i)-2,midy-202,midx+(100*i)+2,midy+202);
	for(i=-2;i<=2;i++)
	bar(midx-200,midy+(100*i)-2,midx+200,midy+(100*i)+2);    //rows

settextjustify(1,1);
settextstyle(0,0,3);

new1=random(4);
new2=random(4);
new3=random(9);

A[new1][new2]=X[new3];
C[1].B[new1][new2]=X[new3];

print();

	while(tp==0)
	{
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

		if(flag!=0 && a!=0)
		{
		new1=random(9);
		new2=random(a);

		A[INSERT[new2].I][INSERT[new2].J]=X[new1];

			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				C[0].B[i][j]=C[1].B[i][j];
			}

			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				C[1].B[i][j]=A[i][j];
			}


		print();
		}

		for(i=0;i<4;i++)
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

		else if(key==5749||key==5717)	//undo: U or u
		{
		undo=0;
			for(i=0;i<4;i++)
			{
				for(j=0;j<4;j++)
				A[i][j]=C[0].B[i][j];
			}
		}

		else if(key==7181 || key==283)	 //exit: enter key or esc
		exit(0);

		if(undo!=0)
		{
			if(key==18432 || key==20480 || key==19712 || key==19200)
			{
				for(i=0;i<4;i++)
				{
					for(j=0;j<4;j++)
					{
						if(C[1].B[i][j]!=A[i][j])
						{
						flag++;
						break;
						}
					}
				}
			}
		}

		if(flag!=0 || undo==0)
		print();
	}


cleardevice();
cout<<"GAME OVER!!!";
getch();
closegraph();
}