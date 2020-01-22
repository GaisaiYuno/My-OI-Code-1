//算出所有直线斜率
//斜率为k的直线和斜率不为k的所有直线一定会相交
//注意要用分数类以及frac判断相等时候，-1/2和1/-2是一个东西 
//map要用pair,直接传分数类会玄学TLE 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#define maxn 1005
#define maxm 1000005
#define INF 0x3f3f3f3f
using namespace std;
typedef long long ll;
int n;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b); 
}
ll lcm(ll a,ll b){
	return a*b/gcd(a,b);
}
struct frac{
	ll a;
	ll b;
	inline void reduce(){
		ll g=gcd(a,b);
		a/=g;
		b/=g;
	}
	frac(){
		
	}
	frac(ll up,ll down){
		if(down==0){
			a=INF;
			b=1;
		}else{ 
			a=up;
			b=down;
			reduce();
			if(a>0&&b<0){
				a=-a;
				b=-b;
			}
		}
	}
	frac(ll x){
		a=x;
		b=1;
	}
	
	inline void mksame(frac &x,frac &y){
		int g=lcm(x.b,y.b);
		x.a=x.a*g/x.b;
		y.a=y.a*g/y.b;
		x.b=g;
		y.b=g;
	}
	friend bool operator == (frac x,frac y){
		return x.a==y.a&&x.b==y.b;
	}
	friend bool operator < (frac x,frac y){
		if(x.b!=y.b) x.mksame(x,y);
		return x.a<y.a;
	}
	friend frac operator + (frac x,frac y){
		if(x.b!=y.b) x.mksame(x,y);
		return frac(x.a+y.a,x.b);
	}
	friend frac operator - (frac x,frac y){
		if(x.b!=y.b) x.mksame(x,y);
		return frac(x.a-y.a,x.b);
	}
	friend frac operator * (frac x,frac y){
		return frac(x.a*y.a,x.b*y.b);
	} 
	friend frac operator / (frac x,frac y){
		return frac(x.a*y.b,x.b*y.a);
	}
};

int m;
struct line{
	frac k;
	frac b;
	friend bool operator < (line x,line y){
		if(x.k==y.k) return x.b<y.b;
		else return x.k<y.k;
	}
	friend bool operator == (line x,line y){
		return x.k==y.k&&x.b==y.b;
	}
}a[maxm]; 
int x[maxn],y[maxn];
map<pair<ll,ll> ,int>s;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x[i],&y[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			m++;
			a[m].k=frac(y[i]-y[j],x[i]-x[j]);
			a[m].b=frac(y[i])-a[m].k*frac(x[i]);
			if(a[m].k==frac(INF,0)){
				a[m].b=x[i];
			}
		}
	}
	sort(a+1,a+1+m);
	m=unique(a+1,a+1+m)-a-1;
	for(int i=1;i<=m;i++){

//		if(a[i].k.a>0&&a[i].k.b<0){
//			a[i].k.a=-a[i].k.a;
//			a[i].k.b=-a[i].k.b;
//		}
//	
		s[make_pair(a[i].k.a,a[i].k.b)]++;
//		printf(" %d\n",s[a[i].k]);
	} 
	ll tot=0;
	for(auto x : s){
		tot+=(ll)x.second*(m-x.second);
	}
	tot/=2; 
	printf("%I64d\n",tot);
}
