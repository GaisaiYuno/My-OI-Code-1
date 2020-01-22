#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,d,k,j[505],q,m[505],add,c=100000,l,x,minx;
long long maxn,ans=1;
bool a=0;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&q);
		scanf("%d",&j[q]);
		if(j[q]>0)
		maxn+=j[q];
		if(q>add)
		add=q;
		c=min(c,q-l);
		l=q;
		if(i==1)
		minx=q;
	}
	if(maxn<=k)
	printf("-1");
	else
	{
		ans=c;
		while(1)
		{
			memset(m,0,sizeof(m));
			if(ans<d)
			for(int i=d-ans+1;i<=add;i++)
			{
				x=0;
				for(int q=d-ans;q<=d+ans;q++)
				{
					if(j[i-q]!=0&&j[i]!=0)
					{
					if(i>=q+ans+1&&q==1)
					m[i]=m[i-q]+j[i];
					else
					if(i>=q+ans+1)
					m[i]=max(m[i],m[i-q]+j[i]);
					else
					m[i]=j[i];
					x=1;
					}
				}
				if(m[i]>=k)
				{
					a=1;
					break;
				}
				if(x==0)
				break;
			}
			else
			for(int i=1+d-ans;i<=add;i++)
			{
				x=0;
				for(int q=1;q<=d+ans;q++)
				{
					if(j[i-q]!=0&&j[i]!=0)
					{
					if(i>=q+ans+1&&q==1)
					m[i]=m[i-q]+j[i];
					else
					if(i>=q+ans+1&&q!=1)
					m[i]=max(m[i],m[i-q]+j[i]);
					else
					m[i]=j[i];
					x=1;
					}
				}
				if(m[i]>=k)
				{
					a=1;
					break;
				}
				if(x==0)
				break;
			}
			if(a==1)
			break;
			ans++;
		}
		printf("%lld",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
