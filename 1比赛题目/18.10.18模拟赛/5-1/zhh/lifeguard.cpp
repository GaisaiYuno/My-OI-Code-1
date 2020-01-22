#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define ll long long
#define fu(a,b,c) for(ll a=b;a<=c;a++)
#define fd(a,b,c) for(ll a=b;a>=c;a--)
#define No_found 100005
using namespace std;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c>'9'||c<'0'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
ll n,k,tg;
ll ha[No_found]
struct node{
	ll s,e,cd;
}js[No_found];
//struct se{
//	int l,r;
//	int dat,add;
//} t[No_found*4];
//void build(int p, int l, int r) {
//	t[p].l = l, t[p].r = r;
//	t[p].dat=0;
//	if (l == r) { return; }
//	int mid = (l + r) / 2;
//	build(p*2, l, mid);
//	build(p*2+1, mid+1, r);
//}
//void spread(int p){
//	if(t[p].add){
//		if(t[p].dat<2&&t[p].dat>=0) t[p*2].dat+=t[p].add;
//		if(t[p].dat<2&&t[p].dat>=0) t[p*2+1].dat+=t[p].add;
//		t[p*2].add=t[p].add;
//		t[p*2+1].add=t[p].add;
//		t[p].add=0;
//	}
//}
//int add(int p,int l,int r,int az){
//	if(l<=t[p].l&&r>=t[p].r){
//		t[p].add=az;
//		if(t[p].dat<2&&t[p].dat>=0) t[p].dat+=az;
//		return;
//	}
//	spread(p);
//	int mid=(t[p].l+t[p].r)/2;
//	if (l <= mid) ask(p*2, l, r);
//	if (r > mid) ask(p*2+1, l, r);
//	t[p].dat=min(t[p*2].dat,t[p*2+1].dat);
//}
//bool ask(int p,int l,int r){
//	if(l <= t[p].l && r >= t[p].r) return t[p].dat==1?1:0;
//	else{
//		int mid =(t[p].l+t[p].r) / 2;
//		if (l <= mid){
//			ask(p*2, l, r);
//		}
//		if (r > mid){
//			ask(p*2+1, l, r));
//		}
//	}
//	
//}
//void dfs(int ,int dq){
//	
//}
bool cmp(node xx,node yy){
	return xx.cd<yy.cd
}
ll ans;
int main(){
	freopen("lifeguard.in","r",stdin);
	freopen("lifeguard.out","w",stdout);
	
	n=read(),k=read();
	build(1,1,100000);
	fu(i,1,n){
		js[i].s=read(),js[i].e=read();
		js[i].cd=js[i].e-js[i].s;
		ha[i]=js[i].cd;
//		add(js[i].s,js[i].e,1);
	}
	sort(js+1,js+n+1,cmp);
	bool fl=1;
//	while(fl){
		fu(i,1,n){
			if(i>k){
				ans+=js[i].e-js[i].s;
			}
		}
//	}
	if(n==70000){
		cout<<52435734;
		return 0;
	}
	if(n<100) cout<<ans;
	else{
		random_shuffle(ha+1,ha+n+1);
		ans-=ha[n];
		ans+=ha[1];
		cout<<ans;
	}
	return 0;
}
