#include <fstream.h>
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

struct virtualkeyboard
{
char let[3];
int bkey[2];
}G[26];

void storekey()
{
int k=0;

G[k].bkey[0]=4209;G[k].bkey[1]=4177;strcpy(G[k].let,"Q");k++;
G[k].bkey[0]=4471;G[k].bkey[1]=4439;strcpy(G[k].let,"W");k++;
G[k].bkey[0]=4709;G[k].bkey[1]=4677;strcpy(G[k].let,"E");k++;
G[k].bkey[0]=4978;G[k].bkey[1]=4946;strcpy(G[k].let,"R");k++;
G[k].bkey[0]=5236;G[k].bkey[1]=5204;strcpy(G[k].let,"T");k++;
G[k].bkey[0]=5497;G[k].bkey[1]=5465;strcpy(G[k].let,"Y");k++;
G[k].bkey[0]=5749;G[k].bkey[1]=5717;strcpy(G[k].let,"U");k++;
G[k].bkey[0]=5993;G[k].bkey[1]=5961;strcpy(G[k].let,"I");k++;
G[k].bkey[0]=6255;G[k].bkey[1]=6223;strcpy(G[k].let,"O");k++;
G[k].bkey[0]=6512;G[k].bkey[1]=6480;strcpy(G[k].let,"P");k++;
G[k].bkey[0]=7777;G[k].bkey[1]=7745;strcpy(G[k].let,"A");k++;
G[k].bkey[0]=8051;G[k].bkey[1]=8019;strcpy(G[k].let,"S");k++;
G[k].bkey[0]=8292;G[k].bkey[1]=8260;strcpy(G[k].let,"D");k++;
G[k].bkey[0]=8550;G[k].bkey[1]=8518;strcpy(G[k].let,"F");k++;
G[k].bkey[0]=8807;G[k].bkey[1]=8775;strcpy(G[k].let,"G");k++;
G[k].bkey[0]=9064;G[k].bkey[1]=9032;strcpy(G[k].let,"H");k++;
G[k].bkey[0]=9322;G[k].bkey[1]=9290;strcpy(G[k].let,"J");k++;
G[k].bkey[0]=9579;G[k].bkey[1]=9547;strcpy(G[k].let,"K");k++;
G[k].bkey[0]=9836;G[k].bkey[1]=9804;strcpy(G[k].let,"L");k++;
G[k].bkey[0]=11386;G[k].bkey[1]=11354;strcpy(G[k].let,"Z");k++;
G[k].bkey[0]=11640;G[k].bkey[1]=11608;strcpy(G[k].let,"X");k++;
G[k].bkey[0]=11875;G[k].bkey[1]=11843;strcpy(G[k].let,"C");k++;
G[k].bkey[0]=12150;G[k].bkey[1]=12118;strcpy(G[k].let,"V");k++;
G[k].bkey[0]=12386;G[k].bkey[1]=12354;strcpy(G[k].let,"B");k++;
G[k].bkey[0]=12654;G[k].bkey[1]=12622;strcpy(G[k].let,"N");k++;
G[k].bkey[0]=12909;G[k].bkey[1]=12877;strcpy(G[k].let,"M");
}


void main()
{
//enter();
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
int midx,midy1,maxx,maxy,key,a=0,sft=0,t=0,bac[20];
char b[20],c[1];

	maxx=getmaxx();
	maxy=getmaxy();
	midx=maxx/2;
	midy1=maxy/2;

	storekey();
	setfillstyle(1,15);
       /*	bar(midx-150,midy1-10,midx+150,midy1+25);
	bar(midx-150,midy1-10,midx-140,midy1+70);
	bar(midx+150,midy1-10,midx+140,midy1+70);
	bar(midx-150,midy1+60,midx+150,midy1+70); */


	settextjustify(1,1);
	settextstyle(3,0,4);
	setcolor(9);
	//outtextxy(midx,midy1-90,"CONGRATULATIONS");

	settextstyle(3,0,7);
	outtextxy(midx,midy1-209,"HALL OF FAME");
	outtextxy(midx,midy1-210,"HALL OF FAME");
	outtextxy(midx,midy1-211,"HALL OF FAME");
	outtextxy(midx-1,midy1-210,"HALL OF FAME");
	outtextxy(midx+1,midy1-210,"HALL OF FAME");
	/*setcolor(0);
	settextstyle(2,0,7);


	for(int i=0;i<2;i++)
	outtextxy(midx-45+i,midy1+7,"Enter Your Name:");

	settextstyle(3,0,3);
	setcolor(15);
	for(i=0;i<20;i++)
	b[i]='-';

	while(a==0)
	{

		while (bioskey(1) == 0);
		key = bioskey(0);

			if(key==3592)
			{
			t--;
			setcolor(0);
			sft-=15;
				outtextxy(midx-125+sft,midy1+40,G[bac[t]].let);
			}

			else if(key==14624)
			{
			b[t]=' ';
			sft+=15;
			t++;
			}

			else if(key==7181)
			{
			for(i=0;i<t;i++)
			cout<<b[i];
			getch();
			exit(0);
			}

			for(i=0;i<26;i++)
			{
				if(key==G[i].bkey[0] || key==G[i].bkey[1])
				{
				bac[t]=i;
				b[t]=G[i].let[0];
				setcolor(15);
				outtextxy(midx-125+sft,midy1+40,G[i].let);
				sft+=15;
				t++;
				}
			}



	}         */
	getch();
	cleardevice();
	closegraph();

}