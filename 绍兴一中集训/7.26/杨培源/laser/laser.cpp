#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 10
#define maxm 100000
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
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m,q;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}

struct point{
	ll x;
	ll y;
	point(){
		
	}
	point(ll _x,ll _y){
		x=_x;
		y=_y;
	}
	friend bool operator == (point p,point q){
		return p.x==q.x&&p.y==q.y;
	}
	friend bool operator < (point p,point q){
		if(p.x==q.x) return p.y<q.y;
		else return p.x<q.x;
	}
};
point a[maxn+5],b[maxm+5];
map<point,int>same;
map<long long,int>cnt[maxn+5];

int query(ll x,ll y){
	int ans=0;
	bool flag=false;
	if(same.count(point(x,y))) flag=true;
	if(flag) ans+=same[point(x,y)];//正好在(x,y)上的特判 
	for(int i=1;i<=n;i++){
		if(flag) cnt[i][a[i].x*y-a[i].y*x]-same[point(x,y)];
	}
	for(int i=1;i<=n;i++){
		if(cnt[i].count(a[i].x*y-a[i].y*x)) ans+=cnt[i][a[i].x*y-a[i].y*x];
	}
	for(int i=1;i<=n;i++){
		if(flag) cnt[i][a[i].x*y-a[i].y*x]+=same[point(x,y)];
	}
	return ans;
}
int main(){
//	freopen("laser.in","r",stdin);
//	freopen("laser.out","w",stdout);
	ll xx,yy;
	qread(n);
	for(int i=1;i<=n;i++){
		qread(a[i].x);
		qread(a[i].y);
		ll g=gcd(a[i].x,a[i].y);
		a[i].x/=g;
		a[i].y/=g; 
	}
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	qread(m);
	for(int i=1;i<=m;i++){
		qread(b[i].x);
		qread(b[i].y);
		same[b[i]]++;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			long long p=a[i].x*b[j].y-a[i].y*b[j].x;
			cnt[i][p]++;
		}
	}
	qread(q); 
	for(int i=1;i<=q;i++){
		qread(xx);
		qread(yy);
		qprint(query(xx,yy));
		putchar('\n');
	}
}
/*
3 
1 1 
1 2 
1 3 
3 
1 1
1 2 
1 3 
3 
0 0 
-1 0 
-2 0

4 
1 1 
1 2 
1 3 
4 4
3 
1 1
1 2 
1 3 
3 
0 0 
-1 0 
-2 0
*/ 
