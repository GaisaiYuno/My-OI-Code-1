#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#define maxn 100005
#define lson tree[p].l
#define rson tree[p].r
#define mod 1000000
#define INF 0x3f3f3f3f
using namespace std;

struct node {
	int l;
	int r;
	int val;
	int dat;
	int cnt;
	int size;
} tree[maxn];
int tot=0;
int root;
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

int New(int val) {
	tree[++tot].val=val;
	tree[tot].dat=rand();
	tree[tot].cnt=1;
	tree[tot].size=1;
	return tot;
}

void build() {
	New(-INF);
	New(INF);
	root=1;
	tree[1].r=2;
	update(root);
}

void insert(int &p,int val) {
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

int get_pre(int val) {
	int ans=1;
	int p=root;
	while(p) {
		if(val==tree[p].val) {
			if(tree[p].l>0) {
				p=tree[p].l;
				while(tree[p].r>0) p=tree[p].r;
				ans=p;
			}
			break;
		}
		if(tree[p].val<val&&tree[p].val>tree[ans].val) ans=p;
		if(val<tree[p].val) p=lson;
		else p=rson;
	}
	return tree[ans].val;
}

int get_next(int val) {
	int ans=2;
	int p=root;
	while(p) {
		if(val==tree[p].val) {
			if(tree[p].r>0) {
				p=tree[p].r;
				while(tree[p].l>0) p=tree[p].l;
				ans=p;
			}
			break;
		}
		if(tree[p].val>val&&tree[p].val<tree[ans].val) ans=p;
		if(val<tree[p].val) p=lson;
		else p=rson;
	}
	return tree[ans].val;
}

void del(int &p,int val) {
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

int n;
int main(){
	int x,y,cnt,cur,pre,nex,tmp;
	long long ans=0;
	scanf("%d",&n);
	build();
	cnt=0;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x,&y);
		if(cnt==0||cur==x){
			cnt++;
			cur=x;
			insert(root,y);
		}else{
			pre=get_pre(y);
			nex=get_next(y);
			if(nex-y<y-pre){
				tmp=nex-y;
				del(root,nex);
			}else{
				tmp=y-pre;
				del(root,pre);
			}
			cnt--;
			ans=(ans+tmp)%mod;
		}
	}
	printf("%lld\n",ans);
} 
