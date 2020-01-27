#include<iostream>
#include<cstdio>
#define maxn 100000
using namespace std;
typedef long long ll;
ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll g=exgcd(b,a%b,x,y);
	ll tmp=y;
	y=x-a/b*y;
	x=tmp;
	return g;
}
ll mul_mod(ll x,ll k,ll mod){
	ll ans=0;
	while(k){
		if(k&1) ans=(ans+x)%mod;
		k>>=1;
		x=(x+x)%mod; 
	}
	return ans;
}

int n;
ll a[maxn+5],b[maxn+5];
ll excrt(){
	ll M=a[1],x=b[1];
	//MΪlcm(a[i]) 
	//����ǰi-1�����̣����ǵõ�ͨ��x+M*t (tΪ����) 
	//��ô���Ƕ��ڵ�i�����̣�Ҫ���һ��tʹ��x+M*t=b[i] (mod a[i])
	for(int i=2;i<=n;i++){
		ll aa=M,bb=a[i],c=((b[i]-x)%a[i]+a[i])%a[i],t,u; //Mt=b[i]-x (mod a[i])
		        //ת��ΪM*t+a[i]*u=b[i]-x
				//��ŷ��� 
		ll g=exgcd(aa,bb,t,u); 
		//ax+by=c,ͨ��Ϊx=x0+b*t,y=y0-a*t
		//����С�������ʱ��t=b/gcd(a,b),x=(x0%t+t)%t 
		t=mul_mod(t,c/g,bb/g);
		x+=t*M;
		M*=bb/g;
		x=(x%M+M)%M;
	} 
	return x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&a[i],&b[i]); 
	}
	printf("%lld\n",excrt());
}

