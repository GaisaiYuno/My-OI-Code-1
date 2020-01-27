#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 500005
#define eps 1e-6 
using namespace std;
int n; 
struct edge{
	int from;
	int to;
	int next;
	double p;
}E[maxn<<1];
int head[maxn];
int size=0;
void add_edge(int u,int v,double c){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	E[size].p=c;
	head[u]=size;
}
int dcmp(double a,double b){
	return fabs(a-b)<eps;
}
double p_up[maxn],dp[maxn];//p_up表示儿子传给父亲的概率，dp表示儿子传给父亲和父亲传给儿子的概率之和
//注意概率的加减不能直接代数运算
//P(A+B)=P(A)+P(B)-P(A)*P(B) 
//P(A)=(P(A+B)-P(B))/(1-P(B)) 
void dfs(int x,int fa){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		double p=E[i].p;
		if(y!=fa){
			dfs(y,x);
			p_up[x]=p_up[x]+p_up[y]*p-p_up[x]*p_up[y]*p; //p_up[x]+=p_up[y] 
		}
	}
}
double ans=0;
void dfs2(int x,int fa){
	ans+=dp[x];
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		double p=E[i].p;
		if(y!=fa){
			if(!dcmp(1.0-p_up[y]*p,0)){
				double pfa=(dp[x]-p_up[y]*p)/(1.0-p_up[y]*p);//pfa=dp[x]-p_up[y]*p
				dp[y]=p_up[y]+pfa*p-p_up[y]*pfa*p;//dp[y]=p_up[y]+pfa*p
			}else dp[y]=1.0;
			dfs2(y,x);
		}
	}
}
int main(){
	int u,v,w;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w/100.0);
		add_edge(v,u,w/100.0);
	}
	for(int i=1;i<=n;i++){
		scanf("%lf",&p_up[i]);
		p_up[i]/=100.0; 
	} 
	dfs(1,0);
	dp[1]=p_up[1];
	dfs2(1,0);
	printf("%lf\n",ans);
}
