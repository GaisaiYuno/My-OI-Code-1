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
		int sum;//1�ĸ���
		int id[3];
//		id[1]��ʾ�Ըýڵ�Ϊ�����������sum��Ϊ1�ĵ�
//    	id[2]��ʾ�Ըýڵ�Ϊ�����������sum��Ϊ2�ĵ�
		int addm;
//		int revm;���LCT����Ҫmake_root,���Բ���Ҫ��ת���
	} tree[maxn*3+5];
	inline bool is_root(int x) {
		return !(lson(fa(x))==x||rson(fa(x))==x);
	}
	inline int check(int x) {
		return rson(fa(x))==x;
	}
	void push_up(int x) {
		id1(x)=id1(rson(x));//����Splay��������������һ����������
		if(tree[x].sum!=1&&id1(x)==0) id1(x)=x;//���������������x�Ϸ�,ѡx
		if(id1(x)==0) id1(x)=id1(lson(x));//���ǲ��У�ѡx��������
		id2(x)=id2(rson(x));
		if(tree[x].sum!=2&&id2(x)==0) id2(x)=x;
		if(id2(x)==0) id2(x)=id2(lson(x));
	}
	void add_tag(int x,int val) {
		tree[x].sum+=val;
		tree[x].addm+=val;
		swap(tree[x].id[1],tree[x].id[2]);
		//�����������Ǻ�1,2����,����idҲ����ֱ�ӽ���
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
		//now_c ��ǰ(δ�޸�)��״̬ 
		int f=fa(x);
		access(f);
		splay(f);
		//ÿ�θ�����Ȼֻ��x�����������һ������sum=1������sum=2�����ı� 
		int hd=tree[f].id[now_c+1];//x������������������sum!=now_c+1�Ľڵ� 
		//�ӱ��޸ĵ㵽hd(������)�������Ҫ�޸� 
		//���now_c��0��1��ֻ��sum=1�ĵ��״̬��仯 
		int delta=(now_c==0?1:-1);
		//���now_c��0��1��sum��Ҫ+1 
		if(hd) {
			splay(hd);
			add_tag(rson(hd),delta);
			push_up(rson(hd));
			tree[hd].sum+=delta;//hd��sum��䣬��������� 
			push_up(hd);
		}else{
			//hd������,˵������޸Ļ�Ӱ�쵽�Ӹýڵ㵽�������е� 
			//���ڵ�����ȡ��
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
void dfs(int x,int fa) { //��ʼ��һ��ʼ����
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

