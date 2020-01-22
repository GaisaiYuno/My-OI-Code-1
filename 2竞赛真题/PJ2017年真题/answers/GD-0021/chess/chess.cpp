#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,x,y,c,ans;
int a[110][110],p,q;
long long f[110][110];
const long long oo=10000000;
//1ÊÇ»Æ£¬2ÊÇºì 
int main()
{
	
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c+1;
	}
	for(int i=0;i<=m;i++){
		f[i][0]=-1;a[i][0]=97;
		f[0][i]=-1;a[0][i]=97;
	}
	f[1][1]=0;
	
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(i==1&&j==1)  {f[i][j]=0;continue;}
			if(f[i-1][j]==-1&&f[i][j-1]==-1) {f[i][j]=-1;continue;}
			
			if(a[i-1][j]==a[i][j]) p=f[i-1][j];
			if(a[i-1][j]!=a[i][j]) p=1+f[i-1][j];
			if(a[i][j]==0) p=2+f[i-1][j];
			if(a[i-1][j]==0&&a[i][j]==a[i-1][j-1]) p--;
			
			
			if(f[i-1][j]==-1) p=oo;
			if(a[i][j]==0&&a[i-1][j]==0)p=oo;
			
			if(a[i][j-1]==a[i][j]) q=f[i][j-1];
			if(a[i][j-1]!=a[i][j]) q=1+f[i][j-1];
			if(a[i][j]==0) q=2+f[i][j-1];
			if(a[i][j-1]==0&&a[i][j]==a[i-1][j-1]) q--;
			if(f[i][j-1]==-1) q=oo;
			if(a[i][j]==0&&a[i][j-1]==0)q=oo;
			
			f[i][j]=min(p,q);
			
			if(p==oo&&q==oo) f[i][j]=-1; 
		}
	}
	
	cout<<f[m][m]<<endl;
	return 0;
}
