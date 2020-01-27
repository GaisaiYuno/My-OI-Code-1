#include<iostream>
#include<cstdio> 
#include<cstring>
#include<map>
#define maxn 5000000
#define base 131
#define mod 1000000007
using namespace std;
int n,k;
char s[maxn+5];
long long pow[maxn+5];
long long sum[maxn+5];
map<long long,int>vis;
int to_int(char c){
	if(c=='A') return 0;
	else if(c=='C') return 1;
	else if(c=='G') return 2;
	else return 3;
}
int main(){
//	freopen("ueana.in","r",stdin);
	scanf("%s",s+1);
	scanf("%d",&k);
	n=strlen(s+1);
	pow[0]=1;
	for(int i=1;i<=n;i++){
		pow[i]=pow[i-1]*base%mod;
	}
	for(int i=1;i<=n;i++){
		sum[i]=(sum[i-1]*base%mod+to_int(s[i]))%mod;
	}
	for(int i=1;i+k-1<=n;i++){
		int l=i,r=i+k-1;
		long long hs=(sum[r]-sum[l-1]*pow[r-l+1]%mod+mod)%mod;
		vis[hs]++;
	}
	int ans=0;
	for(map<long long,int>::iterator it=vis.begin();it!=vis.end();it++){
		ans=max(ans,it->second);
	}
	printf("%d\n",ans);
}
