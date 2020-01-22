#include<bits/stdc++.h>
using namespace std;
long long sum=0;
int n,k,d,jl,x[500500],s[500500],now,lgl,lgr,g=-1;
void jump(int a,int w)
{
	int p=a;
	while(lgr>=x[++a]-x[p]&&lgl<=x[a]-x[p]&&a<=n)
	{
			w+=s[a];
			now=max(now,w);
			jump(a,w);
	}
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&s[i]);
		sum=max(sum,sum+s[i]);
	}
	if(sum<k)
	{
		cout<<-1;
		return 0;
	}
	else
	{
		while(now<k&&g+d<=x[n])
		{
			g++;
			now=0;
			lgl=max(0,d-g);
			lgr=d+g;
			jump(1,s[1]);
		}
		cout<<g;
		return 0;
	}	
}
