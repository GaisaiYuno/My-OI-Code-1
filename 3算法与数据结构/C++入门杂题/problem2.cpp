#include<bits/stdc++.h>
#define zhh 100005
#define ll long long
#define fu(a,b,c) for(ll a=b;a<=c;a++)
#define fd(a,b,c) for(int a=b;a>=c;a--)
#define inf 0x7fffffff
#define mod 998244353
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
inline void fp(ll x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>=10) fp(x/10);
	putchar(x%10+'0');
}
ll x,y;
bool pd(ll x){
	if(x%2==0) return 0;
	for(ll i=3;i*i<=x;i+=2){
		if(x%i==0) return 0;
	}
	return 1;
}
ll ans;
int main(){
//	freopen("te.txt","w",stdout);
	fu(i,2,6541367999){
		if(i*i>6541367999) break;
		fu(j,max((ll)2,(ll)6541367000/i),max(i,(ll)6541367999/i)){
			if(i>j) break;
			if(i*j>6541367999) break;
			if(pd(i)&&pd(j)&&i*j<=6541367999&&i*j>=6541367000){
				ans++;
				fp(i);putchar(' ');fp(j);putchar(' ');fp(ans);puts("");
				
			}
		}
	}
//	x=read(),y=read();
//	fp(x*y);
	return 0;
}
