#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 300
#define maxv 100000
using namespace std;
int n,tot;
int a[maxn+5];
int dp[maxv+5];
int cmp(int x,int y){
	return x>y;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		tot+=a[i];
	}
	sort(a+1,a+1+n,cmp); 
	dp[0]=1;
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=tot/2+a[i];j-a[i]>=0;j--){//Òª±£Ö¤j-a[i]<=tot/2,j<=tot/2+a[i] 
			dp[j]|=dp[j-a[i]];
			if(dp[j]) ans=max(ans,j);
		}
	}
	printf("%d\n",ans);
}
