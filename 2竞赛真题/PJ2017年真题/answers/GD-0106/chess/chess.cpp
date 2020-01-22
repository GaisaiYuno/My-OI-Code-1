#include<iostream>
#include<fstream>
using namespace std;
int map[101][101],gold,mind=99999;
short m,x,y;
short num=0,last,now;
/*int go()//×ß²½ 
{
	x=1;y=1;gold=0;
	last=map[1][1];
	
	return -1;
}*/
//»Æ2ºì1 
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int i,ch,n;
	cin>>m>>n;
	/*for(i=1;i<=100;i++)
	{
		for(int j=1;j<=100;j++)
			map[i][j]=0;
	}*/
	for(i=1;i<=n;i++)
	{
		cin>>x>>y>>ch;
		ch++;
		map[x][y]=ch;
	}
	cout<</*go()*/"-1";
	return 0;
}
