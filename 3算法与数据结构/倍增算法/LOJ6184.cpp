#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#define INF 0x3f3f3f3f
#define maxn 100000
#define maxlogn 25
using namespace std;
int n,log2n,q;
vector<int>orig_t[maxn+5];//原树 
vector<int>vir_t[maxn+5];//虚树
void add_edge(vector<int> *vec,int u,int v){
	vec[u].push_back(v);
}

int tim;
int dfn[maxn+5];
int deep[maxn+5];
int maxd1[maxn+5],maxd2[maxn+5];//原树上每个点子树的最大深度/次大深度 
int anc[maxn+5][maxlogn+5];
int up[maxn+5][maxlogn+5];//x到anc[x][i]的路径上的节点的其他分叉子树里到x的最大距离 (u的其他分叉:u不在路径上的儿子) 
int down[maxn+5][maxlogn+5]; //x到anc[x][i]的路径上的节点的其他分叉子树里到anc[x][i]的最大距离 
inline int cmp_son(int x,int y){
	return maxd1[x]>maxd1[y];
}
void get_maxd(int x,int fa){
	dfn[x]=++tim;
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1;i<=log2n;i++){
		anc[x][i]=anc[anc[x][i-1]][i-1];
		up[x][i]=max(up[x][i-1],up[anc[x][i-1]][i-1]+(1<<(i-1)));
		down[x][i]=max(down[x][i-1]+(1<<(i-1)),down[anc[x][i-1]][i-1]); 
	}
	for(int i=0;i<(int)orig_t[x].size();i++){
		int y=orig_t[x][i];
		if(y!=fa){
			get_maxd(y,x);
			if(maxd1[y]+1>maxd1[x]){
				maxd2[x]=maxd1[x];
				maxd1[x]=maxd1[y]+1;
			}else if(maxd1[y]+1==maxd1[x]){
				maxd2[x]=maxd1[y]+1;
			}
		}
	}
	for(int i=0;i<(int)orig_t[x].size();i++){
		int y=orig_t[x][i];
		if(y!=fa){
			if(maxd1[y]+1==maxd1[x]){//如果最大距离所在的点正好在路径上，就用次大距离 
				up[y][0]=maxd2[x]+1;
				down[y][0]=maxd2[x];
			}else{
				up[y][0]=maxd1[x]+1;
				down[y][0]=maxd1[x];
			}
		}
	}
	orig_t[x].erase(lower_bound(orig_t[x].begin(),orig_t[x].end(),fa));//把父节点去掉，这样就可以直接对儿子排序 
	sort(orig_t[x].begin(),orig_t[x].end(),cmp_son);
}  

