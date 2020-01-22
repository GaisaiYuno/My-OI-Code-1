#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 1000000
using namespace std;
typedef long long ll; 
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
inline void qread(ll &x){
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
inline void qprint(ll x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar(x%10+'0'); 
	}
}

int n,m;
int W,L;
struct rect{
	ll x1;
	ll y1;
	ll x2;
	ll y2;	
	rect(){
		
	}
	rect(ll _x1,ll _y1,ll _x2,ll _y2){
		x1=_x1;
		y1=_y1;
		x2=_x2;
		y2=_y2;
	}
}a[maxn+5];
ll get_area(rect p,rect q){
	if(p.x2<q.x1||q.x2<p.x1||p.y2<q.y1||q.y2<p.y1) return 0;
	else return 1ll*(min(p.x2,q.x2)-max(p.x1,q.x1))*(min(p.y2,q.y2)-max(p.y1,q.y1));
}
int main(){
//	freopen("1.in","r",stdin);
//	freopen("1.ans","w",stdout); 
	rect v;
	qread(n);
	qread(m);
	qread(W);
	qread(L);
	for(int i=1;i<=n;i++){
		qread(a[i].x1);
		qread(a[i].y1);
		qread(a[i].x2);
		qread(a[i].y2);
	}
	for(int i=1;i<=m;i++){
		qread(v.x1);
		qread(v.y1);
		qread(v.x2);
		qread(v.y2);
		ll ans=0;
		for(int j=1;j<=n;j++) ans+=get_area(a[j],v);
		qprint(ans);
		putchar('\n');
	}
}

