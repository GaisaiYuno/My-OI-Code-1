#include<iostream>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
typedef long long ll; 
inline ll fast_pow(ll x,ll k,ll mod){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	} 
	return ans;
}
inline ll inv(ll x,ll mod){
	return fast_pow(x,mod-2,mod);
}

ll bsgs(ll a,ll b,ll c){
	map<ll,ll>mp;
	a%=c;
	b%=c;
	if(a==0&&b==0) return 1;
	else if(a==0) return -1;//注意a=0的特判，否则会求出根0 
	ll m=ceil(sqrt(c));
	//x=i*m-j,a^x=a^m^i/a^j=b
	//a^m^i=b*a^j,枚举两边 
	for(ll sum=b,i=0;i<=m;i++,sum=sum*a%c){//b*a^j
		mp[sum]=i;
	} 
	ll tmp=fast_pow(a,m,c);
	for(ll sum=tmp,i=1;i<=m;i++,sum=sum*tmp%c){//a^m^i
		if(mp.count(sum)) return (i*m-mp[sum]+c)%c;
	}
	return -1;
}
ll a,b,p;
int t,k;
int main(){
	scanf("%d %d",&t,&k);
	for(int i=1;i<=t;i++){
		scanf("%lld %lld %lld",&a,&b,&p);
		if(k==1){
			printf("%lld\n",fast_pow(a,b,p));
		}else if(k==2){
			if(a%p==0&&b%p!=0) printf("Orz, I cannot find x!\n");
			else printf("%lld\n",b*inv(a,p)%p);
		}else{
			ll x=bsgs(a,b,p);
			if(x==-1) printf("Orz, I cannot find x!\n");
			else printf("%lld\n",x);
		}
	}
}

