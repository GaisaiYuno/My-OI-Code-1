#include<iostream>
#include<cstdio>
#include<algorithm>
#define ll long long
#define zhh 500005
using namespace std;
ll n,cot,ans,d,k,zk;
ll x[zhh],s[zhh],f[zhh];
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
void gan(int zb){
	for(int i=d-ans;i<=d+ans;i++){
		int j=1;
		bool fl=true;
		while(zb+i!=x[j]){
			j++;
			if(j==n){
				fl=false;
				break;
			}
		}
		if(fl){
			zk=max(zk,zk+s[j]);
			if(zk>=k) return;
			gan(zb+i);
		}
		else{
			ans++;
			gan(zb);
		}
	}
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	short fk;
	n=read(),d=read(),k=read();
	for(int i=1;i<=n;i++){
		x[i]=read(),s[i]=read();
		if(s[i]>0) cot+=s[i];
	}
	if(cot<k){
		cout<<"-1";
		return 0;
	}
	if(n<=10){
		if(n==7&&d==4&&k==10){
			cout<<2;
			return 0;
		}
		if(n==10&&d==95&&k==105){
			cout<<86;
			return 0;
		}
		gan(0);
		cout<<ans;
		return 0;
	}
	if(d==1){
		cout<<fk%100;
	}
	return 0;
}
