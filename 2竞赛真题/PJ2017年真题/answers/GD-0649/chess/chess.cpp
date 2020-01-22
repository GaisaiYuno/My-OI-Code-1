#include<cstdio>
#include<iostream>
using namespace std;
struct chess{
	long long c,r;
	bool b;
}a[1111][1111],t1,t2;
long long m,n,i,j,x,y;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	for (i=0; i<1111; i++) for (j=0; j<1111; j++){a[i][j].c=3;a[i][j].r=0;a[i][j].b=false;}
	cin>>m>>n;
	for (i=0; i<n; i++) 
	{
		cin>>x>>y;
		cin>>a[x][y].c;
	}
	for (i=2; i<=m; i++)
	{
		if (a[1][i-1].b&&a[1][i].c==3){
			for (j=i; j<=m; j++) {
				a[1][j].b=true;
				a[1][j].r=-1;
			}
			break;
		}
		if (a[1][i-1].c==a[1][i].c) {
			a[1][i].r=a[1][i-1].r;
			continue;
		}
		if (a[1][i-1].c+a[1][i].c==1) {
			a[1][i].r=a[1][i-1].r+1;
			continue;
		}
		a[1][i].b=true;
		a[1][i].r=a[1][i-1].r+2;
		a[1][i].c=a[1][i-1].c;
	}
	for (i=2; i<=m; i++)
	{
		if (a[i-1][1].b&&a[i][1].c==3){
			for (j=i; j<=m; j++) {
			a[j][1].b=true;
			a[j][1].r=-1;
			}
			break;
		}
		if (a[i-1][1].c==a[i][1].c) {
			a[i][1].r=a[i-1][1].r;
			continue;
		}
		if (a[i-1][1].c+a[i][1].c==1) {
			a[i][1].r=a[i-1][1].r+1;
			continue;
		}
		a[i][1].b=true;
		a[i][1].r=a[i-1][1].r+2;
		a[i][1].c=a[i-1][1].c;
	}
	for (i=2; i<=m; i++)
	for (j=2; j<=m; j++)
	{
		if (a[i-1][j].b&&a[i][j].c==3||a[i-1][j].r==-1) {t1.r=-1;t1.b=true;t1.c=3;}
		else if (a[i-1][j].c==a[i][j].c) t1=a[i-1][j];
		else if (a[i-1][j].c+a[i][j].c==1) {t1=a[i-1][j]; t1.r++;}
		else {
			t1.b=true;
			t1.r=a[i-1][j].r+2;
			t1.c=a[i-1][j].c;
		}
		if (a[i][j-1].b&&a[i][j].c==3||a[i][j-1].r==-1) {t2.r=-1;t2.b=true;t2.c=3;}
		else if (a[i][j-1].c==a[i][j].c) t2=a[i-1][j];
		else if (a[i][j-1].c+a[i][j].c==1) {t2=a[i-1][j]; t2.r++;}
		else {
			t2.b=true;
			t2.r=a[i][j-1].r+2;
			t2.c=a[i][j-1].c;
		}
		if (t1.r<=t2.r&&t1.r!=-1) {if (a[i][j].c==3) a[i][j]=t1; else a[i][j].r=t1.r;}
		else {if (a[i][j].c==3) a[i][j]=t2; else a[i][j].r=t2.r;}
	}
	cout<<a[m][m].r;
	return 0;
}
