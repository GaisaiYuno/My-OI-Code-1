#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<stack>
#define maxn 80000
using namespace std;
int n,m;
vector<int>E[maxn*2+5];
void add_edge(int u,int v){
	E[u].push_back(v);
}
inline int get_op(int x){
	if(x%2==1) return x+1;
	else return x-1; 
} 

int dfn[maxn*2+5];
int low[maxn*2+5];
stack<int>s;
int cnt=0,tim=0;
int bel[maxn*2+5];
bool ins[maxn*2+5];
void tarjan(int x){
	dfn[x]=low[x]=++tim;
	s.push(x);
	ins[x]=1;
	for(int y : E[x]){
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
			y=s.top();
			s.pop();
			ins[y]=0;
			bel[y]=cnt;
		}while(y!=x); 
	}
}

bool check(){
	for(int i=1;i<=n*2;i++){
		if(!dfn[i]) tarjan(i);
	}
	for(int i=1;i<=n;i++){
		if(bel[i*2-1]==bel[i*2]) return 0;
	}
	return 1;
}
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		add_edge(v,get_op(u));
		add_edge(u,get_op(v));
	}
	if(check()){
		for(int i=1;i<=n;i++){
			//我们按照拓扑序
			//若i*2-1的拓扑序在i*2之后，则选i*2-1
			//否则选了i*2之后会沿着有向边选到i*2-1，两个都选，矛盾
			//而tarjan的时候拓扑序越往后的编号越小 
			if(bel[i*2-1]<bel[i*2]) printf("%d\n",i*2-1);
			else printf("%d\n",i*2);
		}
	}else printf("NIE");
}

