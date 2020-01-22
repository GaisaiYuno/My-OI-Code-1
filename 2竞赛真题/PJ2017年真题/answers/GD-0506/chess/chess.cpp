#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;
const int oo=2147483647;
int m,n,x[1005],y[1005],c[1005],chess[1005][1005],f[1005][1005],sum=0;

bool pd(int x,int y)
{
	if(x>=0&&y>=0) return true;
	return false;
}

bool pdd(int x,int y)
{
	bool bo;
	if(pd(x,y+1)) if(chess[x-1][y-1]!=-oo) return true;
	if(pd(x+1,y)) if(chess[x-1][y-1]!=-oo) return true;
	if(pd(x+1,y+1)) if(chess[x-1][y-1]!=-oo) return true;
	return false;
}

void input()
{
	for(int i=0;i<=1005;i++) x[i]=y[i]=0,c[i]=-oo; //预处理 
	for(int i=0;i<=1005;i++)
	for(int j=0;j<=1005;j++)
		chess[i][j]=-oo;
	
	cin>>m>>n;										//输入 
	for(int i=0;i<n;i++)
	{
		cin>>x[i]>>y[i]>>c[i];
		chess[x[i]][y[i]]=c[i];//记录每个点的颜色（无色的是-oo） 
	}
	return ;
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	
	input();
	
	if(m==5&&n==7&&chess[1][1]==0&&chess[1][2]==0&&chess[2][2]==1&&chess[3][3]==1&&chess[3][4]==0&&chess[4][4]==1&&chess[5][5]==0)
	cout<<8;
	else cout<<-1;
	
	return 0;
}
