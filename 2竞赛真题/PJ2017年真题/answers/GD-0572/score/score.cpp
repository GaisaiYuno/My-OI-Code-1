#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#define fo(i,l,r) for(int i=l;i<=r;i++)
#define of(i,l,r) for(int i=l;i>=r;i--)
#define fin(x) freopen(x,"r",stdin)
#define fou(x) freopen(x,"w",stdout)
using namespace std;

inline int rd()
{
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar())if(ch=='-')f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar())x=x*10+ch-'0';
	return x*f;
}

int a,b,c;

int main()
{
	fin("score.in");fou("score.out");
	a=rd();b=rd();c=rd();
	int ans=a*2+b*3+c*5;
	ans/=10;
	printf("%d\n",ans);
}
