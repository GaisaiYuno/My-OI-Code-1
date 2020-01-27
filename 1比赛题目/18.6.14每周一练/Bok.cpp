#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 100005
#define maxm 200005
#define maxc 1000005
using namespace std;
int n,m,s;
vector<int>E[maxn];//vector 方便看每个点是否出度为0 
struct qnode{
	int fa;
	int u;
	int ev;//记录是偶数次还是奇数次 
	int tim;
	qnode(){
		
	}
	qnode(int father,int x,int e,int tt){
		fa=father;
		u=x;
		ev=e;
		tim=tt;
		
	}
}q[maxn*20]; 
int used[maxn][2];
int vis[maxn];
int head,tail;
void push_queue(int fx,int x,int y,int t){
	tail++;
	q[tail]=qnode(fx,x,y,t);
	used[x][y]=1;
}
int bfs(int x,int &is_long,int &last){
	push_queue(0,x,1,0);
	while(head<tail){
		head++;
		int lx=q[head].u;
		int ly=q[head].ev;
		if(!E[lx].size()){
			last=head;
			if(q[head].tim>1e6) is_long=1;
			if(!ly) return 1;
		}else{
			int si=E[lx].size();
			for(int i=0;i<si;i++){
				if(!used[E[lx][i]][!ly]){
					push_queue(head,E[lx][i],!ly,q[head].tim+1);
				}
			}
		}	
	}
	return 0;
}
void output(int x){
	if(x!=0) output(q[x].fa);
	else return;
	printf("%d ",q[x].u);
}
int dfs(int x){
	vis[x]=1;
	int si=E[x].size();
	for(int i=0;i<si;i++){
		if(vis[E[x][i]]==1) return 1;
		else if(!vis[E[x][i]]){
			if(dfs(E[x][i])) return 1;
		}
	}
	vis[x]=-1;
	return 0;
}
int main(){
	int c,u,v; 
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&c);
		for(int j=1;j<=c;j++){
			scanf("%d",&v);
			E[i].push_back(v);
		}
	}
	scanf("%d",&s);
	int is_long,las;
	is_long=0;
	las=0;
	memset(used,0,sizeof(used));
	memset(vis,0,sizeof(vis));
	int is_win=bfs(s,is_long,las);
	if(is_win){
		printf("Win\n");
		output(las);
	}else if(is_long||dfs(s)){
		printf("Draw\n");
	}else{
		printf("Lose\n");
	}
}
