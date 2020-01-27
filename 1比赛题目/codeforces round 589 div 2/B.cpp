#include<iostream>
#include<cstdio>
#include<cstring> 
#define mod 1000000007
#define maxn 1000
using namespace std;
typedef long long ll;
int h,w;
int r[maxn+5];
int c[maxn+5];
int mb[maxn+5][maxn+5]; //must be black
int mw[maxn+5][maxn+5];
inline ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}

int main(){
	scanf("%d %d",&h,&w);
	for(int i=1;i<=h;i++){
		scanf("%d",&r[i]);
		for(int j=1;j<=r[i];j++) mb[i][j]=1;
		mw[i][r[i]+1]=1;
	} 
	for(int i=1;i<=w;i++){
		scanf("%d",&c[i]);
		for(int j=1;j<=c[i];j++) mb[j][i]=1;
		mw[c[i]+1][i]=1;
	}
	int cnt=0;
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			if(mb[i][j]&&mw[i][j]){
				printf("0\n");
				return 0;
			}else if(!mb[i][j]&&!mw[i][j]) cnt++;
		}
	}
	printf("%I64d\n",fast_pow(2,cnt));
}

