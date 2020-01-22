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
		return x == fa[x]?x:fa[x]=find(fa[x]);
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

int used_point[maxn];
int maxd,maxu;
void dfs(int u,int d,int pre){
	if(d>maxd){
		maxd=d;
		maxu=u;
	}
	int s=E[u].size();
	for(int i=0;i<s;i++){
		if(E[u][i]==pre) continue;
		dfs(E[u][i],d+1,u);
	}
}
int get_d(int u){
	maxd=maxu=-1;
	dfs(u,0,-1);
	maxd=-1;
	dfs(maxu,0,-1);
	return maxd;
}

union_find_set S;
int main() {
	freopen("tree.in","r",stdin);
	freopen("tree.out1","w",stdout);
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
	int cnt=0;
	for(int i=1;i<=n;i++){
//		if(i==8){
//			i=8;
//		}
		int u=S.find(i);
		if(S.used_cc[u]) continue;
		S.used_cc[u]=1;
		int d=get_d(u);
		S.ans[u]=d;
		cnt++;
	}
//	printf("dfs %d times\n",cnt);
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