int lca(int x,int y){
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=log2n;i>=0;i--){
		if(deep[anc[x][i]]>=deep[y]) x=anc[x][i];
	} 
	if(x==y) return x;
	for(int i=log2n;i>=0;i--){
		if(anc[x][i]!=anc[y][i]){
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}

bool is_key[maxn+5];
int dkey[maxn+5];//到最近关键点的距离
void get_dkey_1(int x,int fa){
	if(is_key[x]) dkey[x]=0;
	else dkey[x]=INF;
	for(int i=0;i<(int)vir_t[x].size();i++){
		int y=vir_t[x][i];
		if(y!=fa){
			get_dkey_1(y,x);
			dkey[x]=min(dkey[x],dkey[y]+deep[y]-deep[x]);
		}
	}
} 
void get_dkey_2(int x,int fa){
	for(int i=0;i<(int)vir_t[x].size();i++){
		int y=vir_t[x][i];
		if(y!=fa){
			dkey[y]=min(dkey[y],dkey[x]+deep[y]-deep[x]);
			get_dkey_2(y,x);
		}
	}
} 
int find(int x,int d){//x向上走距离d到达的节点 
	for(int i=log2n;i>=0;i--){
		if(deep[anc[x][i]]-deep[x]<=d) x=anc[x][i];
	}
	return x;
}
int get_up(int x,int d){//x向上走距离d的路径上向上走的最远距离 
	int ans=0; 
	int left=d;//当前跳到的点到终点的距离 
	for(int i=log2n;i>=0;i--){
		if(deep[anc[x][i]]-deep[x]<=d){
			left-=(1<<i);
			ans=max(ans,left+down[x][i]);
			x=anc[x][i];
		}
	} 
	return ans;
} 
int get_down(int x,int d){//x向上走距离d的路径上向下走的最远距离 
	int ans=0;
	int used=0;//已经走过的距离
	for(int i=log2n;i>=0;i--){
		if(deep[anc[x][i]]-deep[x]<=d){
			ans=max(ans,used+up[x][i]);
			used+=(1<<i);
			x=anc[x][i];
		}
	} 
	return ans;
} 

int ans=0;
bool is_onvt[maxn+5]; 
void get_ans(int x,int fa){
	ans=max(ans,dkey[x]);
	for(int i=0;i<(int)vir_t[x].size();i++){
		int y=vir_t[x][i];
		if(y!=fa){
			is_onvt[find(y,deep[y]-deep[x]-1)]=1;
			int d=deep[y]-deep[x];
			if(d>1){
				//?????? 
				if(dkey[y]-dkey[x]==d){
					ans=max(ans,dkey[x]+1+get_up(y,d-1));
				}else if(dkey[x]-dkey[y]==d){
					ans=max(ans,dkey[y]+get_down(y,d-1));
				}else{
					int md=(deep[y]-deep[x]+dkey[x]-dkey[y])>>1;
					int mid=find(y,md);
			        ans=max(ans,get_up(mid,deep[mid]-deep[x]-1)+1+dkey[x]);
			        ans=max(ans,get_down(y,md)+dkey[y]);
				}
			}
			get_ans(y,x);
		}
	}
	for(int i=0;i<(int)orig_t[x].size();i++){
		int y=orig_t[x][i];
		if(!is_onvt[y]){
			ans=max(ans,dkey[x]+1+maxd1[y]);
			break;//按maxd排序过，第一个就是 
		}
	}
	vir_t[x].clear();
}

int top;
int s[maxn+5];
void insert(int x){
	if(top<=1){
		s[++top]=x;
		return;
	}
	int lc=lca(x,s[top]);
	if(lc==s[top]){
		s[++top]=x;
		return;
	}
	while(top>1&&deep[s[top-1]]>=deep[lc]){
		add_edge(vir_t,s[top-1],s[top]);
		top--;
	}
	if(s[top]!=lc){
		add_edge(vir_t,s[top],lc);
	}
	s[top]=lc;
	s[++top]=x;
}


bool cmp_node(int x,int y){
	return dfn[x]<dfn[y];
}
int solve(int *in,int k){
	sort(in+1,in+1+k,cmp_node);
	for(int i=1;i<=k;i++) is_key[in[i]]=1;
	int root=1;
	top=0;
	s[++top]=root;
	for(int i=1;i<=k;i++){
		if(in[i]!=root) insert(in[i]);
	}
	while(top>1){
		add_edge(vir_t,s[top-1],s[top]);
		top--;
	}
	get_dkey_1(root,0);
	get_dkey_2(root,0);
	ans=0;
	get_ans(root,0);
	for(int i=1;i<=k;i++) is_key[in[i]]=0;
	return ans;
}

int a[maxn+5];
int main(){
//	freopen("1.in","r",stdin);
	int k,u,v;
	scanf("%d %d",&n,&q);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(orig_t,u,v); 
		add_edge(orig_t,v,u); 
	}
	get_maxd(1,0);
	while(q--){ 
		scanf("%d",&k);
		for(int i=1;i<=k;i++) scanf("%d",&a[i]);
		printf("%d\n",solve(a,k));
	} 
}

