//http://119.29.55.79/problem/366
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 100000
#define maxm 1000000
using namespace std;
inline void qread(int &x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}
int n,m;
int a[maxn+5];

int bsz;
int belong[maxn+5];
struct query{
	int l;
	int r;
	int a;
	int b;
	int id;
	friend bool operator < (query a,query b){
		return belong[a.l]<belong[b.l]||(belong[a.l]==belong[b.l]&&((belong[a.l]&1)?a.r<b.r:a.r>b.r));
	}
}q[maxm+5];

struct divide_block{
	inline int lb(int id){
		return (id-1)*bsz+1;
	} 
	inline int rb(int id){
		return id*bsz>=n?n:id*bsz;
	}
	int cnt[maxn+5];
	int res[maxn+5];
	void add(int val){
		cnt[val]++;
		if(cnt[val]==1) res[belong[val]]++;
	}
	void del(int val){
		cnt[val]--;
		if(cnt[val]==0) res[belong[val]]--;
	}
	int query(int l,int r){
		int ans=0;
		for(int i=l;i<=min(rb(belong[l]),r);i++) ans+=cnt[i]>0;
		for(int i=belong[l]+1;i<belong[r];i++) ans+=res[i];
		if(belong[l]!=belong[r]){
			for(int i=lb(belong[r]);i<=r;i++) ans+=cnt[i]>0;
		}
		return ans;
	}
}B;
int ans[maxm+5];
int main(){
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++) qread(a[i]);
	for(int i=1;i<=m;i++){
		qread(q[i].l);
		qread(q[i].r);
		qread(q[i].a);
		qread(q[i].b);
		q[i].id=i;
	}
	bsz=n/sqrt(m);
	for(int i=1;i<=n;i++) belong[i]=(i-1)/bsz+1;
	sort(q+1,q+1+m);
	int l=1,r=0;
	for(int i=1;i<=m;i++){
		while(l<q[i].l) B.del(a[l++]);
		while(l>q[i].l) B.add(a[--l]);
		while(r<q[i].r) B.add(a[++r]);
		while(r>q[i].r) B.del(a[r--]);
		ans[q[i].id]=B.query(q[i].a,q[i].b);
	}
	for(int i=1;i<=m;i++){
		qprint(ans[i]);
		putchar('\n');
	} 
}	

