#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxb 35
#define maxv 1005
using namespace std;
int n,m,mb;
int sum[maxv];
int t[maxb];
int dp[maxb][maxv];
vector<int>v[maxb];
vector<int>w[maxb];
inline int lowpos(int x){
	int ans=0;
	while(!(x&1)){
		x>>=1;
		ans++;
	}
	return ans;
}
void ini(){
	mb=0;
	memset(sum,0,sizeof(sum));
	memset(t,0,sizeof(t));
	memset(dp,0,sizeof(dp));
	for(int i=0;i<=32;i++){
		if(!v[i].size()) continue;
		v[i].clear();
		w[i].clear();
	}
}
int main(){
	int x,y;
	while(scanf("%d %d",&n,&m)!=EOF){
		ini();
		if(n==-1&&m==-1) break;
		for(int i=1;i<=n;i++){
			scanf("%d %d",&x,&y);
			int j=lowpos(x);
			mb=max(mb,j);
			sum[j]+=x;
			v[j].push_back(x);
			w[j].push_back(y);
		}
		for(int i=0;i<=mb;i++){
			for(int j=0;j<v[i].size();j++){
				for(int k=sum[i];k>=v[i][j];k--){
					dp[i][k]=max(dp[i][k],dp[i][k-v[i][j]]+w[i][j]);
				}
			}
		}
		while(m>>mb) mb++;
		mb--;
		for(int i=1;i<=mb;i++){
			t[i]+=(t[i-1]+1)/2;
			for(int j=t[i];j>=0;j--){
				for(int k=0;k<=j;k++){
					dp[i][j]=max(dp[i][j],dp[i][j-k]+dp[i-1][min(t[i-1],(k<<1)|((m>>i-1)&1))]);
				}
			} 
		}
		printf("%d\n",dp[mb][1]);
	}
	
} 
