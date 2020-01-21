//http://hzwer.com/4361.html 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
#define maxn 100005
#define INF 0x7fffffff
using namespace std;
int n,c;
struct point{
	int x;
	int y;
	int id;
	point(){
		
	}
	point(int xx,int yy,int i){
		x=xx;
		y=yy;
		id=i;
	}
	friend bool operator < (point p,point q){
		return p.x<q.x;
	}
};
point a[maxn],q[maxn*2];
int head=0,tail=0;

struct value{
	int v;
	int id;
	value(){
		
	}
	value(int y,int i){
		v=y;
		id=i;
	}
	friend bool operator < (value p,value q){
		if(p.v==q.v) return p.id<q.id;
		return p.v<q.v;
	} 
	friend bool operator <= (value p,value q){
		return p==q||p<q;
	} 
	friend bool operator > (value p,value q){
		if(p.v==q.v) return p.id>q.id;
		return p.v>q.v;
	} 
	friend bool operator >= (value p,value q){
		return p>q||p==q;
	} 
	friend bool operator == (value p,value q){
		return p.id==q.id&&p.v==q.v;
	}
};
struct treap{
	struct node{
		int ls;
		int rs;
		int cnt;
		int sz;
		value val;
		int dat; 
	}tree[maxn];
	int root;	 
	int ptr;
	int New(value val){
		ptr++;
		tree[ptr].ls=tree[ptr].rs=0;
		tree[ptr].cnt=tree[ptr].sz=1;
		tree[ptr].val=val;
		tree[ptr].dat=rand();
		return ptr;
	}
	void push_up(int x){
		tree[x].sz=tree[tree[x].ls].sz+tree[tree[x].rs].sz+tree[x].cnt;
	}
	void rturn(int &x){
		int y=tree[x].ls;
		tree[x].ls=tree[y].rs;
		tree[y].rs=x;
		x=y;
		push_up(tree[x].rs);
		push_up(x);
	}
	void lturn(int &x){
		int y=tree[x].rs;
		tree[x].rs=tree[y].ls;
		tree[y].ls=x;
		x=y;
		push_up(tree[x].ls);
		push_up(x);
	}
	void insert(int &x,value val){
		if(x==0){
			x=New(val);
			return;
		} 
		if(tree[x].val==val){
			tree[x].cnt++;
			push_up(x);
			return;
		}
		if(val<tree[x].val){
			insert(tree[x].ls,val);
			if(tree[tree[x].ls].dat>tree[x].dat){
				rturn(x);
			} 
		}else{
			insert(tree[x].rs,val);
			if(tree[tree[x].rs].dat>tree[x].dat){
				lturn(x);
			} 
		}
		push_up(x);
	}
	value get_pre(int x,value val){
		if(x==0) return value(-INF,0);
		if(tree[x].val>val) return get_pre(tree[x].ls,val);
		else return max(tree[x].val,get_pre(tree[x].rs,val)); 
	}
	value get_nex(int x,value val){
		if(x==0) return value(INF,0);
		if(tree[x].val<val) return get_nex(tree[x].rs,val);
		else return min(tree[x].val,get_nex(tree[x].ls,val)); 
	}
	void del(int &x,value val){
		if(x==0) return;
		if(tree[x].val==val){
			if(tree[x].cnt>1){ 
				tree[x].cnt--;
				push_up(x);
				return;
			}else{
				if(tree[x].ls||tree[x].rs){
					if(tree[x].rs==0||tree[tree[x].ls].dat>tree[tree[x].rs].dat){
						rturn(x);
						del(tree[x].rs,val);
					}
					else{
						lturn(x); 
						del(tree[x].ls,val);
					}
					push_up(x);
				}else x=0;
				return;
			} 
		}
		if(val<tree[x].val) del(tree[x].ls,val);
		else del(tree[x].rs,val);
		push_up(x);
	}
}T; 

struct DSU{
	int fa[maxn];
	int cnt[maxn];
	int tot;
	void ini(int n){
		tot=n;
		for(int i=1;i<=n;i++) fa[i]=i;
	}
	int find(int x){
		if(fa[x]==x) return x;
		else return fa[x]=find(fa[x]);
	}
	void merge(int x,int y){
		int fx=find(x);
		int fy=find(y);
		if(fx==fy) return;
		fa[find(x)]=find(y);
		tot--;
	} 
}S;
int main(){
//	freopen("2.in","r",stdin);
	int x,y;
	scanf("%d %d",&n,&c);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x,&y);
		a[i].x=x+y;
		a[i].y=x-y;
		a[i].id=i;
	}
	sort(a+1,a+1+n);
	S.ini(n);
	for(int i=1;i<=n;i++){
		while(head<tail&&a[i].x-q[head].x>c){
			T.del(T.root,value(q[head].y,q[head].id));
			head++;
		}
		value pre=T.get_pre(T.root,value(a[i].y,a[i].id));
		value nex=T.get_nex(T.root,value(a[i].y,a[i].id));
		if(pre.v!=-INF&&a[i].y-pre.v<=c) S.merge(a[i].id,pre.id);
		if(nex.v!=INF&&nex.v-a[i].y<=c) S.merge(a[i].id,nex.id);
		q[tail++]=a[i];
		T.insert(T.root,value(a[i].y,a[i].id));
	}
	for(int i=1;i<=n;i++){
		int f=S.find(i);
		S.cnt[f]++;
	}
	int ans=0,tot=0;
	for(int i=1;i<=n;i++){
		ans=max(ans,S.cnt[i]);
	}
	sort(S.fa+1,S.fa+1+n);
	tot=unique(S.fa+1,S.fa+1+n)-S.fa-1;
	printf("%d %d\n",tot,ans);
}

