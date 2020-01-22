#include<bits/stdc++.h>
#define zhh 100005
#define ll long long
#define inf 0x7ffffffffffffffff
#define fu(a,b,c) for(ll a=b;a<=c;a++)
#define fd(a,b,c) for(ll a=b;a>=c;a--)
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
ll n,le;
string x;
map<char,ll>ha;
int main(){
	n=read();
	cin>>x;
	le=x.length();
	fu(i,0,le-1){
		ha[x[i]]++;
	}
	for(char i='a';i<='z';i++){
		while(ha[i]>0){
			cout<<i;
			ha[i]--;
		}
	}
	return 0;
}


