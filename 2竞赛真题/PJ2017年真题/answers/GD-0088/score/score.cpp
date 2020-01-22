#include<cstdio>
#include<iostream>
using namespace std;
int a,b,c,s;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&b,&c);
	cout<<a*0.2+b*0.3+c*0.5;
	return 0;
}
