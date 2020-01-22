/*

            -. .
       _____   ',' ,
     ,'     ,'   ', ',
   ,'     ,'      |  |
  \       \       |  |
    \ /^\   \    ,' ,'
          \   \ ,' ,'      L'Internationale,
    / ~-.___\.-'  ,'            Sera le genre humain.
  /   .______.- ~ \
/   /'          \   \
\./               \/'

Problem: Fat_Tiger 的树[SZ2018]
Source:http://acm.hdu.edu.cn/showproblem.php?pid=4219
Algorithm:树形DP 
Description:
转换思维，不直接维护直径长度，而是维护根节点到叶子节点的长度最大值为j的概率
定义dp[i][j]表示在i的子树中i到叶子节点的长度最大值为j，且直径<=s的概率
则最终答案为sigma(dp[1][i]) 0<=i<=s
合并答案时维护两个临时数组，假设当前合并到x点 
up[j]表示x到叶子节点长度<=s的概率，可直接由dp[y][j]推出
up[j+k]=dp[y][j]*1/(l+1) (j+k<=s)
求出up[j]后再将up[j]和已经求得的dp[x][j]合并，相当于把y子树合并入答案 
merge[max(j,k)]+=dp[x][k]*up[j] (k+j<=s)
然后将dp[x][j]=merge[j]
这样的时间复杂度是O((n+L)*S^2)的,会TLE1个点

首先对up和原来的dp求前缀和  
然后枚举最长距离为j, 那么最长距离来自x当前已经合并完的子树的概率为dp[x][0~j]*up[0~min(j,s-j)]
最长距离来自y的可能性是dp[x][0~min(j,s-j)]*up[0~j]
 对上面这两个部分求和即可, 当然注意枚举的j满足j*2<=s的时候重复计算了dp[i][0~j]*up[0~j]

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005 
#define maxs 2005
using namespace std;
int n,l,s;
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int head[maxn];
int sz=0;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

double dp[maxn][maxs];
double up[maxs];
double sumup[maxs],sumdp[maxs];
void dfs(int x,int fa){
	dp[x][0]=1.0;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
			for(int j=0;j<=s;j++)up[j]=sumup[j]=sumdp[j]=0;
			for(int j=0;j<=l;j++){
				for(int k=0;j+k<=s;k++){
					up[j+k]+=dp[y][k]/(1.0+l);
				} 
			}
			sumup[0]=up[0];
			for(int j=1;j<=s;j++) sumup[j]=sumup[j-1]+up[j];
			sumdp[0]=dp[x][0];
			for(int j=1;j<=s;j++) sumdp[j]=sumdp[j-1]+dp[x][j];
			
			for(int j=0;j<=s;j++){
				int k=min(s-j,j);
				double tmp=dp[x][j]*up[j];
				dp[x][j]=dp[x][j]*sumup[k]+sumdp[k]*up[j];
				if(j*2<=s) dp[x][j]-=tmp;
			}

		}
	}
} 

int main(){
	int u,v;
	scanf("%d %d %d",&n,&l,&s);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	double ans=0;
	for(int i=0;i<=s;i++){
		ans+=dp[1][i];
	}
	printf("%.6f\n",ans);
}
