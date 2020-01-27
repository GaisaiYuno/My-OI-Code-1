#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
typedef long long ll;
typedef double db;
int n,m;
int judge_cases() {
	if(n*m<5000000) return 1;
	else return 2;
}
namespace brute_force {
	ll x[maxn];
	ll y[maxn];
	void work() {
		int cmd,l,r;
		ll s,t;
		for(int i=1; i<=n; i++) {
			scanf("%lld",&x[i]);
		}
		for(int i=1; i<=n; i++) {
			scanf("%lld",&y[i]);
		}
		for(int i=1; i<=m; i++) {
			scanf("%d",&cmd);
			if(cmd==2) {
				scanf("%d %d %lld %lld",&l,&r,&s,&t);
				for(int i=l; i<=r; i++) {
					x[i]+=s;
					y[i]+=t;
				}
			} else if(cmd==3) {
				scanf("%d %d %lld %lld",&l,&r,&s,&t);
				for(int i=l; i<=r; i++) {
					x[i]=s+i;
					y[i]=t+i;
				}
			} else {
				scanf("%d %d",&l,&r);
				db up,down,ax,ay;
				db sumx=0,sumy=0;
				up=down=0;
				for(int i=l; i<=r; i++) {
					sumx+=x[i];
					sumy+=y[i];
				}
				ax=sumx/(r-l+1);
				ay=sumy/(r-l+1);
				for(int i=l; i<=r; i++) {
					up+=((db)x[i]-ax)*((db)y[i]-ay);
					down+=((db)x[i]-ax)*((db)x[i]-ax);
				}
				printf("%.10f\n",up/down);
			}
		}
	}
}

namespace seg_tree_without_op3 {
	struct segment_tree1 {
		struct node {
			int l;
			int r;
			ll v;//和 
			ll sqv;//平方和 
			ll mark;
			ll len(){
				return r-l+1;
			}
		}tree[maxn*4];
		void push_up(int pos){
			tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
			tree[pos].sqv=tree[pos<<1].sqv+tree[pos<<1|1].sqv;
		}
		void build(int l,int r,int pos,ll *a){
			tree[pos].l=l;
			tree[pos].r=r;
			tree[pos].mark=0;
			tree[pos].sqv=0;
			tree[pos].v=0; 
			if(l==r){
				tree[pos].v=a[l];
				tree[pos].sqv=a[l]*a[l];
				return;
			}
			int mid=(l+r)>>1;
			build(l,mid,pos<<1,a);
			build(mid+1,r,pos<<1|1,a);
			push_up(pos);
		} 
		void push_down(int pos){
			int son;
			ll mk=tree[pos].mark;
			for(int i=0;i<=1;i++){
				son=(pos<<1)+i;
				tree[son].mark+=mk;
				tree[son].sqv+=2*tree[son].v*mk+tree[son].len()*mk*mk;
				tree[son].v+=mk*tree[son].len();
			}
			tree[pos].mark=0;
		}
		
		void update(int L,int R,ll v,int pos){
			if(L<=tree[pos].l&&R>=tree[pos].r){
				tree[pos].sqv+=2*tree[pos].v*v+tree[pos].len()*v*v;
				tree[pos].v+=v*tree[pos].len();
				tree[pos].mark+=v;
				return;
			}
			push_down(pos);
			int mid=(tree[pos].l+tree[pos].r)>>1;
			if(L<=mid) update(L,R,v,pos<<1);
			if(R>mid)update(L,R,v,pos<<1|1);
			push_up(pos);
		}
		
		ll query_sum(int L,int R,int pos){
			if(L<=tree[pos].l&&R>=tree[pos].r){
				return tree[pos].v;
			}
			push_down(pos);
			long long ans=0;
			int mid=(tree[pos].l+tree[pos].r)>>1;
			if(L<=mid) ans+=query_sum(L,R,pos<<1);
			if(R>mid) ans+=query_sum(L,R,pos<<1|1);
			return ans;
		}
		
		ll query_sqsum(int L,int R,int pos){
			if(L<=tree[pos].l&&R>=tree[pos].r){
				return tree[pos].sqv;
			}
			push_down(pos);
			int mid=(tree[pos].l+tree[pos].r)>>1;
			long long ans=0;
			if(L<=mid) ans+=query_sqsum(L,R,pos<<1);
			if(R>mid) ans+=query_sqsum(L,R,pos<<1|1);
			return ans;
		} 
	};
	segment_tree1 X,Y;
	
