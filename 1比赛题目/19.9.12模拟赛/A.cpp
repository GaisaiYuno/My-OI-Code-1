#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x3f3f3f3f
#define maxn 1000000
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

int len,n;
struct seg{
	int l;
	int r;
	int type;
	seg(){
		
	}
	seg(int _l,int _r,int _type){
		l=_l;
		r=_r;
		type=_type;
	}
	friend bool operator < (seg p,seg q){
		if(p.l==q.l) return p.r<q.r;
		return p.l<q.l;
	}
}a[maxn*2+5];
int sz;
int dp[maxn+5];

int head,tail;
int q[maxn+5];
int main(){
	int l,r;
	qread(len);
	qread(n);
	for(int i=1;i<=n;i++){
		qread(l);
		qread(r);
		if(l<r){
			a[++sz]=seg(l,r,2);
		}else{
			a[++sz]=seg(1,r,1);
			a[++sz]=seg(l,n,1);
		}
	}
	sort(a+1,a+1+sz);
	memset(dp,0x3f,sizeof(dp));
	for(int i=1;i<=sz;i++){
		if(a[i].l==1) dp[i]=a[i].type;
		for(int j=1;j<i;j++){
			if(a[j].r+1>=a[i].l) dp[i]=min(dp[j]+a[i].type,dp[i]);
		}
	}
	int ans=INF;
	for(int i=1;i<=sz;i++){
		if(a[i].r==n){
			ans=min(ans,dp[i]);
		}
	}
	printf("%d\n",ans/2);
}
