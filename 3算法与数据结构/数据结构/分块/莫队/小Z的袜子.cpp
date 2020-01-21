/*
Problem:小Z的袜子 
Source:https://www.luogu.org/problemnew/show/P1494
Algorithm:分块 
Description:
莫队模板 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#include<algorithm>
#define maxn 50005
using namespace std;
long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}
long long a[maxn];
long long cnt[maxn];
long long lans[maxn],rans[maxn];
int pos[maxn];
struct query{
	int l;
	int r;
	int id;
	long long len(){
		return r-l+1;
	}
	friend bool operator < (query a,query b){
		if(pos[a.l]==pos[b.l]) return a.r<b.r;
		else return pos[a.l]<pos[b.l]; 
	}
}q[maxn];
int n,m;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&q[i].l,&q[i].r);
		q[i].id=i;
	}
	int sz=int(sqrt(n));
	for(int i=1;i<=n;i++){
		pos[i]=i/sz;
	}
	sort(q+1,q+1+m);
	int l=1,r=1;
	long long ans=0;
	cnt[a[1]]++;
	for(int i=1;i<=m;i++){
		if(q[i].l==q[i].r){
			lans[q[i].id]=0;
			rans[q[i].id]=1;
			continue;
		}
		if(r<q[i].r){
			for(int j=r+1;j<=q[i].r;j++){
				ans-=cnt[a[j]]*(cnt[a[j]]-1);
				cnt[a[j]]++;
				ans+=cnt[a[j]]*(cnt[a[j]]-1); 
			}
		}else if(r>q[i].r){
			for(int j=r;j>=q[i].r+1;j--){
				ans-=cnt[a[j]]*(cnt[a[j]]-1);
				cnt[a[j]]--;
				ans+=cnt[a[j]]*(cnt[a[j]]-1); 
			}
		}
		if(l<q[i].l){
			for(int j=l;j<=q[i].l-1;j++){
				ans-=cnt[a[j]]*(cnt[a[j]]-1);
				cnt[a[j]]--;
				ans+=cnt[a[j]]*(cnt[a[j]]-1); 
			}
		}else if(l>q[i].l){
			for(int j=l-1;j>=q[i].l;j--){
				ans-=cnt[a[j]]*(cnt[a[j]]-1);
				cnt[a[j]]++;
				ans+=cnt[a[j]]*(cnt[a[j]]-1); 
			}
		}
		l=q[i].l;
		r=q[i].r;
		long long tot=q[i].len()*(q[i].len()-1);
		long long g=gcd(ans,tot);
		lans[q[i].id]=ans/g;
		rans[q[i].id]=tot/g;
	}
	for(int i=1;i<=m;i++){
		printf("%lld/%lld\n",lans[i],rans[i]);
	}
}
