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
int B[4][4];
}C[2];

struct
{
int I;
int J;
}INSERT[16];

int maxx,maxy,midx,midy,i,j,k,m,n;
int A[4][4],A2[4][4];
char NUM[][5]={"2","4","8","16","32","64","128","256","512","1024","2048"};

void print()
{
//int m,n;

	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
		m=A[i][j];
		n=0;

		if(m!=0)
		{
		n=log10(m)/log10(2);
			/*while(m%2!=1)
			{
			m=m/2;
			n++;
			} */

		setfillstyle(1,0);
		bar(midx-196+(100*j),midy-196+(100*i),midx-104+(100*j),midy-104+(100*i));

		outtextxy(midx-150+(100*j), midy-150+(100*i),NUM[n-1]);
		}

		else
		{
		setfillstyle(1,0);
		bar(midx-196+(100*j),midy-196+(100*i),midx-104+(100*j),midy-104+(100*i));

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
int key,a,b,X[]={2,4};
  setbkcolor(YELLOW);


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

	for(i=-2;i<=2;i++)
	bar(midx+(100*i)-2,midy-202,midx+(100*i)+2,midy+202);
	for(i=-2;i<=2;i++)
	bar(midx-200,midy+(100*i)-2,midx+200,midy+(100*i)+2);

settextjustify(1,1);
settextstyle(5,0,3);
//outtextxy(midx-50, midy-50, "1024");
int tp=0,new1,new2,new3,undo,flag=1,over;
new1=random(4);
new2=random(4);
new3=random(2);

A[new1][new2]=X[new3];
C[1].B[new1][new2]=X[new3];

/*
int r=0;

A[0][0]=1024;
A[0][1]=4;
A[0][2]=4;
A[0][3]=8;
A[1][0]=16;
A[1][1]=512;
A[1][2]=1024;
A[1][3]=64;
A[2][0]=128;
A[2][1]=2;
A[2][2]=4;  */

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
	new1=random(2);
	new2=random(a);

	A[INSERT[new2].I][INSERT[new2].J]=X[new1];
	/*m=A[I[newr]][J[newc]];
	n=0;
	n=log10(m)/log10(2);
			/*
			while(m%2!=0)
			{
			m=m/2;
			n++;
			}*/

	/*outtextxy(midx-150+(100*I[newr]), midy-150+(100*J[newc]),NUM[n-1]);
	*/
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


	while (bioskey(1) == 0);
	key = bioskey(0);

		if(key==19200)                   //left arrow.
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

		else if(key==19712)
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

		else if(key==18432)
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

		else if(key==20480)
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

		else if(key==5749||key==5717)
		{
		flag=0;
		for(i=0;i<4;i++)
		{
			for(j=0;j<4;j++)
			A[i][j]=C[0].B[i][j];
		}
		}

		else
		exit(0);

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
		/*gotoxy(0,0);
		bar(0,0,midx-202,midy);
		for(i=0;i<4;i++)
			{  	for(j=0;j<4;j++)
				cout<<A[i][j]<<" ";
			cout<<"\n";
			}
		*/



		print();


	}


cleardevice();
cout<<"GAME OVER!!!";
getch();
closegraph();
}