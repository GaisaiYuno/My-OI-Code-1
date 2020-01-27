#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 65

struct ff{int to,nxt;}e[N<<1];
int i,j,u,y,n,cnt;
int head[N],sz[N],maxl[N];
double ans,dp[N][N<<1][N<<1],tmp[2][N<<1][N<<1][N<<1];

int fast(){
	int res=0;
	char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48&&c<=57)res=res*10+c-48,c=getchar();
	return res;
}

void add(int u,int y){
	e[++cnt]=(ff){y,head[u]};
	head[u]=cnt;
}

void dfs(int x,int fa){
	sz[x]=1;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y!=fa)dfs(y,x),sz[x]+=sz[y];
	}int maxd=sz[x]<<1;
	maxd-=2;
	for(int i=0;i<=maxd;i++)tmp[0][0][0][i]=1.0;
	
	int p=0;
	for(int i=head[x];i;i=e[i].nxt){
		int y=e[i].to;
		if(y!=fa){p^=1;
			for(int j=0;j<=maxl[y];j++)
				for(int k=1;k<=maxd;k++)dp[y][j][k]+=dp[y][j][k-1];

			for(int j=0;j<=maxl[x];j++)
			for(int k=0;k<=j;k++)
			for(int h=0;h<=maxd;h++){
				double val2=tmp[p^1][j][k][h];
				for(int l=0;l<=maxl[y];l++){
					double val1=dp[y][l][h];
				//	printf("%d %d %d %d %d\n",p,j,k,h,l);
					for(int delta=1;delta<=2;delta++){
						if(l+delta>j)tmp[p][l+delta][j][h]+=val1*val2*0.5;
						else if(l+delta>k)tmp[p][j][l+delta][h]+=val1*val2*0.5;
							else tmp[p][j][k][h]+=val1*val2*0.5;
					}
//					if(l+1>j)tmp[p][l+1][j][h]+=val1*val2;
//						else if(l+1>k)tmp[p][j][l+1][h]+=val1*val2;
//							else tmp[p][j][k][h]+=val1*val2;
//
//					if(l+2>j)tmp[p][l+2][j][h]+=val1*val2;
//						else if(l+2>k)tmp[p][j][l+2][h]+=val1*val2;
//							else tmp[p][j][k][h]+=val1*val2;
				}
				tmp[p^1][j][k][h]=0;
			}
			maxl[x]=max(maxl[x],maxl[y]+2);
		}
	}
	
	for(int i=0;i<=maxl[x];i++)
	for(int j=0;j<=i;j++){
		for(int k=0;k<=maxd;k++){
			double val=tmp[p][i][j][k];
			if(k!=0) val-=tmp[p][i][j][k-1];
			dp[x][i][max(i+j,k)]+=val;
			
		}
		for(int k=0;k<=maxd;k++) tmp[p][i][j][k]=0;
	} 
	
}

int main()
{
	n=fast();
	for(i=1;i<n;i++){
		u=fast(),y=fast();
		add(u,y),add(y,u);
	}dfs(1,0);
	//printf("%lf %lf %lf %lf\n",dp[1][4][4],dp[1][6][6],dp[1][7][7],dp[1][8][8]);
	for(i=0;i<=maxl[1];i++)
	for(j=1;j<=n*2-2;j++)
		ans+=dp[1][i][j]*j;
	printf("%.12lf\n",ans);
	return 0;
}
