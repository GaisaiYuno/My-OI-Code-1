#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<bitset>
#define maxn 200005
using namespace std;
int n,m,k,q;
int in_car[maxn];//到达i时在车上的人数
int get_on[maxn];//在i站下车的人数
int get_off[maxn];//在i站上车的人数
int peo[maxn];
int sum[maxn];
typedef bitset<100> seat;
void print(seat x){
	for(int i=0;i<10;i++){
		cout<<x[i];
	}
	printf("\n");
}
struct node {
	int l;
	int r;
	int cnt;
	bool is_mark;
	seat lv;
	seat rv;
	seat mark;
	seat v;
} tree[maxn<<2];
void push_up(int pos) {
	
}
void build(int l,int r,int pos) {
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].cnt=0;
	tree[pos].is_mark=false;
	if(l==r) {
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
}

void push_down(int pos) {
	if(tree[pos].is_mark) {
		tree[pos<<1].v|=tree[pos].mark;
		tree[pos<<1|1].v|=tree[pos].mark;
		tree[pos<<1].mark|=tree[pos].mark;
		tree[pos<<1|1].mark|=tree[pos].mark;
		tree[pos].is_mark=false;
	}
}
void update(int L,int R,int k,int pos) {
	if(L<=tree[pos].l&&R>=tree[pos].r) {
		tree[pos].cnt=0;
		tree[pos].v[k]=1;
		tree[pos].mark[k]=1;
		tree[pos].is_mark=true;
//		print(tree[pos].v);
		return;
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) update(L,R,k,pos<<1);
	if(R>mid) update(L,R,k,pos<<1|1);
	push_up(pos);
}

seat query(int L,int R,int pos) {
	if(L<=tree[pos].l&&R>=tree[pos].r) {
//		print(tree[pos].v);
		return tree[pos].v;
	}
	push_down(pos);
	seat ans;
	ans.set(0);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) ans|=query(L,R,pos<<1);
	if(R>mid) ans|=query(L,R,pos<<1|1);
	return ans;
}

int maxv=0;
seat sta[maxn];
int get_ans(int l,int r){
	if(sum[r]-sum[l-1]>0) return -1;
	seat tmp;
	int ans=0;
	for(int i=l;i<r;i++){
		tmp=(~sta[l])&(~sta[r]);
		if(tmp.count()==10-maxv) ans++;
	} 
	return ans;
}
int main() {
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	int x,y,v;
	scanf("%d %d %d",&n,&m,&k);
	build(1,n,1);
	for(int i=1; i<=m; i++) {
		scanf("%d %d %d",&x,&y,&v);
		get_on[x]++;
		get_off[y]++;
		in_car[x+1]++;
		in_car[y+1]--;
		update(x,y-1,v-1,1);
		maxv=max(v,maxv);
	}
	for(int i=1; i<=n; i++) {
		in_car[i]+=in_car[i-1];
	}
	for(int i=1; i<=n; i++) {
		peo[i]=in_car[i]-get_off[i]+get_on[i];
//		printf("%d ",peo[i]);
		if(peo[i]==k) sum[i]=1;
	}
	for(int i=1;i<=n;i++){
	    sta[i]=(query(i,i,1));
//		printf("%d\n",sta[i].count());
//		print(sta[i]);
		sum[i]+=sum[i-1];
	} 
	scanf("%d",&q);
	for(int i=1;i<=q;i++){
		scanf("%d %d",&x,&y);
		printf("%d\n",get_ans(x,y));
	}
}
