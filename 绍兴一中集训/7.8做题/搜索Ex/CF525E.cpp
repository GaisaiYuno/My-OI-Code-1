#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#define maxn 25
#define maxk 25
using namespace std;
typedef long long ll;
int n,k;
ll S;
int a[maxn+5];
ll fact[maxn+5];
map<ll,int>lans[maxk+5],rans[maxk+5];//lans[i][j]表示用了i个贴纸，和为j的方案数
void dfs(map<ll,int> *ans,int deep,int lim,ll sum,ll cnt){
	if(sum>S||cnt>k) return;
	if(deep>lim){
		ans[cnt][sum]++;
		return;
	}
	if(a[deep]<20)dfs(ans,deep+1,lim,sum+fact[a[deep]],cnt+1);
	dfs(ans,deep+1,lim,sum+a[deep],cnt);
	dfs(ans,deep+1,lim,sum,cnt);
} 

int main(){
	scanf("%d %d %I64d",&n,&k,&S);
//	printf("%d\n",k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]); 
	fact[0]=1;
	for(int i=1;i<=20;i++) fact[i]=fact[i-1]*i;
	dfs(lans,1,n/2,0,0);
	dfs(rans,n/2+1,n,0,0);
	ll ans=0;
	for(int i=0;i<=k;i++){
		for(auto x : lans[i]){
			ll sum=x.first,cnt=x.second,tot=0;
			for(int j=0;j<=k-i;j++){
				tot+=rans[j][S-sum];
			}
			ans+=cnt*tot;
		}
	}
	printf("%I64d\n",ans);
} 
