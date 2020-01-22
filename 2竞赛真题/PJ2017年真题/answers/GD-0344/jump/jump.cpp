#include<iostream>
#include<cstdio>
#include<fstream>
#include<cmath>
#include<algorithm>
	using namespace std;
	long long F[500005];
	int N=0,D=0,K=0,x[500005],s[500005];
long long dfs(int S,int E,int X)
{ 
	if(F[X]!=0) return F[X];
	for(int i=X+1;i<=N;i++)
	{
		if(x[i]-x[X]>E) break;
		if(x[i]-x[X]>=S) F[X]=max(F[X],dfs(S,E,i)+s[i]);
	}
	return F[X];
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int ans=-1;
	scanf("%d%d%d",&N,&D,&K);
	for(int i=1;i<=N;i++) scanf("%d%d",&x[i],&s[i]);
	x[0]=0;
	for(int i=0;D+i<=x[N];i++) 
	{
		for(int j=0;j<=N;j++) F[j]=0;
		long long T=0;
		if(i<D) T=dfs(D-i,D+i,0);
		   else T=dfs(1,D+i,0);	
		if(T>=K) 
		{
			ans=i;
			break;
		}
	}
	printf("%d",ans);
	return 0;
}
