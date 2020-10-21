#include<iostream>
#include<math.h>
#include<time.h>
#include<stdlib.h>
#include<cstdlib>
using namespace std;

char M[24][24];
bool GameOver;
int x,y,h,w,Fx,Fy,score,k;
int Tx[100],Ty[100];

char getch()
{
	char c; // This function should return the keystroke
	system("stty raw");    // Raw input - wait for only a single keystroke
	system("stty -echo");  // Echo off
	c = getchar();
	system("stty cooked"); // Cooked input - reset
	system("stty echo");   // Echo on - Reset
	return c;
}

void setup()
{
	score=0;
	GameOver = false;
	w = 20;
	h = 20;
	system("clear");
	x = w/2;
	y = h/2;
	Fx = rand() % w;
	Fy = rand() % h;
	Tx[0] = x;
	Ty[0] = y;
}

void draw()
{
	if(Fx==1)
		Fx++;
	if(Fx==w)
		Fx--;
	if(Fy==1)
		Fy++;
	if(Fy==h)
		Fy--;
	if(Fx==0)
		Fx += 3;
	if(Fy==0)
		Fy+= 3;

	system("clear");
	int i,j;
	for(i=1;i<=h;i++)
	{
		for(j=1;j<=w;j++)
		{
			if(i==1 || i==h)
				M[i][j] = '#';
			else
			{
				if(j==1 || j==w)
					M[i][j]='#';
				else
					M[i][j]=' ';
			}
			if(i==y && j==x)
			{
				M[i][j]='O';
			}
			if(i==Fy && j==Fx)
			{
				M[i][j]='*';
			}
		}
	}

	for(k=1;k<=score/10;k++)
	{
		M[Ty[k]][Tx[k]] = 'o';
	}
	for(i=1;i<=20;i++)
	{
		for(j=1;j<=20;j++)
		{
			cout<<M[i][j];
		}
		cout<<endl;
	}
	cout<<"Score : "<<score<<endl;
}

char in;

void input()
{
	in = getch();	

	Tx[0] = x;
	Ty[0] = y;

	if(in=='a')
		x--;
	if(in == 'd')
		x++;
	if(in=='w')
		y--;
	if(in=='s')
		y++;
}

void logic() 
{
	if(x==1 || x==w || y==1 || y==h)
		GameOver = true;

	if(x==Fx && y==Fy)
	{
		score += 10;
		Fx = rand() % w;
		Fy = rand() % h;
	}
	
	for(k=score/10;k>=1;k--)
	{
		Tx[k] = Tx[k-1];
		Ty[k] = Ty[k-1];
	}
	Tx[0] = x;
	Ty[0] = y;

	for(k=2;k<=score/10;k++)
		if(Tx[k]==x && Ty[k]==y)
			GameOver = true;

}

int main()
{
  	srand(time(0)); 
	setup();
	while(GameOver==false)
	{
		draw();
		input();
		logic();
	}
	return 0;
}
