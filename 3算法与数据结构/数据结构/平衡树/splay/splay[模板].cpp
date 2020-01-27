#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005 
#define INF 0x3f3f3f3f
using namespace std;
struct Splay {
#define lson(x) tree[x].ch[0]
#define rson(x) tree[x].ch[1]
	struct node {
		int fa;
		int ch[2];
		int val;
		int sz;
		int cnt;
	} tree[maxn];
	int ptr;
	int root;
	void push_up(int x) {
		tree[x].sz=tree[x].cnt+tree[lson(x)].sz+tree[rson(x)].sz;
	}
	int chk(int x) { //�ж�x������ӻ����Ҷ���
		return rson(tree[x].fa)==x;
	}
	int New(int val) {
		ptr++;
		tree[ptr].ch[0]=tree[ptr].ch[1]=0;
		tree[ptr].val=val;
		tree[ptr].cnt=tree[ptr].sz=1;
		return ptr;
	}
	void rotate(int x) { //��x��ת�����ڵ�
		int y=tree[x].fa,z=tree[y].fa,k=chk(x),w=tree[x].ch[k^1];
		tree[y].ch[k]=w;
		tree[w].fa=y;
		tree[z].ch[chk(y)]=x;
		tree[x].fa=z;
		tree[x].ch[k^1]=y;
		tree[y].fa=x;
		push_up(y);
		push_up(x);
	}
	void splay(int x,int goal=0) { //��xת��goal���ӽڵ㣬goalĬ��=0��ʱ��ת����
		while(tree[x].fa!=goal) {
			int y=tree[x].fa;
			int z=tree[y].fa;
			if(z!=goal) {
				if(chk(x)==chk(y)) rotate(y);
				else rotate(x);
			}
			rotate(x);
		}
		if(!goal) root=x;
	}

	void find(int val) { //�ҵ�����<=val����������ת����
		if(!root) return;
		int cur=root;
		while(tree[cur].ch[val>tree[cur].val]&&val!=tree[cur].val) {
			cur=tree[cur].ch[val>tree[cur].val];
		}
		splay(cur);
	}

	void insert(int val) {
		int cur=root;
		int f=0;
		while(cur&&tree[cur].val!=val) {
			f=cur;
			cur=tree[cur].ch[val>tree[cur].val];
		}
		if(cur!=0) {
			tree[cur].cnt++;//����push_up��Ϊsplay���Ѿ�pushup����
		} else {
			cur=New(val);
			if(f) tree[f].ch[val>tree[f].val]=cur;
			tree[cur].fa=f;
		}
		splay(cur);
	}

	int get_val(int k) {
		int x=root;
		while(1) {
			if(lson(x)&&k<=tree[lson(x)].sz) {
				x=lson(x);
			} else if(k<=tree[lson(x)].sz+tree[x].cnt) {
				return tree[x].val;
			} else {
				k-=tree[lson(x)].sz+tree[x].cnt;
				x=rson(x);
			}
		}
		return 0;
	}

	int get_rank(int val) {
		find(val);
		return tree[lson(root)].sz+1;
	}

	int _pre(int val) { //ע�ⷵ�ص���λ�ö�����ֵ
		find(val);
		if(tree[root].val<val) return root;
		int cur=lson(root);
		while(rson(cur)) {
			cur=rson(cur);
		}
		return cur;
	}
	int pre(int val) {
		return tree[_pre(val)].val;
	}
	
	int _nex(int val) {
		find(val);
		if(tree[root].val>val) return root;
		int cur=rson(root);
		while(lson(cur)) {
			cur=lson(cur);
		}
		return cur;
	}
	int nex(int val){
		return tree[_nex(val)].val;
	}
//	ǰ��splay���������splay��ǰ�����Ҷ��ӣ���ô��̵�����Ӿ���Ҫɾ���ĵ㡣
	void del(int val) {
		int pre=_pre(val),nex=_nex(val); 
		splay(pre);
		splay(nex,pre);
		int del=lson(rson(pre));
		if(tree[del].cnt>1){
			tree[del].cnt--;
			splay(del);
		}else lson(nex)=0; 
	}

}T;

int n;
int main() {
#ifdef FILE_IO
	freopen("input2.in","r",stdin);
#endif
	int opt,x;
	scanf("%d",&n);
	T.insert(-INF);
	T.insert(INF);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&opt,&x); 
//		printf("ok %d %d\n",opt,x);
		if(opt==4&&x==3){
			opt=4;
		}
		switch(opt){
			case(1):{
				T.insert(x);
				break;
			} 
			case(2):{
				T.del(x);
				break;
			}
			case(3):{
				printf("%d\n",T.get_rank(x)-1);
				break;
			}
			case(4):{
				printf("%d\n",T.get_val(x+1));
				break;
			} 
			case(5):{
				printf("%d\n",T.pre(x));
				break;
			}
			case(6):{
				printf("%d\n",T.nex(x));
				break;
			}
			default:{
				
				break;
			} 
		}
	}
}

