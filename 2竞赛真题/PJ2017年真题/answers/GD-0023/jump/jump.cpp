#include<cstdio>
#include<cstring>
using namespace std;
int max(int x,int y){if(x>y)return x; return y;}
int x[110],s[110];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,i,now=0,last=0,h;
	scanf("%d%d%d",&n,&d,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&s[i]);
		if(s[i]>0)
		{
			now+=s[i];
			if(h<x[i]-last)h=x[i]-last;
			last=x[i];
		}
	}
	if(now<k){printf("-1\n");return 0;}
	if(now==k){printf("%d\n",max(h-d,0));return 0;}
	return 0;
}
