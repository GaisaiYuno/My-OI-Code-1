#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxm 15
#define maxn 100005
using namespace std;
int m,n;
int a[maxm][maxn];
int hash_a[maxn];
int minv[maxn];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		hash_a[a[1][i]]=i;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			a[i][j]=hash_a[a[i][j]];
		}
	}
	memset(minv,0x7f,sizeof(minv));
	for(int i=1;i<=m;i++){
		int r=1;
		for(int j=1;j<=n;j++){
			if(r<j) r++;
			while(r<n&&a[i][r]+1==a[i][r+1]) r++;
			minv[a[i][j]]=min(minv[a[i][j]],a[i][r]);
		}
	}
	long long ans=0;
	int now=1;
	while(now<=n){
		long long tmp=minv[now]-now+1;
		ans+=(tmp+1)*tmp/2;
		now=minv[now]+1; 
	}
	cout<<ans;
}
