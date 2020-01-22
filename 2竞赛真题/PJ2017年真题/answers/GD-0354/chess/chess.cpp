#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int m,n,b[105][105],a[105][105],z1,z2,c,mans=2147483647,t;
void f(int x,int y,int ans)
{
	if (t>=9900000) return;
	t++;
	if (x==m&&y==m) {
		mans=min(mans,ans);
	}
	if (x<1||x>m||y<1||y>m) return;
	
	if (b[x][y+1]==0){
		if (a[x][y+1]==a[x][y]%10)
			{b[x][y+1]=1;f(x,y+1,ans);b[x][y+1]=0;} 
		if (a[x][y+1]==1&&a[x][y]%10==0||a[x][y+1]==0&&a[x][y]%10==1)
			{b[x][y+1]=1;f(x,y+1,ans+1);b[x][y+1]=0;} 
		if (a[x][y+1]==3&&a[x][y]==0)
			{b[x][y+1]=1;a[x][y+1]=10;f(x,y+1,ans+2);a[x][y+1]=3;b[x][y+1]=0;}
		if (a[x][y+1]==3&&a[x][y]==1)
			{b[x][y+1]=1;a[x][y+1]=11;f(x,y+1,ans+2);a[x][y+1]=3;b[x][y+1]=0;}
	}
	
	if (b[x+1][y]==0){
		if (a[x+1][y]==a[x][y]%10)
			{b[x+1][y]=1;f(x+1,y,ans);b[x+1][y]=0;} 
		if (a[x+1][y]==1&&a[x][y]%10==0||a[x+1][y]==0&&a[x][y]%10==1)
			{b[x+1][y]=1;f(x+1,y,ans+1);b[x+1][y]=0;} 
		if (a[x+1][y]==3&&a[x][y]==0)
			{b[x+1][y]=1;a[x+1][y]=10;f(x+1,y,ans+2);a[x+1][y]=3;b[x+1][y]=0;}
		if (a[x][y+1]==3&&a[x][y]==1)
			{b[x+1][y]=1;a[x+1][y]=11;f(x+1,y,ans+2);a[x+1][y]=3;b[x+1][y]=0;}
	}
	
	if (b[x-1][y]==0){
		if (a[x-1][y]==a[x][y]%10)
			{b[x-1][y]=1;f(x-1,y,ans);b[x-1][y]=0;} 
		if (a[x-1][y]==1&&a[x][y]%10==0||a[x-1][y]==0&&a[x][y]%10==1)
			{b[x-1][y]=1;f(x-1,y,ans+1);b[x-1][y]=0;} 
		if (a[x-1][y]==3&&a[x][y]==0)
			{b[x-1][y]=1;a[x-1][y]=10;f(x-1,y,ans+2);a[x-1][y]=3;b[x-1][y]=0;}
		if (a[x][y+1]==3&&a[x][y]==1)
			{b[x-1][y]=1;a[x-1][y]=11;f(x-1,y,ans+2);a[x-1][y]=3;b[x-1][y]=0;}
	}
	
	if (b[x][y-1]==0){
		if (a[x][y-1]%10==a[x][y]%10)
			{b[x][y-1]=1;f(x,y-1,ans);b[x][y-1]=0;} 
		if (a[x][y-1]==1&&a[x][y]%10==0||a[x][y-1]==0&&a[x][y]%10==1)
			{b[x][y-1]=1;f(x,y-1,ans+1);b[x][y-1]=0;} 
		if (a[x][y-1]==3&&a[x][y]==0)
			{b[x][y-1]=1;a[x][y-1]=10;f(x,y-1,ans+2);a[x][y-1]=3;b[x][y-1]=0;}
		if (a[x][y+1]==3&&a[x][y]==1)
			{b[x][y-1]=1;a[x][y-1]=11;f(x,y-1,ans+2);a[x][y-1]=3;b[x][y-1]=0;}
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=0;i<105;i++)
		for (int j=0;j<105;j++)
			a[i][j]=3,b[i][j]=0;
	for (int i=1;i<=n;i++){
		cin>>z1>>z2>>c;
		a[z1][z2]=c;
	}
	if (a[1][1]==3){
		b[1][1]=1;
		a[1][1]=10;
		f(1,1,2);
		a[1][1]=11;
		f(1,1,2);
	}
	else{
		b[1][1]=1;f(1,1,0);
	}
	
	if (mans==2147483647) mans=-1;
	cout<<mans;
	return 0;
}
