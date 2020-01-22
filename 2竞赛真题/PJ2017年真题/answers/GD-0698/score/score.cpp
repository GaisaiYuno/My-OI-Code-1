#include<iostream>
#include<cstdio>
using namespace std;
int a,s,d;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d%d%d",&a,&s,&d);
	cout<<a*0.2+s*0.3+d*0.5;
	return 0;
}