	struct segment_tree2{
		struct node {
			int l;
			int r;
			ll v;//维护xiyi乘积之和 
			ll mks;
			ll mkt;
			ll len(){
				return r-l+1;
			}
		}tree[maxn*4];
		void push_up(int pos){
			tree[pos].v=tree[pos<<1].v+tree[pos<<1|1].v;
		}
		
		void build(int l,int r,int pos,ll *x,long long *y){
			tree[pos].l=l;
			tree[pos].r=r;
			tree[pos].mks=0;
			tree[pos].mkt=0;
			tree[pos].v=0; 
			if(l==r){
				tree[pos].v=x[l]*y[l];
				return;
			}
			int mid=(l+r)>>1;
			build(l,mid,pos<<1,x,y);
			build(mid+1,r,pos<<1|1,x,y);
			push_up(pos);
		} 
		
		void push_down(int pos){
			int son;
			ll ms=tree[pos].mks;
			ll mt=tree[pos].mkt;
			for(int i=0;i<=1;i++){
				son=(pos<<1)+i;
				tree[son].v+=X.tree[son].v*mt;
				tree[son].v+=Y.tree[son].v*ms;
				tree[son].v+=tree[son].len()*ms*mt;
				tree[son].mkt+=mt;
				tree[son].mks+=ms;
			}
			tree[pos].mks=0;
			tree[pos].mkt=0;
		}
		
		void update(int L,int R,ll s,ll t,int pos){
			if(L<=tree[pos].l&&R>=tree[pos].r){
				tree[pos].v+=X.tree[pos].v*t;
				tree[pos].v+=Y.tree[pos].v*s;
				tree[pos].v+=tree[pos].len()*s*t;
				tree[pos].mks+=s;
				tree[pos].mkt+=t;
				return;
			}
			X.push_down(pos);
			Y.push_down(pos);
			push_down(pos);
			int mid=(tree[pos].l+tree[pos].r)>>1;
			if(L<=mid) update(L,R,s,t,pos<<1);
			if(R>mid) update(L,R,s,t,pos<<1|1);
			push_up(pos);
		}
		
		ll query_sum(int L,int R,int pos){
			if(L<=tree[pos].l&&R>=tree[pos].r){
				return tree[pos].v;
			}
			X.push_down(pos);
			Y.push_down(pos);
			push_down(pos);
			long long ans=0;
			int mid=(tree[pos].l+tree[pos].r)>>1;
			if(L<=mid) ans+=query_sum(L,R,pos<<1);
			if(R>mid) ans+=query_sum(L,R,pos<<1|1);
			push_up(pos);
			return ans;
		}
		
	}XY;
	
	ll x[maxn];
	ll y[maxn];
	void work() {
		int cmd,l,r;
		ll s,t;
		for(int i=1; i<=n; i++) {
			scanf("%lld",&x[i]);
		}
		for(int i=1; i<=n; i++) {
			scanf("%lld",&y[i]);
		}
		XY.build(1,n,1,x,y);
		X.build(1,n,1,x);
		Y.build(1,n,1,y);
		for(int i=1; i<=m; i++) {
			scanf("%d",&cmd);
			if(cmd==2) {
				scanf("%d %d %lld %lld",&l,&r,&s,&t);
				XY.update(l,r,s,t,1);
				X.update(l,r,s,1);
				Y.update(l,r,t,1);
			} else if(cmd==3) {
				scanf("%d %d %lld %lld",&l,&r,&s,&t);
			} else {
				scanf("%d %d",&l,&r);
				db up,down,ax,ay;
				db sumx,sumy,sumxy,sumsqx;
				sumx=X.query_sum(l,r,1);
				sumy=Y.query_sum(l,r,1);
				sumxy=XY.query_sum(l,r,1);
				sumsqx=X.query_sqsum(l,r,1);
				printf("x=%lf y=%lf xy=%lf x^2=%lf\n",sumx,sumy,sumxy,sumsqx); 
				ax=sumx/(r-l+1);
				ay=sumy/(r-l+1);
				up=ax*ay*(r-l+1)+sumxy-ay*sumx-ax*sumy;
				down=sumsqx-2*ax*sumx+(r-l+1)*ax*ax;
				printf("%.10f\n",up/down); 
			}
			printf("debug:\n");
			for(int i=1;i<=n;i++){
				printf("%d ",X.query_sum(i,i,1));
			}
			printf("\n debug:\n");
			for(int i=1;i<=n;i++){
				printf("%d ",Y.query_sum(i,i,1));
			}
			printf("\n");
		}
	}
}

int main() {
	scanf("%d %d",&n,&m);
	int cmd=judge_cases();
//	seg_tree_without_op3::work();
	if(cmd==1) {
		brute_force::work();
	}else{
		seg_tree_without_op3::work();
	}
}
