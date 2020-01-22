#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,x,y,t;
int map[109][109],map2[109][109],p[109][109],c[109][109];
int a[4]={1,0,-1,0};
int b[4]={0,1,0,-1};
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>t;
		if(t==1) map[x][y]=1;else map[x][y]=2;
	}
	map2[1][1]=1;
	for(int i=1;i<=m;i++)
	 for(int j=1;j<=m;j++)
	 {
	 	if((i!=m||j!=m)&&map2[i][j]==1)
	 	{
	 		for(int k=0;k<=3;k++)
	 		{
	 			int s=-1;
	 			x=i+a[k];y=j+b[k];
	 			
	 			if(map[x][y]==map[i][j]&&map[x][y]!=0) s=0;
	 			 else if(map[x][y]!=0) s=1;
	 			  else if(map[i][j]!=0) s=2;
	 			if(map[i][j]==0&&c[i][j]==map[x][y]) s=0;
	 			if(s==0) 
				  {
				  	if(map2[x][y]==0) p[x][y]=p[i][j];
					  else if(p[i][j]<=p[x][y]) {p[x][y]=p[i][j];c[x][y]=0;}
				  }
	 			 else if(s==1) 
				  {
				  	if(map2[x][y]==0) p[x][y]=p[i][j]+1;
					  else if(p[i][j]+1<=p[x][y]) {p[x][y]=p[i][j]+1;c[x][y]=0;}
				  }
	 			  else if(s==2) 
				  {
				  	if(map2[x][y]==0) {p[x][y]=p[i][j]+2;c[x][y]=map[i][j];}
					  else if(p[i][j]+2<p[x][y]) {p[x][y]=p[i][j]+2;c[x][y]=map[i][j];}
				  }
				if(s!=-1) map2[x][y]=1;
	 		}
	 	}
	 }
	 if(map2[m][m]==1) cout<<p[m][m];else cout<<-1;	 
	 return 0;
}

