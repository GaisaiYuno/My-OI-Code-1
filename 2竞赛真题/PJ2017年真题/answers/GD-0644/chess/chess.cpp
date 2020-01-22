#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
short board[101][101]={0};
int mmin=1000000;int m;
void go(short x,short y,int cost);
void go(short x,short y,int cost)
{
	if ((x==m)&&(y==m)) 
	{
	   if (cost < mmin) 
	      {
	      mmin=cost;
		  }
    return;
	}
	if ((board[x][y]<0)&&(board[x][y+1]=0)&&(board[x+1][y]=0)) return;
	if ((board[x][y+1]>0)&&(y<m))
	{
		if (board[x][y]==board[x][y+1]) go(x,y+1,cost);
		else 
		if ((board[x][y]*-1)==board[x][y+1])
             {
             	board[x][y]=0;
             	go(x,y+1,cost);
             }
		else go(x,y+1,cost+1);
	}
	else if ((y<m)&&(board[x][y]>0)) 
	{
		board[x][y+1]=board[x][y]*-1;
		go(x,y+1,cost+2);
    };
    
	if ((board[x+1][y]>0)&&(x<m))
	{
		if (board[x][y]==board[x+1][y]) go(x+1,y,cost);
		else if ((board[x][y]*-1)==board[x+1][y])
             {
             	board[x][y]=0;
             	go(x+1,y,cost);
             }
		else go (x+1,y,cost+1);
	}
	else if ((x<m)&&(board[x][y]>0)) 
	{
		board[x+1][y]=board[x][y]*-1;
		go(x+1,y,cost+2);
    }
    return;
}
int main() {
	ifstream infile;
	infile.open("chess.in");
	ofstream outfile;
	outfile.open("chess.out");
    int n;
    infile >> m >> n;
	for (int i=1;i<=n;++i)
	{
		int x,y;short color;
		infile >> x >> y >> color;
		if (color==1) board[x][y]=2;
		else board[x][y]=1;
	}
	go(1,1,0);
	if (mmin==1000000) outfile << -1;
	else outfile << mmin;
	infile.close();
	outfile.close();
	return 0;
}

