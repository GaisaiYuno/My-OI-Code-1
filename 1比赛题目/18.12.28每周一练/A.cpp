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

Problem: Fat_Tiger ����[SZ2018]
Source:http://acm.hdu.edu.cn/showproblem.php?pid=4219
Algorithm:����DP 
Description:
ת��˼ά����ֱ��ά��ֱ�����ȣ�����ά�����ڵ㵽Ҷ�ӽڵ�ĳ������ֵΪj�ĸ���
����dp[i][j]��ʾ��i��������i��Ҷ�ӽڵ�ĳ������ֵΪj����ֱ��<=s�ĸ���
�����մ�Ϊsigma(dp[1][i]) 0<=i<=s
�ϲ���ʱά��������ʱ���飬���赱ǰ�ϲ���x�� 
up[j]��ʾx��Ҷ�ӽڵ㳤��<=s�ĸ��ʣ���ֱ����dp[y][j]�Ƴ�
up[j+k]=dp[y][j]*1/(l+1) (j+k<=s)
���up[j]���ٽ�up[j]���Ѿ���õ�dp[x][j]�ϲ����൱�ڰ�y�����ϲ���� 
merge[max(j,k)]+=dp[x][k]*up[j] (k+j<=s)
Ȼ��dp[x][j]=merge[j]
������ʱ�临�Ӷ���O((n+L)*S^2)��,��TLE1����

���ȶ�up��ԭ����dp��ǰ׺��  
Ȼ��ö�������Ϊj, ��ô���������x��ǰ�Ѿ��ϲ���������ĸ���Ϊdp[x][0~j]*up[0~min(j,s-j)]
���������y�Ŀ�������dp[x][0~min(j,s-j)]*up[0~j]
 ������������������ͼ���, ��Ȼע��ö�ٵ�j����j*2<=s��ʱ���ظ�������dp[i][0~j]*up[0~j]

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
