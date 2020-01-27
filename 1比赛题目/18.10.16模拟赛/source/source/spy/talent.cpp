#include<iostream>
#include<cstdio>
using namespace std;
int n,wm,w[251],v[251];
long long dp[1001];
bool chekku(int mid){
	for(int i=1;i<=wm;i++)dp[i]=-0x3f3f3f3f;
	for(int i=1;i<=n;i++){
		long long val=v[i]-(long long)w[i]*mid;
		for(int j=wm;j>=0;j--){//cout<<i<<" "<<j<<endl;
			if(dp[j]==-0x3f3f3f3f)continue;
			int k=j+w[i];if(k>wm)k=wm;
			dp[k]=max(dp[k],dp[j]+val);
		}
	}
	return dp[wm]>=0;
}

int main(){
	freopen("talent.in","r",stdin);
	freopen("talent.out","w",stdout);
	scanf("%d%d",&n,&wm);
	for(int i=1;i<=n;i++)scanf("%d%d",&w[i],&v[i]),v[i]*=1000;
	int l=0,r=1000000000,mid;
	while(l<r){
		mid=(l+r+1)/2;//cout<<l<<" "<<r<<" "<<mid<<endl; 
		if(chekku(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
}
