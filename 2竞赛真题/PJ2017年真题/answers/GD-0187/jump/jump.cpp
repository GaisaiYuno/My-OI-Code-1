#include<cstdio>
#include<iostream>
using namespace std;
int x[500001],s[500001];
int n,d,k,wz=0,book[500001];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);

	scanf("%d%d%d",&n,&d,&k);
	int count=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&s[i]);
		if(s[i]>0)count+=s[i];
		book[x[i]]=1;
	}
	int i,j,f,ans=0;
	for(i=1;i<=x[n];i++)
	{
		if(i%d==0&&book[i]==1)ans+=i;
	}
	if(ans>=k)
	{
		printf("0");
		return 0;
	}
	ans=0;
	bool fa=false,d=false;
	for(i=1;;i++)
	{
		for(j=d-i;j<=d+i;j++)
		{
			for(f=1;f<=n;f++)
			{
				if(wz+j==x[f]){
				ans+=s[f];wz+=j;
				}
				if(ans>=k)
				{
					fa=true;
					break;
				}
			}
			if(fa)
			{
				d=true;
				break;
			}
		}
		if(d)break;
	}
	if(count<k){
		printf("-1");
		return 0;
	}
	printf("%d",ans);
	return 0;
}
