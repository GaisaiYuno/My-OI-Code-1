#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10005
using namespace std;
inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
inline int lcm(int a,int b){
	return a/gcd(a,b)*b;
}
inline long long fast_pow(long long x,long long k,long long mod){
	long long ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans%mod;
}
inline long long inv(int x,int mod){
	return fast_pow(x,mod-2,mod);
}
struct frac{
	int a;
	int b;
	void div(){
		int g=gcd(a,b);
		a/=g;
		b/=g;
	}
	frac(){
		
	}
	frac(int x){
		a=x;
		b=1;
	}
	frac(int x,int y){
		a=x;
		b=y;
		div();
	}
	friend frac operator +(frac x,frac y){
		frac z;
		int l=lcm(x.b,y.b);
		z.b=l;
		z.a=l/x.b*x.a+l/y.b*y.a;
		z.div();
		return z;
	}
	friend frac operator -(frac x,frac y){
		frac z;
		int l=lcm(x.b,y.b);
		z.b=l;
		z.a=l/x.b*x.a-l/y.b*y.a;
		z.div();
		return z;
	}
	friend frac operator *(frac x,frac y){
		frac z=frac(x.a*y.a,x.b*y.b);
		z.div();
		return z;
	}
	friend frac operator /(frac x,frac y){
		frac z=frac(x.a*y.b,x.b*y.a);
		z.div();
		return z;
	}
	friend bool operator ==(frac x,frac y){
		return x.a==y.a&&x.b==y.b;
	}
	friend bool operator !=(frac x,frac y){
		return !(x==y);
	}
	void print(){
		printf("%d/%d\n",a,b);
	}
};
const int mod=998244353;
int numb,n,q,ta,tb,A,B;
frac p[maxn];
frac combo[maxn];
long long get_ans(int l,int r){
	memset(combo,0,sizeof(combo));
	frac basic_score=frac(0);
	for(int i=l;i<=r;i++){
		basic_score=basic_score+frac(p[i]);
	}
	basic_score=basic_score*frac(A);
	combo[l]=p[l];
	for(int i=l+1;i<=r;i++){
		if(i!=l&&p[i]==frac(1)){
//			printf("ok\n");
//			combo[i-1].print();
			combo[i]=combo[i-1]+frac(1);
		}else{
			combo[i]=combo[i-1]*frac(ta,tb);
		}
//		combo[i].print();
	}
	frac combo_score=frac(0);
	for(int i=l;i<=r;i++){
		combo_score=combo_score+p[i]*combo[i];
	}
	frac total_score=basic_score+combo_score;
//	total_score.print();
	return (long long)total_score.a*inv(total_score.b,mod);
}
int main(){
	freopen("omeed.in","r",stdin);
	freopen("omeed.out","w",stdout);
	int cmd,wa,wb,x,l,r;
	scanf("%d",&numb);
	scanf("%d %d %d %d %d %d",&n,&q,&ta,&tb,&A,&B);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&p[i].a,&p[i].b);
		p[i].div();
	}
	for(int i=1;i<=q;i++){
		scanf("%d",&cmd);
		if(cmd==1){
			scanf("%d %d %d",&x,&wa,&wb);
			p[x]=frac(wa,wb);
		}else{
			scanf("%d %d",&l,&r);
			printf("%lld\n",get_ans(l,r)%mod);
		}
	}
}
/*
2
5 5 2 3 1 1
1 1
0 2
2 2
4 4
0 5
2 1 5
2 1 5
1 2 9 9
2 2 3
2 1 5
*/
