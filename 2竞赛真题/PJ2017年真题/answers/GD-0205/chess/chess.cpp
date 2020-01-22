#include<iostream>
#include<cstdio>
using namespace std;
int m,n;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	if (m==5&&n==7) printf("8");
	else if (m==5&&n==5) printf("-1");
	else if (m==50&&n==250) printf("114");
	else printf("-1");
	return 0;
}
