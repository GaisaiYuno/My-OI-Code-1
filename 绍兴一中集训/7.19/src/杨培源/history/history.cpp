#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300000
#define maxm 300000
#define maxlogn 32
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x/10>0) qprint(x/10);
		putchar(x%10+'0');
	}
}

int n,m;
struct per_set{
	struct node{
		int ls;
		int rs;
		int fa;
		int deep;
	}tree[maxn*maxlogn+5];
	int ptr;
	void build(int &x,int l,int r){
		x=++ptr;
		if(l==r){
			tree[x].fa=l;
			return;
		}
		int mid=(l+r)>>1;
		build(tree[x].ls,l,mid);
		build(tree[x].rs,mid+1,r);
	}
	void merge(int &x,int last,int to,int fa,int l,int r){
		x=++ptr;
		tree[x].ls=tree[last].ls;
		tree[x].rs=tree[last].rs;
		if(l==r){
			tree[x].fa=fa;
			tree[x].deep=tree[last].deep;
			return;
		}
		int mid=(l+r)>>1;
		if(to<=mid) merge(tree[x].ls,tree[last].ls,to,fa,l,mid);
		else merge(tree[x].rs,tree[last].rs,to,fa,mid+1,r);
	}
	void update(int x,int to,int val,int l,int r){
		if(l==r){
			tree[x].deep+=val;
			return;
		}
		int mid=(l+r)>>1;
		if(to<=mid) update(tree[x].ls,to,val,l,mid);
		else update(tree[x].rs,to,val,mid+1,r);
	}
	int get_id(int x,int to,int l,int r){
		if(l==r) return x;
		int mid=(l+r)>>1;
		if(to<=mid) return get_id(tree[x].ls,to,l,mid);
		else return get_id(tree[x].rs,to,mid+1,r);
	}
	int get_fa(int x,int to){
		int now=get_id(x,to,1,n);
		if(tree[now].fa==to) return now;
		else return get_fa(x,tree[now].fa);
	}
}T;
int root[maxm+5];

void merge(int x,int y,int ver){
	root[ver]=root[ver-1];
	int posx=T.get_fa(root[ver],x);
	int posy=T.get_fa(root[ver],y);
	if(T.tree[posx].fa!=T.tree[posy].fa){
		if(T.tree[posx].deep>T.tree[posy].deep) swap(posx,posy);
		T.merge(root[ver],root[ver-1],T.tree[posx].fa,T.tree[posy].fa,1,n);//fa[fx]=fy;
		if(T.tree[posx].deep==T.tree[posy].deep) T.update(root[ver],T.tree[posy].fa,1,1,n);
	}
}

bool judge(int x,int y,int ver){
	int posx=T.get_fa(root[ver],x);
	int posy=T.get_fa(root[ver],y);
	if(T.tree[posx].fa==T.tree[posy].fa) return 1;
	else return 0;
}
int sz=0;
int main(){
	char cmd[2];
	int u,v,c,t;
	c=0;
	bool is_angry=false;
	qread(n);
	qread(m);
	T.build(root[0],1,n);
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='K'){
			qread(c);
		}else if(cmd[0]=='R'){
			qread(u);
			qread(v);
			if(is_angry){
				u=(u+n+c)%n+1;
				v=(v+n+c)%n+1;
			}else{
				u++;
				v++;
			}
			sz++;
			merge(u,v,sz);
		}else{
			qread(u);
			qread(v);
			qread(t);
			u++;
			v++;
			if(judge(u,v,sz)){
				if(sz-t<0){
					if(u==v) is_angry=true;
					else is_angry=false;
				}else{
					if(!judge(u,v,sz-t)) is_angry=false;
					else is_angry=true;
				}
			}else is_angry=true;
			if(is_angry){
				putchar('N');
				putchar('\n');
			}else{
				putchar('Y');
				putchar('\n');
			}
		}
	}
}
