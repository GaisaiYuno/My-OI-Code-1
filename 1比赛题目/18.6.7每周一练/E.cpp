#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define maxn 300005
using namespace std;
int n,m,q;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign; 
}

vector<int>E[maxn];
int size=0;
void add_edge(int u,int v) {
	E[u].push_back(v);
}

struct union_find_set {//并查集 
	int fa[maxn];
	int ans[maxn];//连通分量直径 
	int used_cc[maxn];//连通分量是否计算过 
	void init() {
		for(int i=1; i<=n; i++) fa[i]=i;
	}
	int find(int x){
		if(fa[x]==x) return x;
		else{
			fa[x]=find(fa[x]);
			return fa[x];
		}
	}
	void union_set(int x,int y){
		int fx=find(x);
		int fy=find(y);
		if(fx>fy) swap(fx,fy);
		fa[fy]=fx;
	}
	void cal_len(int x,int y){
		x=find(x);
		y=find(y);
		if(x>y) swap(x,y);
		fa[y]=x;
		int dx=ans[x],dy=ans[y];
		ans[x]=max(max(dx,dy),(dx+1)/2+(dy+1)/2+1);//d(i,j)=max(max(di,dj),(di+1)/2+(dj+1)/2+1) 
	}
};

struct bfs_node{
	int u;
	int d;
	bfs_node(){
		
	}
	bfs_node(int x,int dis){
		u=x;
		d=dis;
	}
};
int used_point[maxn*2];
bfs_node bfs(int u){//求直径 
	queue<bfs_node>q;
	memset(used_point,0,sizeof(used_point));
	q.push(bfs_node(u,0));
	bfs_node ans=bfs_node(u,0);
	while(!q.empty()){
		bfs_node now=q.front();
		q.pop();
		if(used_point[now.u]) continue;
		used_point[now.u]=1;
		if(now.d>ans.d){
			ans.d=now.d;
			ans.u=now.u;
		}
		int s=E[now.u].size();
		for(int i=0;i<s;i++){
//			if(used_point[E[u][i]]) continue;
			if(E[now.u][i]==now.u) continue;
			else q.push(bfs_node(E[now.u][i],now.d+1));
		}
//		for(int i=head[now.u];i;i=E[i].next){
//			if(used_point[E[i].to]) continue;
//			else q.push(bfs_node(E[i].to,now.d+1));
//		}
	}
	return ans;
}
int get_d(int u){
	bfs_node x1=bfs(u);
	bfs_node x2=bfs(x1.u);
	return x2.d;
}

union_find_set S;
int main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout); 
	int x,y;
	scanf("%d %d %d",&n,&m,&q);
	S.init();
	for(int i=1;i<=m;i++){
		//scanf("%d %d",&x,&y);
		x=qread();
		y=qread();
		add_edge(x,y);
		add_edge(y,x);
		S.union_set(x,y);
	}
	for(int i=1;i<=n;i++){
		int u=S.find(i);
		if(S.used_cc[u]) continue;
		S.used_cc[u]=1;
		int d=get_d(u);
		S.ans[u]=d;
	}
	int cmd;
	for(int i=1;i<=q;i++){
//		scanf("%d",&cmd);
		cmd=qread();
		if(cmd==1){
//			scanf("%d",&x);
			x=qread();
			printf("%d\n",S.ans[S.find(x)]);
		}else if(cmd==2){
//			scanf("%d %d",&x,&y);
			x=qread();
			y=qread();
			if(S.find(x)==S.find(y)) continue;
			S.cal_len(x,y);
		}
	}
}
