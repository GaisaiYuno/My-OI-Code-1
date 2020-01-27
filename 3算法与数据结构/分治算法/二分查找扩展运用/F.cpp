#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 60005
#define eps 1e-5
#define INF 0x7fffffff
using namespace std;
int a[maxn];
int pos[maxn],last[maxn];
struct node{
	int l;
	int r;
	double mark;
	double v;
	int len(){
		return r-l+1;
	}
}tree[maxn<<2];
void push_up(int pos){
	tree[pos].v=min(tree[pos<<1].v,tree[pos<<1|1].v);
}
void build(int l,int r,int pos){
	tree[pos].l=l;
	tree[pos].r=r;
	tree[pos].v=0;
	tree[pos].mark=0;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(l,mid,pos<<1);
	build(mid+1,r,pos<<1|1);
} 
void push_down(int pos){
	if(tree[pos].mark!=0){
		tree[pos<<1].v+=tree[pos].mark;
		tree[pos<<1|1].v+=tree[pos].mark;
		tree[pos<<1].mark+=tree[pos].mark;
		tree[pos<<1|1].mark+=tree[pos].mark;
		tree[pos].mark=0;
	}
}
void update(int L,int R,double v,int pos){
	int l=tree[pos].l,r=tree[pos].r;
	if(L<=l&&R>=r){
		tree[pos].v+=v;
		tree[pos].mark+=v;
		return;
	} 
	push_down(pos); 
	int mid=(l+r)>>1;
	if(L<=mid) update(L,R,v,pos<<1);
	if(R>mid) update(L,R,v,pos<<1|1);
	push_up(pos);
}
double query(int L,int R,int pos){
	int l=tree[pos].l,r=tree[pos].r;
	if(L<=l&&R>=r){
		return tree[pos].v;
    }
    push_down(pos);
    int mid=(l+r)>>1;
    double ans=INF;
	if(L<=mid) ans=min(ans,query(L,R,pos<<1));
	if(R>mid) ans=min(ans,query(L,R,pos<<1|1));
	return ans; 
}
int t,n;
int main(){
	scanf("%d",&t);
	while(t--){
		memset(last,0,sizeof(last));
		memset(pos,0,sizeof(pos));
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			last[i]=pos[a[i]];
			pos[a[i]]=i;
		}
		double l=0,r=1;
		double ans=INF;
		while(fabs(l-r)>eps){
			build(1,n,1);
			double mid=(l+r)/2;
			bool is_min=false;
			for(int i=1;i<=n;i++){
				update(i,i,mid*i,1);
				update(last[i]+1,i,1,1);
				double t=query(1,i,1);
				if(mid*(i+1)>=t){
					is_min=true;
					break;
				}
			}
			if(is_min){
				r=mid;
				ans=min(ans,mid);
			} 
			else l=mid;
		}
		printf("%lf\n",ans);
	}
} 
