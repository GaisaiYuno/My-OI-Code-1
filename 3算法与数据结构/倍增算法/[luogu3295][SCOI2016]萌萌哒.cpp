//http://119.29.55.79/contest/98/problem/6
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define maxn 100000
#define maxlogn 21
#define mod 1000000007
using namespace std;
typedef long long ll;
inline ll fast_pow(ll x,ll k){
	ll ans=1;
	while(k){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}

struct disjoint_set{
	int fa[maxlogn+5][maxn+5];//f[i][j]表示[j,j+2^i-1]的代表元
	void ini(int n){
		int k=log2(n)+1;
		for(int j=0;j<=k;j++){
			for(int i=1;i<=n;i++){
				fa[j][i]=i;
			}	
		}
	} 
	int find(int b,int x){
		if(fa[b][x]==x) return x;
		else return fa[b][x]=find(b,fa[b][x]);
	}
	void merge(int b,int x,int y){
		int fx=find(b,x);
		int fy=find(b,y);
		if(fx!=fy) fa[b][fx]=fy;
	}
}S;

int log2n;
int n,m;
int main(){
	int l1,l2,r1,r2;
	scanf("%d %d",&n,&m);
	log2n=log2(n)+1;
	S.ini(n);
	for(int i=1;i<=m;i++){
		scanf("%d %d %d %d",&l1,&r1,&l2,&r2);
		int len=r1-l1+1;
		for(int j=log2n;j>=0;j--){//二进制拆分 
			if(len&(1<<j)){
				S.merge(j,l1,l2);
				l1+=(1<<j);
				l2+=(1<<j);
			} 
		}
	}
	for(int j=log2n;j>=1;j--){
		for(int i=1;i+(1<<j)-1<=n;i++){//下推关系，长度为2^j的推到2^(j-1) 
			int f=S.find(j,i);
			S.merge(j-1,i,f);
			S.merge(j-1,i+(1<<(j-1)),f+(1<<(j-1))); 
		}
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(S.find(0,i)==i) cnt++;
	}
	printf("%lld\n",9*fast_pow(10,cnt-1)%mod);
}

