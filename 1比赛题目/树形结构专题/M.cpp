//https://www.cnblogs.com/GXZlegend/p/8315275.html
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005 
#define INF 0x3f3f3f3f
using namespace std;
struct tag{
	int a;
	int b;
	//表示先给区间内数+a，再和b取max
	//区间+相当于打标记(a,-INF),区间=相当于标记(-INF,a) 
	tag(){
		a=0;
		b=-INF; 
	}
	tag(int x,int y){
		a=x;
		b=y;
	}
	friend tag operator + (tag x,tag y){
		return tag(max(x.a+y.a,-INF),max(x.b+y.a,y.b));
		//将x,y合并（先x后y) 
	}
}; 
tag getmax(tag x,tag y){
	return tag(max(x.a,y.a),max(x.b,y.b));//标记取最值 
}
int a[maxn];
struct node{
	int l;
	int r;
	int nmax;
	int pmax;
	tag nmark;
	tag pmark;
	int len(){
		return r-l+1;
	}
}tree[maxn<<2];
void push_up(int pos){
	tree[pos].nmax=max(tree[pos<<1].nmax,tree[pos<<1|1].nmax);
	tree[pos].pmax=max(tree[pos<<1].pmax,tree[pos<<1|1].pmax);
}
void build(int l,int r,int pos){
	tree[pos].nmark=tree[pos].pmark=tag();
	tree[pos].l=l;
	tree[pos].r=r;
	if(l==r){
		tree[pos].nmax=tree[pos].pmax=a[l];
		return;
	}
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
	push_up(pos); 
}
void push_down(int pos){
	int l=pos<<1;
	int r=pos<<1|1;
	tree[l].pmark=getmax(tree[l].pmark,tree[l].nmark+tree[pos].pmark);//跟历史值取max 
	tree[l].nmark=tree[l].nmark+tree[pos].nmark;//现在的值直接修改 
	tree[l].pmax=max(tree[l].pmax,max(tree[l].nmax+tree[pos].pmark.a,tree[pos].pmark.b));
	//max(tree[l].nmax+tree[pos].pmark.a,tree[pos].pmark.b)相当于打完上面下传标记后的值 
	tree[l].nmax=max(tree[l].nmax+tree[pos].nmark.a,tree[pos].nmark.b);
	
	tree[r].pmark=getmax(tree[r].pmark,tree[r].nmark+tree[pos].pmark);
	tree[r].nmark=tree[r].nmark+tree[pos].nmark;
	tree[r].pmax=max(tree[r].pmax,max(tree[r].nmax+tree[pos].pmark.a,tree[pos].pmark.b));
	tree[r].nmax=max(tree[r].nmax+tree[pos].nmark.a,tree[pos].nmark.b);
	
	tree[pos].pmark=tree[pos].nmark=tag();
}

void update(int L,int R,tag v,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		tree[pos].pmark=getmax(tree[pos].pmark,tree[pos].nmark+v);
		tree[pos].nmark=tree[pos].nmark+v;
		tree[pos].nmax=max(tree[pos].nmax+v.a,v.b);
		tree[pos].pmax=max(tree[pos].pmax,tree[pos].nmax);
		return; 
	}
	push_down(pos);
	int mid=(tree[pos].l+tree[pos].r)>>1;
	if(L<=mid) update(L,R,v,pos<<1);
	if(R>mid) update(L,R,v,pos<<1|1);
	push_up(pos);
}

int query(int L,int R,int type,int pos){
	if(L<=tree[pos].l&&R>=tree[pos].r){
		if(type==0) return tree[pos].pmax;
		else if(type==1) return tree[pos].nmax;
	}
	int mid=(tree[pos].l+tree[pos].r)>>1;
	int ans=-INF;
	push_down(pos); 
	if(L<=mid) ans=max(ans,query(L,R,type,pos<<1));
	if(R>mid) ans=max(ans,query(L,R,type,pos<<1|1));
	return ans;
}
int n,m;
char cmd[5];
int main(){
	int u,v,w;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}  
	build(1,n,1);
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%s",cmd);
		if(cmd[0]=='Q'){
			scanf("%d %d",&u,&v);
			printf("%d\n",query(u,v,1,1)); 
		}else if(cmd[0]=='A'){
			scanf("%d %d",&u,&v);
			printf("%d\n",query(u,v,0,1)); 
		}else if(cmd[0]=='P'){
			scanf("%d %d %d",&u,&v,&w);
			update(u,v,tag(w,-INF),1);
		}else if(cmd[0]=='C'){
			scanf("%d %d %d",&u,&v,&w);
			update(u,v,tag(-INF,w),1);
		} 
	}
}
