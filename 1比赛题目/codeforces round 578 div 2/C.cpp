#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
ll n,m;
ll g;
ll blk1,blk2;
int q;
ll gcd(ll a,ll b){
	return b==0?a:gcd(b,a%b);
}
ll get_blk(ll x,ll y){
	if(x==1){
		if(y%blk1==0) return y/blk1;
		else return y/blk1+1;
	}else{
		if(y%blk2==0) return y/blk2;
		else return y/blk2+1;
	}
}
int main(){
	ll sx,sy,ex,ey;
	scanf("%I64d %I64d %d",&n,&m,&q);
	g=gcd(n,m);
	blk1=n/g;
	blk2=m/g;
	for(int i=1;i<=q;i++){
		scanf("%I64d %I64d %I64d %I64d",&sx,&sy,&ex,&ey);
		if(get_blk(sx,sy)==get_blk(ex,ey)) printf("YES\n");
		else printf("NO\n");
	}
}

