#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
inline void read(int &x)
{
	x=0;int f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	x*=f;
}
int N,K;
int nex[maxn<<1],to[maxn<<1];
int head[maxn],tot;
int val[maxn];
inline void insert(int from,int tos)
{
	nex[++tot]=head[from];
	head[from]=tot;
	to[tot]=tos;
}
/*void dfs(int u,int x,int from,int t)
{
	ans[u]+=val[x];
	if(t==K)
		return ;
	for(int i=head[x];i;i=nex[i])
		if(to[i]^from)
			dfs(u,to[i],x,t+1);
}*/
int dp[25][maxn];
int main()
{
	freopen("nearcows.in","r",stdin);
	freopen("nearcows.out","w",stdout);
	read(N);read(K);
	int u,v;
	for(register int i=1;i<N;i++)
	{
		read(u);read(v);
		insert(u,v);
		insert(v,u);
	}
	for(register int i=1;i<=N;i++)
		read(dp[0][i]);
	 for(int i=1;i<=K;i++)
		 for(int j=1;j<=N;j++)
		 {
	        if(i==1)
				dp[i][j]=dp[i-1][j];
	        else 
	       		dp[i][j]=dp[i-2][j];
	        for(int p=head[j];p;p=nex[p]){
	            int y=to[p];
	            	dp[i][j]+=dp[i-1][y];
	            if(i!=1)
	            	dp[i][j]-=dp[i-2][j];
	        }
	    }
    for(int i=1;i<=N;i++)
		printf("%d\n",dp[K][i]);
}
