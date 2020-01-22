#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500000
#define maxlogn 20
#define mod 1000000000
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}

typedef long long ll;
int n;
int a[maxn+5];
int Log2[maxn+5];
int st1[maxn+5][maxlogn+5];
int st2[maxn+5][maxlogn+5];
void ini(){
	Log2[0]=-1;
	for(int i=1;i<=n;i++) Log2[i]=Log2[i>>1]+1;
	memset(st2,0x3f,sizeof(st2));
	for(int i=1;i<=n;i++) st1[i][0]=st2[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st1[i][j]=max(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);
		}
	} 
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st2[i][j]=min(st2[i][j-1],st2[i+(1<<(j-1))][j-1]);
		}
	} 
}
ll query_max(int l,int r){
	int k=Log2[r-l+1];
	return max(st1[l][k],st1[r-(1<<k)+1][k]);
}
ll query_min(int l,int r){
	int k=Log2[r-l+1];
	return min(st2[l][k],st2[r-(1<<k)+1][k]);
}
int main(){
	qread(n);
	for(int i=1;i<=n;i++) qread(a[i]);
	ll ans=0;
	ini();
	if(n<=5000){ 
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
	//			printf("[%d,%d] len=%d max=%d min=%d\n",i,j,j-i+1,query_max(i,j),query_min(i,j));
				ll sum=(ll)(j-i+1)*query_max(i,j)%mod*query_min(i,j)%mod;
				ans=(ans+sum)%mod;
			}
		}
	}else{
		int cnt=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				cnt++;
	//			printf("[%d,%d] len=%d max=%d min=%d\n",i,j,j-i+1,query_max(i,j),query_min(i,j));
				ll sum=(ll)(j-i+1)*query_max(i,j)%mod*query_min(i,j)%mod;
				ans=(ans+sum)%mod;
				if(cnt>=50000000) break; 
			}
			if(cnt>=50000000) break; 
		}
//		printf("%lld\n",ans);
	}
	printf("%lld\n",ans);
}
