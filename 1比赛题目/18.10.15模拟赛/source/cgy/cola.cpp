#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstdio>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
#define maxn 105
#define maxx 1005
int n,m;
int mp[maxn][maxn];
bool mp1[maxn][maxn];
long long dp[maxn][maxx];
bool vis[maxn];
int t;
long long ans=0;
int main(){
	freopen("cola.in","r",stdin);
	freopen("cola.out","w",stdout);
	scanf("%d%d",&n,&m);
	int x,y;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&x,&y);
		if(!mp1[y][x])
		mp[y][++mp[y][0]]=x;
		mp1[y][x]=true;
	}
	dp[0][1]=1;
	int cnt=0;
	bool mark=false;
	scanf("%d",&t);
//	cout<<"check"<<endl;
	for(int i=1;i<=t;i++){
		cnt=0;
		if(!mark)
		for(int j=1;j<=n;j++){
			vis[j]=false;
			if(dp[i-1][j]){
				vis[j]=true;
				cnt++;
			}
		}
//		cout<<i<<endl;
		if(cnt==n)mark=true;
		for(int j=1;j<=n;j++){
			dp[i][j]=dp[i-1][j];
		}
		for(int j=1;j<=n;j++){
			for(int k=1;k<=mp[j][0];k++){
//				cout<<j<<" "<<k<<endl;
				dp[i][j]=(dp[i][j]+dp[i-1][mp[j][k]])%2017;
			}
		}
		if(mark){
			for(int j=1;j<=n;j++){
				dp[i][j]++;
			}
		}
		else{
			for(int j=1;j<=n;j++){
				if(vis[j]){
//					cout<<"check"<<" "<<j<<endl;
					dp[i][j]++;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans=(ans+dp[t][i])%2017;
	}
	cout<<ans<<endl;
}
