#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<map>
#include<utility>
#include<algorithm>
#define maxn 200000
#define maxm 500000
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
inline void qprint(long long x){
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

int n,m,w,h;
struct city{
	int x;
	int y;
	int id;
	city(){
		
	}
	city(int _x,int _y,int _id){
		x=_x;
		y=_y;
		id=_id;
	}
	friend bool operator < (city p,city q){
		if(p.x==q.x){
			if(p.y==q.y) return p.id<q.id;
			else return p.y<q.y;
		}
		else return p.x<q.x;
	}
}a[maxn+5];
struct portal{
	int p;
	int t;
	int l,r,d,u;
}b[maxm+5];


struct edge{
	int from;
	int to;
	int len;
	int next;
}E[maxm*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].len=w;
	head[u]=sz;
}

struct node{
	int id;
	long long dist;
	node(){
		
	}
	node(int _id,long long _dist){
		id=_id;
		dist=_dist;
	}
	friend bool operator < (node p,node q){
		return p.dist>q.dist;
	}
};
long long dist[maxn+5];
int vis[maxn+5];
priority_queue<node>q;
void dijkstra(int s){
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	q.push(node(s,0));
	while(!q.empty()){
		int x=q.top().id;
		q.pop();
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(dist[y]>dist[x]+E[i].len){
				dist[y]=dist[x]+E[i].len;
				q.push(node(y,dist[y]));
			}
		}
	}
}

namespace brute_force{
	void solve(){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(a[j].x>=b[i].l&&a[j].x<=b[i].r&&a[j].y>=b[i].d&&a[j].y<=b[i].u){
					add_edge(b[i].p,j,b[i].t);
//					printf("%d->%d %d\n",b[i].p,j,b[i].t);
				}
			}
		}
		dijkstra(1);
		for(int i=2;i<=n;i++){
			qprint(dist[i]);
			putchar('\n');
		}
	}
}

namespace ld_equl_ru{
	map< pair<int,int> , int > mark;
	void solve(){
		for(int i=1;i<=n;i++){
			mark[make_pair(a[i].x,a[i].y)]=a[i].id;
		}
		for(int i=1;i<=m;i++){
			if(mark.count(make_pair(b[i].l,b[i].d))){
				add_edge(b[i].p,mark[make_pair(b[i].l,b[i].d)],b[i].t);
//				printf("%d->%d %d\n",b[i].p,mark[make_pair(b[i].l,b[i].d)],b[i].t);
			}
		}
		dijkstra(1);
		for(int i=2;i<=n;i++){
			qprint(dist[i]);
			putchar('\n');
		}
	}
}

namespace h_1{
	struct node {
		int l;
	    int r;
	} tree[maxn+5];
	int p[maxn+5];
	int newn=n;
	void build(int l,int r,int pos) {
	    newn++;
	    tree[pos].l=l;
	    tree[pos].r=r;
	    if(l==r) {
	        add_edge(pos+n,l,0);
	        return;
	    }
	    add_edge(pos+n,pos*2+n,0);
	    add_edge(pos+n,pos*2+1+n,0);
	    int mid=(l+r)>>1;
	    build(l,mid,pos<<1);
	    build(mid+1,r,pos<<1|1);
	}
	void update(int L,int R,int st,int w,int pos) {
	    if(L<=tree[pos].l&&R>=tree[pos].r) {
	        add_edge(st,pos+n,w);
	        return;
	    }
	    int mid=(tree[pos].l+tree[pos].r)>>1;
	    if(L<=mid) update(L,R,st,w,pos<<1);
	    if(R>mid) update(L,R,st,w,pos<<1|1);
	}
	
	int hash_id[maxn+5];//‘≠¿¥±‡∫≈->≈≈–Ú∫Û±‡∫≈ 
	void solve(){
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++){
			hash_id[a[i].id]=i; 
			p[i]=a[i].x;
		}
		build(1,n,1);
		newn=n;
		for(int i=1;i<=m;i++){
			int s=hash_id[b[i].p];
			int lb=lower_bound(p+1,p+1+n,b[i].l)-p;
			int rb=upper_bound(p+1,p+1+n,b[i].r)-p-1;
			update(lb,rb,s,b[i].t,1);
		}
		dijkstra(hash_id[1]);
		for(int i=2;i<=n;i++){
			qprint(dist[hash_id[i]]);
			putchar('\n');
		}
	}
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	qread(n);
	qread(m);
	qread(w);
	qread(h);
	for(int i=1;i<=n;i++){
		qread(a[i].x);
		qread(a[i].y);
		a[i].id=i;
	}
	bool flag=true;
	for(int i=1;i<=m;i++){
		qread(b[i].p);
		qread(b[i].t);
		qread(b[i].l);
		qread(b[i].r);
		qread(b[i].d);
		qread(b[i].u);
		if(b[i].l!=b[i].r) flag=false;
		if(b[i].d!=b[i].u) flag=false;
	}
//	h_1::solve(); 
	if(n<=100&&m<=100){
		brute_force::solve();
	}
	else if(flag){
		ld_equl_ru::solve();
	}
	else if(h==1){
		h_1::solve();
	}else{
		brute_force::solve();
	}
	return 0;
}
/*
4 4 1 5
1 1
2 3
3 3
4 4
1 10 2 2 3 3
2 5 3 3 3 3
3 1 5 5 5 5
3 8 4 4 4 4

4 3 1 5
5 1
3 1
2 1
4 1
1 10 2 3 1 1
1 5 3 3 1 1
2 7 4 5 1 1

5 10 12
*/
