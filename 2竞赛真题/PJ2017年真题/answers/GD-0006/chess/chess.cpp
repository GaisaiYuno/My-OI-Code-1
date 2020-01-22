#include<iostream>
#include<cstdio>
using namespace std;
int ans=0,m,n,x,y,c,chess[105][105],pd;
void dg(int i,int j)
{
	if (i==m&&j==m) return ;
	if (chess[i][j]==chess[i][j+1]) {j++;pd=1;if (i==m&&j==m) return;}
	  else if (chess[i][j]==chess[i+1][j]) {i++;pd=1;if (i==m&&j==m) return;}
	else if (chess[i+1][j]!=0) {i++;ans++;pd=1;if (i==m&&j==m) return;}
	  else if (chess[i][j+1]!=0) {j++;ans++;pd=1;if (i==m&&j==m) return;}
	else if (chess[i][j+1]==0&&chess[i+1][j]==0&&chess[i+1][j+1]!=0) {chess[i][j+1]=chess[i][j];j++;ans+=2;pd=1;if (i==m&&j==m) return;}
	  else if (chess[i][j+1]==0&&chess[i+1][j]==0&&chess[i+1][j+1]==0) {pd=0;return;}
	dg(i,j);
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for (int i=1;i<=n;i++)
	{
		cin>>x>>y>>c;
		if (c==1) chess[x][y]=c;
		else if (c==0) chess[x][y]=2;
	}
    dg(1,1);
	if (pd==0) cout<<-1;
	else cout<<ans;
	return 0;
}
