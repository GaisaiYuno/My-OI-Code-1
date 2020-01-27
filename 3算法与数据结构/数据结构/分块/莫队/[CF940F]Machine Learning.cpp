#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#include<cmath>
#define maxn 100000
#define maxm 100000
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

int n,m,dn; 
int a[maxn+5];
int tmp[maxn+maxm+5];

int bsz;
int belong[maxn+5];

int l,r,t;
int cntq=0;
struct que{
	int l;
	int r;
	int id;
	int t; 
	friend bool operator < (que p,que q){
		if(belong[p.l]==belong[q.l]){
			if(belong[p.r]==belong[q.r]) return p.t<q.t;
			else return p.r<q.r;
		}else return belong[p.l]<belong[q.l];
	} 
}q[maxm+5];
int cntu=0;
struct upd{
	int pos;
	int val;
}up[maxm+5];

int cnt[maxn+maxm+5];//离散化之后值域为n+m 
int sumcnt[maxn+maxm+5];//统计cnt出现的次数，用于求cnt的mex
void add(int val){
	sumcnt[cnt[val]]--;
	cnt[val]++;
	sumcnt[cnt[val]]++;
}
void del(int val){
	sumcnt[cnt[val]]--;
	cnt[val]--;
	sumcnt[cnt[val]]++;
}
void update(upd &p){
	if(l<=p.pos&&p.pos<=r){
		del(a[p.pos]);
		add(p.val);
	}
	swap(p.val,a[p.pos]);
}

int calc_mex(){
	int ans=1;
	while(sumcnt[ans]>0) ans++;
	return ans;
	//考虑cnt的mex为x，那么存在出现1次的数，出现2次的数...出现x-1次的数
	// 1+2+..+x-1=n
	//x是O(sqrt(n))级别的 
}
int ans[maxm+5];
int main(){
	int cmd;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++){
		qread(a[i]);
		tmp[++dn]=a[i];
	}
	for(int i=1;i<=m;i++){
		qread(cmd);
		if(cmd==1){
			cntq++;
			qread(q[cntq].l);
			qread(q[cntq].r);
			q[cntq].id=cntq;
			q[cntq].t=cntu;
		}else{
			cntu++;
			qread(up[cntu].pos);
			qread(up[cntu].val);
			tmp[++dn]=up[cntu].val;
		}
	}
	sort(tmp+1,tmp+1+dn);
	dn=unique(tmp+1,tmp+1+dn)-tmp-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(tmp+1,tmp+1+dn,a[i])-tmp;
	for(int i=1;i<=cntu;i++) up[i].val=lower_bound(tmp+1,tmp+1+dn,up[i].val)-tmp;
	
	bsz=pow(n,2.0/3.0);
	for(int i=1;i<=n;i++) belong[i]=i/bsz+1;
	sort(q+1,q+1+cntq);
	l=1,r=0,t=0;
	for(int i=1;i<=cntq;i++){
		while(l<q[i].l) del(a[l++]);
		while(l>q[i].l) add(a[--l]);
		while(r<q[i].r) add(a[++r]);
		while(r>q[i].r) del(a[r--]);
		while(t>q[i].t) update(up[t--]);
		while(t<q[i].t) update(up[++t]);
		ans[q[i].id]=calc_mex(); 
	}
	for(int i=1;i<=cntq;i++) printf("%d\n",ans[i]);
}

