#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cmath>
#include<map>
#include<queue>
using namespace std;
int m,x,y,c,n,a[1005][1005];
long long  find(int i,int j,int i1,int k1,int e,int i2,int j2)
{
	int u1=i2,u2=j2;
	int q=e;
    
    
	if (a[i][j]==0) 
	{
		if (a[i1][k1]==0) return 9999999999999;
		q+=2;
	} 
	else
	if (a[i][j]!=a[i1][k1]&&a[i1][k1]!=0) q++; 
	if (i==n&&j==n)return q;
	if (i-i1==1)return min(min(find(i+1,j,i,j,q,u1,u2),find(i,j+1,i,j,q,u1,u2)),find(i,j-1,i,j,q,u1,u2));
	if (i-i1==-1)return min(min(find(i-1,j,i,j,q,u1,u2),find(i,j+1,i,j,q,u1,u2)),find(i,j-1,i,j,q,u1,u2));
	if (j-k1==1)return min(min(find(i+1,j,i,j,q,u1,u2),find(i,j+1,i,j,q,u1,u2)),find(i-1,j,i,j,q,u1,u2));
	if (j-k1==-1)return min(min(find(i+1,j,i,j,q,u1,u2),find(i-1,j,i,j,q,u1,u2)),find(i,j-1,i,j,q,u1,u2));
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>m;
	if (n==1)
	{
		cout<<0;
		return 0;
	}
	for(int k=1;k<=m;k++)
	{
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c+1;
	}
	if (find(1,1,1,1,0,0,0)==9999999999999) cout<<-1;else cout<<find(1,1,1,1,0,0,0);
	return 0;
} 
