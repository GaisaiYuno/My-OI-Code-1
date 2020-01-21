//http://119.29.55.79/problem/365
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 100000
#define maxm 100000 
using namespace std;
typedef long long ll;
int n,m,dn;
int a[maxn+5];
int reala[maxn+5];

int tmp[maxn+5];
int discrete(int *a,int n){
	int p=0;
	for(int i=1;i<=n;i++) tmp[i]=a[i];
	sort(tmp+1,tmp+1+n);
	p=unique(tmp+1,tmp+1+n)-tmp-1;
	for(int i=1;i<=n;i++){
		a[i]=lower_bound(tmp+1,tmp+1+p,a[i])-tmp;
	}
	return p;
}
int bsz;
int belong[maxn+5];
struct query{
	int l;
	int bel;
	int r;
	int id;
	friend bool operator < (query p,query q){
		if(p.bel==q.bel) return p.r<q.r;
		else return p.bel<q.bel;
	}
}q[maxm+5];

ll cnt[maxn+5];
ll ans[maxm+5]; 
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		reala[i]=a[i];
	}
	dn=discrete(a,n);
	
	bsz=sqrt(n);
	for(int i=1;i<=n;i++) belong[i]=(i-1)/bsz+1;
	for(int i=1;i<=m;i++){
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].id=i;
		q[i].bel=belong[q[i].l];
	}
	sort(q+1,q+1+m);
	int r=0;
	ll sum=0;
	for(int i=1;i<=m;i++){
		if(q[i].bel!=q[i-1].bel){
			sum=0;
			for(int i=1;i<=dn;i++) cnt[i]=0;
			r=q[i].bel*bsz;
		}
		while(r<q[i].r){
			r++;
			cnt[a[r]]++;
			sum=max(sum,reala[r]*cnt[a[r]]);
		}
		ll res=sum;
		for(int l=q[i].l;l<=min(q[i].r,q[i].bel*bsz);l++){
			cnt[a[l]]++;
			res=max(res,reala[l]*cnt[a[l]]);
		}
		ans[q[i].id]=res;
		for(int l=q[i].l;l<=min(q[i].r,q[i].bel*bsz);l++){
			cnt[a[l]]--;
		}
	}
	for(int i=1;i<=m;i++) printf("%lld\n",ans[i]);
}

