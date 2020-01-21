#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 500000
using namespace std;
int n,m;
struct link_cut_tree {
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1])
#define fa(x) (tree[x].fa)
#define id1(x) (tree[x].id[1])
#define id2(x) (tree[x].id[2])
	struct node {
		int ch[2];
		int fa;
		int sum;//1的个数
		int id[3];
//		id[1]表示以该节点为子树的最深的sum不为1的点
//    	id[2]表示以该节点为子树的最深的sum不为2的点
		int addm;
//		int revm;这棵LCT不需要make_root,所以不需要反转标记
	} tree[maxn*3+5];
	inline bool is_root(int x) {
		return !(lson(fa(x))==x||rson(fa(x))==x);
	}
	inline int check(int x) {
		return rson(fa(x))==x;
	}
	void push_up(int x) {
		id1(x)=id1(rson(x));//由于Splay按深度排序，最深的一定是右子树
		if(tree[x].sum!=1&&id1(x)==0) id1(x)=x;//如果右子树不行且x合法,选x
		if(id1(x)==0) id1(x)=id1(lson(x));//还是不行，选x的左子树
		id2(x)=id2(rson(x));
		if(tree[x].sum!=2&&id2(x)==0) id2(x)=x;
		if(id2(x)==0) id2(x)=id2(lson(x));
	}
	void add_tag(int x,int val) {
		tree[x].sum+=val;
		tree[x].addm+=val;
		swap(tree[x].id[1],tree[x].id[2]);
		//整棵树打完标记后1,2交换,所以id也可以直接交换
	}
	void push_down(int x) {
		if(tree[x].addm) {
			add_tag(lson(x),tree[x].addm);
			add_tag(rson(x),tree[x].addm);
			tree[x].addm=0;
		}
	}
	void push_down_all(int x) {
		if(!is_root(x)) push_down_all(fa(x));
		push_down(x);
	}
	void rotate(int x) {
		int y=fa(x),z=fa(y),k=check(x),w=tree[x].ch[k^1];
		tree[y].ch[k]=w;
		tree[w].fa=y;
		if(!is_root(y)) tree[z].ch[check(y)]=x;
		tree[x].fa=z;
		tree[x].ch[k^1]=y;
		tree[y].fa=x;
		push_up(y);
		push_up(x);
	}
	void splay(int x) {
		push_down_all(x);
		while(!is_root(x)) {
			int y=fa(x);
			if(!is_root(y)) {
				if(check(x)==check(y)) rotate(y);
				else rotate(x);
			}
			rotate(x);
		}
		push_up(x);
	}
	void access(int x) {
		for(int y=0; x; y=x,x=fa(x)) {
			splay(x);
			rson(x)=y;
			push_up(x);
		}
	}
	void change(int x,int now_c,int &ans) {
//		if(x==6){
//			x=6;
//		}
		//now_c 当前(未修改)的状态 
		int f=fa(x);
		access(f);
		splay(f);
		//每次更新显然只有x到根的最底下一段连续sum=1或连续sum=2发生改变 
		int hd=tree[f].id[now_c+1];//x到根的链上深度最深的sum!=now_c+1的节点 
		//从被修改点到hd(不包含)上这段需要修改 
		//如果now_c从0变1，只有sum=1的点的状态会变化 
		int delta=(now_c==0?1:-1);
		//如果now_c从0变1，sum就要+1 
		if(hd) {
			splay(hd);
			add_tag(rson(hd),delta);
			push_up(rson(hd));
			tree[hd].sum+=delta;//hd的sum会变，但输出不变 
			push_up(hd);
		}else{
			//hd不存在,说明这次修改会影响到从该节点到根的所有点 
			//根节点的输出取反
			ans^=1; 
			add_tag(f,delta);
			push_up(f);
		}
	}
#undef fa
#undef lson
#undef rson
#undef id1
#undef id2
} T;

int col[maxn*3+5];

struct edge {
	int from;
	int to;
	int next;
} E[maxn*6+5];
int head[maxn*3+5];
int sz=1;
void add_edge(int u,int v) {
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}
void dfs(int x,int fa) { //初始化一开始的树
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(y!=fa) {
			dfs(y,x);
			T.tree[x].sum+=col[y]==1;
			if(T.tree[x].sum>=2) col[x]=1; 
		}
	}
}


int main(){
	int x,x1,x2,x3;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d %d",&x1,&x2,&x3);
		T.tree[x1].fa=T.tree[x2].fa=T.tree[x3].fa=i;
		add_edge(i,x1);
		add_edge(i,x2);
		add_edge(i,x3);
	}
	for(int i=n+1;i<=n*3+1;i++) scanf("%d",&col[i]);
	dfs(1,0);
	int ans=col[1];
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		T.change(x,col[x],ans);
		col[x]^=1;
		printf("%d\n",ans);
	}
}

