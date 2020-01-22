#include<bits/stdc++.h>
#define zhh 300010
#define ll long long
#define fu(a,b,c) for(ll a=b;a<=c;a++)
#define fd(a,b,c) for(ll a=b;a>=c;a--)
#define inf 0x7fffffff
#define hs 1000000007
#define ls c<<1
#define rs c<<1|1
#define pii pair<ll,ll>
#define fi first
#define se second
using namespace std;
inline int read(){
	int x=0,f=1;
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
inline void fp(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) fp(x/10);
	putchar(x%10+'0');
}
ll n,k,b,q,top=1;
pii st[zhh];
long double xl(pii a,pii b){
	return 1.0*(b.se-a.se)/(a.fi-b.fi);
}
ll geta(pii a){
	return(a.fi-1)*k+a.se+b;
}
int main(){
	n=read(),q=read();
	st[top]=pii(1,0);
	while(q--){
		int op=read(),x=read(),y;
		if(op==1){
			top=1;
			st[top]=pii(1,0);
			k=b=0;
			n+=x;
		} 
		else if(op==2){
			pii u=pii(n+1,-geta(pii(n+1,0)));
			while(top>1&&xl(u,st[top])>=xl(st[top],st[top-1])) --top;
			st[++top]=u;
			n+=x;
		}
		else{
			y=read();
			b+=x;
			k+=y;
		}
		while(top>1&&geta(st[top])>=geta(st[top-1])) --top;
		printf("%lld %lld\n",st[top].fi,geta(st[top]));
	}
	return 0;
}
