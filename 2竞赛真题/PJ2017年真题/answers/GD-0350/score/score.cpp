#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int rd()
{
	int x=1,res=0;
	char ch;
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		res=res*10;
		res+=ch-'0';
		ch=getchar();
	}
	return x*res;
}
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	a=rd();
	b=rd();
	c=rd();
	cout<<a*2/10+b*3/10+c*5/10;
	return 0;
}
