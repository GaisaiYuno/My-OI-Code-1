//转换在:选择最少的点，使得能遍历到至少n-1个点（最后一个点可以推理）
//选x个点，则答案为(n-x)/n （凶手在n-x个点中） 
//显然先缩点再选入度为0的点 
//注意特判： 
//若点x入度为0，所在的强联通分量大小为1
//而且x直接到达的点的入度都>1 （防止y只被x连接，不选x就选不到y) 
//那么这个点不选也可以遍历到n-1个点
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<stack>
#include<map>
#define maxn 500005
using namespace std;
int n,m,st,p;
vector<int>G[maxn];
vector<int>D[maxn];
int tim=0;
int cnt=0;
int dfn[maxn];
int low[maxn];
int ins[maxn];
int belong[maxn];
int sz[maxn];
stack<int>s;
void tarjan(int x){
	s.push(x);
	ins[x]=1;
	dfn[x]=low[x]=++tim;
	int t=G[x].size();
	for(int i=0;i<t;i++){
		int y=G[x][i];
		if(!dfn[y]){
			tarjan(y);
			low[x]=min(low[x],low[y]);
		}else if(ins[y]){
			low[x]=min(low[x],dfn[y]);
		}
	}
	if(low[x]==dfn[x]){
		cnt++;
		int y;
		do{
			sz[cnt]++;
			y=s.top();
			s.pop();
			ins[y]=0;
			belong[y]=cnt;
		}while(x!=y);
	}
}

int in[maxn];
void graph_to_dag(){
	for(int i=1;i<=n;i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i=1;i<=n;i++){
		int t=G[i].size();
		for(int j=0;j<t;j++){
			int k=G[i][j];
			if(belong[i]!=belong[k]){
//				printf("debug%d %d\n",belong[i],belong[k]);
				D[belong[i]].push_back(belong[k]);
				in[belong[k]]++;
			}
		}
	}
}

int check(int x){
	if(in[x]>0||sz[x]>1) return 0;
	int t=D[x].size();
	for(int i=0;i<t;i++){
		if(in[D[x][i]]<=1) return 0;
	}
	return 1;
}
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		G[u].push_back(v);
	}
	graph_to_dag();
	int chosen=0;
	for(int i=1;i<=cnt;i++){
		if(in[i]==0){
			chosen++;
		}
	}
	for(int i=1;i<=cnt;i++){
		if(check(i)){
			chosen--;
			break;
		}
	}
	printf("%.6f\n",(double)(n-chosen)/n);
}
