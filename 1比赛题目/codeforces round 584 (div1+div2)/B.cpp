#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 100
#define maxt 1000
using namespace std;
int n;
int s[maxn+5];
int a[maxn+5],b[maxn+5];
int vis[maxn+5][maxt+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%1d",&s[i]);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i],&b[i]);
	}
	for(int i=1;i<=n;i++){
		for(int j=0;j<=maxt;j++){
			if(j<b[i]) vis[i][j]=s[i];
			else{
				if((j-b[i])%a[i]==0) vis[i][j]=!vis[i][j-1];
				else vis[i][j]=vis[i][j-1];
			}
		}
	}
	int ans=0;
	for(int i=0;i<=maxt;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(vis[j][i]) cnt++;
		} 
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);
}

