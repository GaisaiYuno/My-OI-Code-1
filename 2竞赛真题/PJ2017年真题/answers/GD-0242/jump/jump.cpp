#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,d,m,s,x,y,len;
int a[510000],b[510000];
void dfs(int k,int l)
{
	if(l>=m&&k==len){printf("%d\n",s);exit(0);}
	if(k<len)
	{
		for(int i=x;i<=y;i++)
		{
			dfs(k+i,l+b[k+i]);
		}
	}
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);scanf("%d",&b[a[i]]);
		if(b[a[i]]>0)s+=b[a[i]];
	}len=a[n];
	if(s<m){printf("-1\n");return 0;}
	s=0;
	while(1)
	{
		if(s>=d)x=1,y=s+d;
		else x=d-s,y=d+s;
		dfs(0,0);
		s++;
	}
}
