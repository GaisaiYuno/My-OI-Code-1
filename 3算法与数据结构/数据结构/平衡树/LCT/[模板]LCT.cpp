#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300000
using namespace std;
int n,m;
struct LCT{
#define fa(x) (tree[x].fa)
#define lson(x) (tree[x].ch[0])
#define rson(x) (tree[x].ch[1])
	struct node{
		int fa;
		int ch[2];
		int sum;
		int val;
		int mark;
	}tree[maxn+5];
	inline bool is_root(int x){
		return !(lson(fa(x))==x||rson(fa(x))==x);
	}
	inline int check(int x){
		return rson(fa(x))==x;
	}
	void push_up(int x){
		tree[x].sum=tree[lson(x)].sum^tree[rson(x)].sum^tree[x].val;	
	}
	void reverse(int x){
		if(x==0) return;
		swap(lson(x),rson(x));
		tree[x].mark^=1;
	}
	void push_down(int x){
		if(tree[x].mark){
			reverse(lson(x));
			reverse(rson(x));
			tree[x].mark=0;
		}
	}
	void push_down_all(int x){//��x����push_down 
		if(!is_root(x)) push_down_all(fa(x));//�ݹ鵽�� 
		push_down(x);//����ʱ��������push_down 
	}
	void rotate(int x){
		int y=fa(x),z=fa(y),k=check(x),w=tree[x].ch[k^1];
		tree[y].ch[k]=w;
		tree[w].fa=y;
		if(!is_root(y)) tree[z].ch[check(y)]=x;
		tree[x].fa=z;//�ϸ������� 
		tree[x].ch[k^1]=y;
		tree[y].fa=x;
		push_up(y);
		push_up(x); 
	}
	void splay(int x){
		int y;
		push_down_all(x);
		while(!is_root(x)){
			y=fa(x);
//			z=fa(y);
			if(!is_root(y)){
				if(check(x)==check(y)) rotate(y);
				else rotate(x);
			}
			rotate(x);
		}
		push_up(x);
	}
	void access(int x){//��x��ԭ���ĸ�����һ��splay�x�����ұ� 
		for(int y=0;x;y=x,x=fa(x)){
			splay(x);
			rson(x)=y;
			push_up(x);
		}
	}
	void make_root(int x){//������ʹx��Ϊԭ���ĸ� 
		access(x);
		splay(x);//x������������Ľڵ� 
		reverse(x);//��ת�����������˳�򵹹���,x��Ϊ�� 
	}
	void split(int x,int y){//�ֳ�·��(x,y),yΪ�� 
		make_root(x);
		access(y);
		splay(y);
	}
	int find_root(int x){//�ҵ�x����ԭ���ĸ�,�����˳����С�� 
		access(x);
		splay(x);
		while(lson(x)){
			push_down(x);
			x=lson(x); 
		}
//		splay(x);
		return x;
	}
	void link(int x,int y){
		make_root(x);
		if(find_root(y)==x) return; //��֤�����Ϸ����� 
		fa(x)=y;
	}
	void cut(int x,int y){
		make_root(x);		
		if(find_root(y)!=x||fa(y)!=x||lson(y)) return; //��֤�����Ϸ����� 
		fa(y)=rson(x)=0;//�����if����xת�ɸ� 
		push_up(x);

/*��֤�����Ϸ�ʱ����д 
		split(x,y);
		lson(y)=fa(x)=0;
		push_up(y);
*/
	} 
	int query(int x,int y){
		split(x,y);
		return tree[y].sum;
	}
	void update_point(int x,int val){
		splay(x);
		tree[x].val=val;
		push_up(x);
	}
#undef fa
#undef lson
#undef rson
}T;

int main(){
	int cmd,x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&T.tree[i].val);
		T.tree[i].sum=T.tree[i].val;
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d %d",&cmd,&x,&y);
		if(cmd==0){
			printf("%d\n",T.query(x,y));
		}else if(cmd==1){
			T.link(x,y);
		}else if(cmd==2){
			T.cut(x,y);
		}else{
			T.update_point(x,y);
		}
	}
}

