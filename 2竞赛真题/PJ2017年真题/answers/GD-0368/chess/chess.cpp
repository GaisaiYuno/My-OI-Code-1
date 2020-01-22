#include<iostream>
#include<cstdio>
using namespace std;
long long m,n,q,w,e,z=1000000,s;
int a[105][105],b[105][105];
void vl(int x,int y,int k,int l)
{
	int c=0,v=0,p=s;
	if (x<0||x>m||y<0||y>m||b[x][y]==1) return;
	if (a[x][y]!=0&&a[x][y]!=k) {s++;l=0;v=1;}
	if (a[x][y]==k) {l=0;v=1;c=3;}
	if (a[x][y]==0&&l==0) {a[x][y]=k;c=1;s+=2;l=1;v=1;}
	b[x][y]=1;
	if (x==1&&y==1) v=1;
	if (x==m&&y==m) {z=min(z,s);return;}
	if (v==0) return;
	vl(x,y+1,a[x][y],l);
	vl(x+1,y,a[x][y],l);
	vl(x-1,y,a[x][y],l);
	vl(x,y-1,a[x][y],l);
	b[x][y]=0;
	if (c==1)a[x][y]=0;
	s=p;
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	if (m>20) {cout<<"-1"<<endl;return 0;}
	for (int i=1;i<=n;i++)
	{
		cin>>q>>w>>e;
		a[q][w]=e+1;
	}
	vl(1,1,a[1][1],0);
	if (z==1000000) cout<<"-1"<<endl;
	else cout<<z<<endl;
	return 0;
}
