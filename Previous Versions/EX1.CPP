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

class score_card
{
	char name[20];
	int score_save;

	public:
	void add();
	void display();
} obj;

int score,i,j,flag2,HOF[20];
char HOF_Name[20][20];

void enter()
{
clrscr();
cout<<"Enter Score: ";
cin>>score;
obj.add();
obj.display();
}

void couldnt()
{
clrscr();
cout<<"You CO:";
getch();
}

void score_card:: display()
{
	int k;
	clrscr();

	fstream fio;
	fio.open("scores123.txt",ios::in);//open file in input mode
	fio.seekg(0);//set file pointer to first object

	fio.read((char*)&obj,sizeof(obj));

	i=0;

	while(!fio.eof())
	{
		cout<<i+1<<". ";
		cout<<obj.name<<" ";
		cout<<obj.score_save<<"\n";
		i++;
		fio.read((char*)&obj,sizeof(obj));
	}

	fio.close();
	getch();

	cout<<"again?";
	cin>>k;
	if(k==1)
	enter();
	else
	exit(0);

}

void score_card:: add()
{

clrscr();
	fstream fin,fout;
	fin.open("scores123.txt",ios::app);//open file in input mode
	fin.seekg(0);//set file pointer to first object

	i=0, flag2=0;


	/*for(i=0;i<9;i++)
		HOF[i]=0;  */

	fin.read((char*)&obj,sizeof(obj));

	while(!fin.eof())
	{
		HOF[i]=obj.score_save;
		strcpy(HOF_Name[i],obj.name);
		i++;
		fin.read((char*)&obj,sizeof(obj));
	}

	for(i=9; i>=0; i--)
	{
		if(score<=HOF[i])
			break;

	}

	if(i==9)
		couldnt();

	else
	{
		/*
		if(i==-1)
		flag2=i+1;

		else
		flag2=i;
		*/

		for(j=9; j>i; j--)
		{
			HOF[j]=HOF[j-1];
			strcpy(HOF_Name[j],HOF_Name[j-1]);
		}

		HOF[i+1]=score;
		cout<<"Enter your name:";
		gets(HOF_Name[i+1]);

		fout.open("temp.txt",ios::app);//open temporary file

		for(i=0; i<10; i++)
		{
			strcpy(name,HOF_Name[i]);
			score_save=HOF[i];

			fout.write((char*)&obj,sizeof(obj));
		}

		fin.close();
		fout.close();
		remove("scores123.txt");//delete old file
		rename("temp.txt","scores123.txt");//rename temporary file as master file
	}
}



void main()
{
enter();
}