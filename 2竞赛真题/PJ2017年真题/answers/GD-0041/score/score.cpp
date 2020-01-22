#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int read()
{
	int x=0,f=1; char c=getchar();
	while (c>'9'||c<'0') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
	return x*f;
}
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a=read(),b=read(),c=read();
	cout<<a*0.2+b*0.3+c*0.5;
	fclose(stdin); fclose(stdout);
	return 0;
}
