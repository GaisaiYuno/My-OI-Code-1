//洛谷 过河 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxl 30005
#define mod 25001
#define INF 2139062143
using namespace std;
int cnt=0; 
bool a[maxl];
int f[maxl];
int l,s,t,m;
inline int fastread() {
	int x=0,sign=1,c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int main() {
	int x,ans,pos;
	//freopen("river.in","r",stdin);
	//freopen("river.out","w",stdout);
	while(cin>>l){ 
	ans=0;
	cnt++;
	s=fastread();t=fastread();m=fastread();
	for(int i=1; i<=m; i++) {
		x=fastread();
		a[x%mod]=1;//过程压缩,否则会MLE或者TLE 
		if(s==t&&x%s==0) ans++;//s==t的特判
	}
	if(s==t) {
		cout<<ans;
		return 0;
	}
	f[0]=0;
	for(int i=1; i<=mod; i++) f[i]=INF;
	for(int i=1; i<=mod; i++) {
		int pos=i%mod;
		for(int j=s; j<=t; j++) {
			if(i>=j&&f[i]>f[i-j]+a[pos])f[i]=f[i-j]+a[pos];
		}
	}
	if(cnt!=1) cout<<endl;
	cout<<f[mod];
	} 
	return 0;
}
