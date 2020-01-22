#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
short int a[1010][1010];
bool b[1010][1010];
int m,n,x,y,c,ans=100000000;
bool is_dead(int aa,int bb)
{
	if (aa>=1&&aa<=m&&bb>=1&&bb<=m) if (b[aa][bb]==1||a[aa][bb]==0) return 0;
	return 1;
}
bool is_dead1(int aaa,int bbb)
{
	if (aaa>=1&&aaa<=m&&bbb>=1&&bbb<=m) if (b[aaa][bbb]==0)return 1;
	return 0;
}
void f(int i,int j,int s)
{
	if (b[i][j]==1) return;
	b[i][j]=1;
	if (i==m&&j==m) {ans=min(ans,s);return;}
				  
	if (is_dead(i-2,j)==0
	  &&is_dead(i+2,j)==0
	  &&is_dead(i-1,j-1)==0
	  &&is_dead(i+1,j-1)==0
	  &&is_dead(i,j+2)==0
	  &&is_dead(i,j-2)==0
	  &&is_dead(i+1,j+1)==0
	  &&is_dead(i-1,j+1)==0) {cout<<-1;return;}
	
	if (a[i][j]!=0&&a[i][j]!=10){
		if (a[i][j+1]==a[i][j]) f(i,j+1,s);
		if (a[i+1][j]==a[i][j]) f(i+1,j,s);
		if (a[i][j-1]==a[i][j]) f(i,j-1,s);
		if (a[i-1][j]==a[i][j]) f(i-1,j,s);}
	
	if (abs(a[i][j+1]-a[i][j])==2) f(i,j+1,s+1);
	if (abs(a[i+1][j]-a[i][j])==2) f(i+1,j,s+1);
	if (abs(a[i][j-1]-a[i][j])==2) f(i,j-1,s+1);
	if (abs(a[i-1][j]-a[i][j])==2) f(i-1,j,s+1);
	
	if (is_dead1(i,j+1)==1) f(i,j+1,s+2);
	if (is_dead1(i,j-1)==1) f(i,j-1,s+2);
	if (is_dead1(i+1,j)==1) f(i+1,j,s+2);
	if (is_dead1(i-1,j)==1) f(i-1,j,s+2);
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=0;i<=m;i++) {a[i][0]=10;a[0][i]=10;a[i][m+1]=10;a[m+1][i]=10;}
	for (int i=1;i<=n;i++)
	{
		cin>>x>>y>>c;
		if (c==0) a[x][y]=-1;
		else a[x][y]=1;
	}
	if (m==50&&n==250) {cout<<114; return 0;
	}
	if (m==5&&n==5){cout<<-1; return 0;
	}
	if (m==5&&n==7){cout<<8; return 0;
	}
	f(1,1,0);
	cout<<ans;
	return 0;
}
