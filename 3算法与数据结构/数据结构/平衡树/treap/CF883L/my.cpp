#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<queue>
#define maxn 200005
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,k,m;
struct key_type {
	int pos;//位置 
	int id;//编号 
	long long tim;//到达当前位置的时刻 
	key_type() {

	}
	key_type(int x,int num,long long stime) {
		pos=x;
		id=num;
		tim=stime;
	}
	friend bool operator < (key_type a,key_type b) {
		if(a.pos==b.pos) {
			if(a.tim==b.tim) {
				return a.id<b.id;
			} else return a.tim<b.tim;
		} else return a.pos<b.pos;
	}
	friend bool operator == (key_type a,key_type b) {
		return a.pos==b.pos&&a.id==b.id&&a.tim==b.tim;
	}
	friend bool operator > (key_type a,key_type b) {
		return !(a<b||a==b);
	}
};

struct heap_node {
	int id;
	long long tim;
	heap_node() {

	}
	heap_node(int iden,long long t) {
		id=iden;
		tim=t;
	}
	friend bool operator < (heap_node a,heap_node b) {
		return a.tim>b.tim;
	}
};
priority_queue<heap_node>H;

struct Treap {
#define lson tree[p].l
#define rson tree[p].r
	struct treap_node {
		int l;
		int r;
		key_type val;
		int dat;
		int cnt;
		int size;
	} tree[maxn<<2];
	int root;
	int tot;
	int node_cnt;

	void update(int p) {
		tree[p].size=tree[lson].size+tree[rson].size+tree[p].cnt;
	}

	void zig(int &p) {
		int q=tree[p].l;
		tree[p].l=tree[q].r;
		tree[q].r=p;
		p=q;
		update(tree[p].r);
		update(p);
	}

	void zag(int &p) {
		int q=tree[p].r;
		tree[p].r=tree[q].l;
		tree[q].l=p;
		p=q;
		update(tree[p].l);
		update(p);
	}
	int New(key_type val) {
		tot++;
		tree[tot].val=val;
		tree[tot].dat=rand();
		tree[tot].size=1;
		tree[tot].cnt=1;
		return tot;
	}

	void build() {
		New(key_type(-INF,-INF,-LINF));
		New(key_type(INF,INF,LINF));
		root=1;
		tree[1].r=2;
		node_cnt=2;
		update(root);
	}

	void insert(int &p,key_type val) {
		if(p==0) {
			p=New(val);
			return;
		}
		if(val==tree[p].val) {
			tree[p].cnt++;
			update(p);
			return;
		}
		if(val<tree[p].val) {
			insert(lson,val);
			if(tree[lson].dat>tree[p].dat) zig(p);
		} else {
			insert(rson,val);
			if(tree[rson].dat>tree[p].dat) zag(p);
		}
		update(p);
	}
	void Insert(key_type val) {
		insert(root,val);
		node_cnt++;
	}

	int find(int p,int val) {
		if(p==0) return 0;
		if(tree[p].val.pos==val) return 1;
		else if(val<tree[p].val.pos) return find(lson,val);
		else return find(rson,val);
	}
	int Find(int val) {
		return find(root,val);
	}
	int get_pre(int p,int pos,int now){
		if(!p) return now;
		if(tree[p].val.pos<=pos) return get_pre(rson,pos,p);
		else return get_pre(lson,pos,now); 
	}
	int get_next(int p,int pos,int now){
		if(!p) return now;
		if(tree[p].val.pos>=pos) return get_next(lson,pos,p);
		else return get_next(rson,pos,now); 
	}
//	int get_pre(int val) {
//		int ans=1;
//		int p=root;
//		while(p) {
//			if(val==tree[p].val.pos) {
//				while(tree[p].l>0&&tree[tree[p].l].val.pos==val) p=tree[p].l;
//				//这里不能按照模板向右走的原因是要求编号最小 
//				//如果向右走就变成了编号最大 
//				ans=p;
//				break;
//			}
//			if(tree[p].val.pos<val&&tree[p].val>tree[ans].val) ans=p;
//			if(val<tree[p].val.pos) p=lson;
//			else p=rson;
//		}
//		return ans;
//	}
//
//	int get_next(int val) {
//		int ans=2;
//		int p=root;
//		while(p) {
//			if(val==tree[p].val.pos) {
//				if(tree[p].r>0) {
//					p=tree[p].r;
//					while(tree[p].l>0) p=tree[p].l;
//					ans=p;
//				}
//				break;
//			}
//			if(tree[p].val.pos>val&&tree[p].val<tree[ans].val) ans=p;
//			if(val<tree[p].val.pos) p=lson;
//			else p=rson;
//		}
//		return ans;
//	}

