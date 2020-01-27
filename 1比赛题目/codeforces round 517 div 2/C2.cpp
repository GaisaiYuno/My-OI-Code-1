#include<bits/stdc++.h>
#define zhh 2000005
#define ll long long
#define inf 0x7fffffff
#define re register int
#define fu(a,b,c) for(int a=b;a<=c;a++)
#define fd(a,b,c) for(int a=b;a>=c;a--)
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
ll gcd(ll x,ll y){
	if(x>y) swap(x,y);
	if(x==0) return y;
	return gcd(y%x,x);
}
ll a,b,k,p;
ll an1[zhh],an2[zhh];
bool vs[zhh];
long long s;
int main(){
	a=read(),b=read();
	s=a+b;
//	s*=2;
	while((p*(p+1)>>1)<=s){
		p++;
	}
	p--;
	ll h1=0,h2=0;
	ll he=0;
	fd(i,p,1){
		if(he+i<=a){
			vs[i]=1;
			an1[++h1]=i;
			he+=i;
		}
		else break;
	}
	if(a-he){
		an1[++h1]=a-he;
		vs[a-he]=1;
	}
	he=0;
	fu(i,1,p){
		if(he+i<=b){
			if(vs[i]) continue;
			vs[i]=1;
			an2[++h2]=i;
			he+=i;
		}
		else break;
	}
	cout<<h1<<endl;
	fu(i,1,h1){
		cout<<an1[i]<<" ";
	}
	puts("");
	cout<<h2<<endl;
	fu(i,1,h2){
		cout<<an2[i]<<" ";
	}
	return 0;
}


