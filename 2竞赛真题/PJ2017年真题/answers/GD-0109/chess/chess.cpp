#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;
int a[300][300],m,n,x,y,c,fxl=1,fxy=1,s,t;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for (int i=1;i<=200;i++)
	{
		for (int j=1;j<=200;j++)
		{
			a[i][j]=-1;
		}
	}
	for (int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&x,&y,&c);
		a[x][y]=c;
	}
	bool r=false;
	while(fxl!=m||fxy!=m)
	{
		if((a[fxl][fxy]==a[fxl+1][fxy]&&a[fxl+1][fxy]!=-1)||(t==a[fxl+1][fxy]&&r)) {fxl++;}
		else if((a[fxl][fxy]==a[fxl][fxy+1]&&a[fxl][fxy+1]!=-1)||(t==a[fxl][fxy+1]&&r)){fxy++;}
		else if(a[fxl+1][fxy]!=-1){fxl++;s++;}
		else if(a[fxl][fxy+1]!=-1){fxy++;s++;}
		else
		{
			if(a[fxl+1][fxy+1]!=-1||a[fxl+2][fxy]!=-1) {t=a[fxl][fxy];fxl++;s+=2;}
			else if(a[fxl+1][fxy+1]!=-1||a[fxl][fxy+2]!=-1) {t=a[fxl][fxy];fxy++;s+=2;}
			else {cout<<-1;return 0;}
			r=true;
			continue;
		}
		r=false;
	}
	cout<<s;
	return 0;
}
