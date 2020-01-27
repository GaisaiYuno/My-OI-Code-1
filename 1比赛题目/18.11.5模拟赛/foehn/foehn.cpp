#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 200005
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}

void dprint(long long x){
	if(x==0) return;
	dprint(x/10);
	putchar('0'+x%10);
}

void qprint(long long x){
	if(x<0){
		putchar('-');
		dprint(-x);
	}
	if(x==0) putchar('0');
	if(x>0) dprint(x);
	putchar('\n');
}
int n,q;
long long s,t;
long long a[maxn];
long long ans;
struct fenwick_tree {
	long long c[maxn];
	inline int lowbit(int x){
		return x&(-x);
	}
	inline void add(int x,int v){
		while(x<=n){
			c[x]+=v;
			x+=lowbit(x);
		}
	}
	inline void update(int L,int R,int v){
		add(L,v);
		add(R+1,-v);
	}
	inline long long query(int x){
		int t=x;
		if(x==0) return 0;
		long long ans=0;
		while(x){
			ans+=c[x];
			x-=lowbit(x);
		}
		return a[t]+ans;
	}
};


fenwick_tree T;
int main() {
//	freopen("foehn.in","r",stdin);
//	freopen("foehn.out","w",stdout);
	long long l,r,x;
	n=qread();
	q=qread();
	s=qread();
	t=qread();
	for(int i=0; i<=n; i++) {
		a[i]=qread();
//		if(i>0)T.update(i,i,a[i]);
	}
	for(int i=1; i<=n; i++) {
		if(a[i]<=a[i-1]) ans+=t*(a[i-1]-a[i]);
		else ans-=s*(a[i]-a[i-1]);
	}
	long long hl1,hr1,hl2,hr2,pre,nex;
	long long ans1,ans2;
	for(int i=1; i<=q; i++) {
		l=qread();
		r=qread();
		x=qread();
		ans1=ans2=0;
		hl1=T.query(l);
		hr1=T.query(r);
		pre=T.query(l-1);
		nex=T.query(r+1);
		if(r==n) nex=hr1;
		if(pre<=hl1) ans1-=s*(hl1-pre);
		else ans1+=t*(pre-hl1);
		if(hr1<=nex) ans1-=s*(nex-hr1);
		else ans1+=t*(hr1-nex);
		
		T.update(l,r,x);
		hl2=hl1+x;
		hr2=hr1+x;
		if(r==n) nex=hr2;
		if(pre<=hl2) ans2-=s*(hl2-pre);
		else ans2+=t*(pre-hl2);
		if(hr2<=nex) ans2-=s*(nex-hr2);
		else ans2+=t*(hr2-nex);
//		printf("debug:%d %d %d %d %d %d %lld %lld\n",pre,hl1,hr1,hl2,hr2,nex,ans1,ans2);
		ans+=(ans2-ans1);
		qprint(ans);
	}
}
