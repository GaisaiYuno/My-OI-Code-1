#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;
int n,m,a[2500][2500],mi=10000000,coin=0;
int dx[5]={0,0,-1,0,1},dy[5]={0,1,0,-1,0};
bool b[2500][2500]={false},bc=true;
void chess(int x,int y)
{
	if( (x==m)&&(y==m) ) 
	{
		if(coin<mi) 
		{
			mi=coin;
			coin=0;	
		}return;
	}
	for(int i=1;i<=4;i++)
	{
		if( (x+dx[i]>0)&&(x+dx[i]<m)&&
		    (y+dy[i]>0)&&(y+dy[i]<m)&&
		    (b[x+dx[i]][y+dy[i]]==false) )
		{
			if(a[x][y]!=a[x+dx[i]][y+dy[i]])
			{
				if( (a[x+dx[i]][y+dy[i]]==-1)
				     &&(bc==true) ) 
				{	coin+=2; bc=false; a[x+dx[i]][y+dy[i]]=a[x][y];	}
				else {	coin+=1; bc=true;	}
			}
			 b[x+dx[i]][y+dy[i]]=true;
			 
			chess(x+dx[i],y+dy[i]);
			
			b[x+dx[i]][y+dy[i]]=false;
			if(bc==false) a[x+dx[i]][y+dy[i]]=-1; 
			//coin-=2;
			// else coin-=1;
		}
		
	}
}

int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int i,j,c,c0,c1;
	cin>>m>>n;
	memset(a,-1,sizeof(a));
	for(int k=1;k<=n;k++)
	{
		cin>>i>>j>>c;
		a[i][j]=c;
		if(c==0) c0++;
		else c1++;
	}
	chess(1,1); 
	if(mi==10000000) cout<<"-1";
	else cout<<mi;
	return 0;
}
