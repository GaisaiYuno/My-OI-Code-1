#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define fd(a,b,c) for(int a=b;a>=c;a--)
#define ll long long
#define zhh 100005
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
ll n,b,s,d;
ll f[zhh],ans[zhh];
void fp(ll x){
	if(x>10) fp(x/10);
	putchar(x%10+'0');
}
int main(){
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	n=read(),b=read();
	fu(i,1,n) f[i]=read();
	fu(i,1,b){
		s=read(),d=read();
		ll l1=1;
		fu(j,2,n){
			if((j-l1)<=d&&f[j]<=s) l1=j;
		}
		if(l1==n) ans[i]=1;
		else ans[i]=0;
	}
	fu(i,1,b){
		fp(ans[i]);
		puts("");
	}
	return 0;
}