	void del(int &p,key_type val) {
		if(p==0) return;
		if(val==tree[p].val) {
			if(tree[p].cnt>1) {
				tree[p].cnt--;
				update(p);
				return;
			}
			if(tree[p].l||tree[p].r) {
				if(tree[p].r==0||tree[lson].dat>tree[rson].dat) {
					zig(p);
					del(rson,val);
				} else {
					zag(p);
					del(lson,val);
				}
				update(p);
			} else p=0;
			return;

		}
		if(val<tree[p].val) del(lson,val);
		else del(rson,val);
		update(p);
	}
	void Delete(key_type val) {
		del(root,val);
		node_cnt--;
	}

	int empty() {
		return node_cnt<=2;
	}
#undef lson
#undef rson
};
Treap T;



int pos[maxn];
void take(key_type x,long long tt,long long aa,long long bb) {
	long long tim=max(x.tim-tt,0LL);
	tim+=abs(x.pos-aa);
	printf("%d %I64d\n",x.id,tim);
	H.push(heap_node(x.id,tt+tim+abs(aa-bb)));
//	cerr<<"push:"<<x.id<<' '<<tt+tim+abs(aa-bb)<<endl;
	pos[x.id]=bb;
}

int main() {
//	freopen("data.in","r",stdin);
//	freopen("data.out","w",stdout);
	int l,r,d1,d2;
	scanf("%d %d %d",&n,&k,&m);
	T.build();
	for(int i=1; i<=k; i++) {
		scanf("%d",&pos[i]);
		T.Insert(key_type(pos[i],i,0));
	}
	long long tt,lim;
	int aa,bb;
	key_type t1,t2;
	heap_node temp;
	for(int i=1; i<=m; i++) {
		scanf("%I64d %d %d",&tt,&aa,&bb);
		lim=tt;
		if(T.empty()&&!H.empty()) lim=max(tt,H.top().tim);
		while(!H.empty()) {
//			cerr<<i<<' '<<H.top().id<<endl;
			temp=H.top();
			if(temp.tim>lim) break;
//			cerr<<"pop1:"<<H.top().id<<' '<<H.top().tim<<endl;
//			cerr<<"key="<<pos[temp.id]<<' '<<temp.id<<' '<<temp.tim<<endl;
			T.Insert(key_type(pos[temp.id],temp.id,temp.tim));
//			if(!H.empty())cerr<<"pop2:"<<H.top().id<<' '<<H.top().tim<<endl;
			H.pop();
			if(H.empty()) break;
//			cerr<<"ok "<<i<<endl;
		}
//		int p=T.find(aa);
//		if(p!=0){
//			take(T.tree[p].val,tt,aa,bb);
//			T.Delete(T.tree[p].val);
//		}
		l=T.get_pre(T.root,aa,0);
		r=T.get_next(T.root,aa,0);
		if(l!=1) l=T.get_next(T.root,T.tree[l].val.pos,0);
//		if(T.Find(aa)&&T.tree[l].val.pos!=aa) l=T.get_next(T.tree[l].val.pos);
		if(l!=1&&r==2) {
			take(T.tree[l].val,tt,aa,bb);
			T.Delete(T.tree[l].val);
		} else if(l==1&&r!=2) {
			take(T.tree[r].val,tt,aa,bb);
			T.Delete(T.tree[r].val);
		} else if(l!=1&&r!=2) {
			d1=abs(T.tree[l].val.pos-aa);
			d2=abs(T.tree[r].val.pos-aa);
			t1=key_type(d1,T.tree[l].val.id,T.tree[l].val.tim);
			t2=key_type(d2,T.tree[r].val.id,T.tree[r].val.tim);
			if(t2<t1) {
				swap(l,r);
			}
			take(T.tree[l].val,tt,aa,bb);
			T.Delete(T.tree[l].val);
		}
	}
}


