#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int N,D,K,X[500005],S[500005],L[500005],T,G1,G2,Maxs,Minm,Left,Right,Mid;
bool Tf=false;
int main()
{
	int i,j,k;
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&N,&D,&K);
	for(i=1;i<=N;i++)
		scanf("%d%d",&X[i],&S[i]);
	X[0]=S[0]=0;
	Left=0;
	Right=X[N];
	while(Left<Right)
	{
		Mid=(Left+Right)/2;
		G1=D+Mid;
		G2=D-Mid;
		memset(L,0,sizeof(L));
		T=0;
		for(j=1;j<=N;j++)
		{
			if(X[j]-X[j-1]>G1)
				break;
			else if((S[j]<0 && T+X[j]-X[j-1]<=G1) || T+X[j]-X[j-1]<G2)
			{
				L[j]=L[j-1];
				T+=X[j]-X[j-1];
			}
			else if(S[j]<0 && T+X[j]-X[j-1]>G1)
			{
				for(k=j-1;X[j]-X[k]<=G1;k--)
					if(S[k]<0)
						Maxs=k;
				for(k=j-2;X[j]-X[k]<=G1;k--)
				{
					if(S[k]>=0)
						continue;
					else if(S[Maxs]<S[k])
						Maxs=k;
				}
				L[j]=L[j+1]+S[Maxs];
				T=X[j]-X[Maxs];
			}
			else if(S[j]>=0 && T+X[j]-X[j-1]<=G1)
			{
				L[j]=L[j-1]+S[j];
				T=0;
			}
			else if(S[j]>=0 && T+X[j]-X[j-1]>G1)
			{
				for(k=j-1;X[j]-X[k]<=G1;k--)
					if(S[k]<0)
						Maxs=S[k];
				for(k=j-2;X[j]-X[k]<=G1;k--)
				{
					if(S[k]>=0)
						continue;
					else
						Maxs=max(Maxs,S[k]);
				}
				L[j]=L[j-1]+Maxs+S[j];
				T=0;
			}
			if(L[j]>=K)
			{
				Right=Mid;
				if(!Tf)
				{
					Minm=Mid;
					Tf=true;
				}
				else
					Minm=min(Minm,Mid);
				break;
			}
		}
		if(j>N || X[j]-X[j-1]>G1)
			Left=Mid+1;
	}
	if(Tf)
		printf("%d",Minm);
	else
		printf("-1");
	fclose(stdin);
	fclose(stdout);
	return 0;
}
