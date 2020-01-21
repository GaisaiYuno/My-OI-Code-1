//https://www.luogu.org/problem/P4396 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define maxn 1000000
#define maxm 1000000 
#define maxlogn 20
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
		return bsz*(id-1)+1; 
	}
	inline int rb(int id){
		return bsz*id>=n?n:bsz*id;
	}
	int cnt[maxn+5];//数x的出现次数 
	int val1[maxn+5];//第i个整块的第一问答案 
	int val2[maxn+5];//第i个整块的第二问答案 
	void add(int val){
		if(cnt[val]==0) val2[belong[val]]++; 
		cnt[val]++;
		val1[belong[val]]++;
	}
	void del(int val){
		cnt[val]--;
		if(cnt[val]==0) val2[belong[val]]--;
		val1[belong[val]]--;
	}
	int query1(int l,int r){
		int ans=0;
		for(int i=l;i<=min(r,rb(belong[l]));i++) ans+=cnt[i];
		for(int i=belong[l]+1;i<belong[r];i++) ans+=val1[i];
		if(belong[l]!=belong[r]){
			for(int i=lb(belong[r]);i<=r;i++) ans+=cnt[i];
		}
		return ans;
	} 
	int query2(int l,int r){
		int ans=0;
		for(int i=l;i<=min(r,rb(belong[l]));i++) ans+=cnt[i]>0;
		for(int i=belong[l]+1;i<belong[r];i++) ans+=val2[i];
		if(belong[l]!=belong[r]){
			for(int i=lb(belong[r]);i<=r;i++) ans+=cnt[i]>0;
		}
		return ans;
	}
}B;




int ans1[maxm+5];
int ans2[maxm+5];
int main(){
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++){
		qread(a[i]);
	}
	for(int i=1;i<=m;i++){
		qread(q[i].l);
		qread(q[i].r);
		qread(q[i].a);
		qread(q[i].b);
		q[i].id=i;
	}
	bsz=sqrt(n);
	for(int i=1;i<=n;i++) belong[i]=(i-1)/bsz+1;
	sort(q+1,q+1+m);
	register int l=1,r=0;
	for(int i=1;i<=m;i++){
		while(l>q[i].l) B.add(a[--l]);
		while(r<q[i].r) B.add(a[++r]);
		while(l<q[i].l) B.del(a[l++]);
		while(r>q[i].r) B.del(a[r--]); 
		ans1[q[i].id]=B.query1(q[i].a,q[i].b);
		ans2[q[i].id]=B.query2(q[i].a,q[i].b);
	}
	for(int i=1;i<=m;i++){
		qprint(ans1[i]);
		putchar(' ');
		qprint(ans2[i]);
		putchar('\n');
	}
}
