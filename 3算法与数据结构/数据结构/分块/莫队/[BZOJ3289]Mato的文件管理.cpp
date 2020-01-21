//http://119.29.55.79/problem/357 
#include<iostream>
#include<cstdio>
#include<cstring> 
#include<cmath>
#include<algorithm>
#define maxn 50000
using namespace std;
int n,dn,m;
int a[maxn+5];
int tmp[maxn+5]; 
void discrete(){
	for(int i=1;i<=n;i++) tmp[i]=a[i];
	sort(tmp+1,tmp+1+n);
	dn=unique(tmp+1,tmp+1+n)-tmp-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(tmp+1,tmp+1+dn,a[i])-tmp;
}

int bsz;
int belong[maxn+5];
struct que{
	int l;
	int r;
	int id;
	friend bool operator < (que p,que q){
		if(belong[p.l]==belong[q.l]) return p.r<q.r;
		else return belong[p.l]<belong[q.l];
	}
}q[maxn+5];

struct fenwick_tree{
	inline int lowbit(int x){
		return x&-x;
	}
	long long c[maxn+5];
	void update(int x,int val){
		for(int i=x;i<=dn;i+=lowbit(i)) c[i]+=val; 
	}
	long long sum(int x){
		long long ans=0;
		for(int i=x;i>0;i-=lowbit(i)) ans+=c[i];
		return ans;
	}
	long long query(int l,int r){
		if(l>r) return 0;
		return sum(r)-sum(l-1);
	}
}T;
long long sum=0;
long long ans[maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	discrete();
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	bsz=sqrt(n);
	for(int i=1;i<=n;i++) belong[i]=i/bsz+1;
	sort(q+1,q+1+m);
	int l=1,r=0;
	for(int i=1;i<=m;i++){
		while(l<q[i].l){
			sum-=T.query(1,a[l]-1);
			T.update(a[l],-1);
			l++;
		}
		while(l>q[i].l){
			l--;
			sum+=T.query(1,a[l]-1);
			T.update(a[l],1);
		}
		while(r<q[i].r){
			r++;
			sum+=T.query(a[r]+1,dn);
			T.update(a[r],1);
		}
		while(r>q[i].r){
			sum-=T.query(a[r]+1,dn);
			T.update(a[r],-1);
			r--;
		}
		ans[q[i].id]=sum;
	}
	for(int i=1;i<=m;i++) printf("%lld\n",ans[i]); 
}

