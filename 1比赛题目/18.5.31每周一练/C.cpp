#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
#define INF 0x7fffffff
using namespace std;
struct tree{
	int x;
	int h;
}a[maxn];
int cmp(tree a,tree b){
	return a.x<b.x;
}
int dp[maxn][3];//dp[i][1] 树i向左 dp[i][2]向右 
int n;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d %d",&a[i].x,&a[i].h);
	sort(a+1,a+1+n,cmp);
	a[n+1].x=INF;
	for(int i=1;i<=n;i++){
		if(i==1){
			dp[i][1]=1;
			if(a[i].x+a[i].h<a[i+1].x) dp[i][2]=1;
		}else{
			//不砍 
			dp[i][1]=max(dp[i-1][1],dp[i-1][2]);
			dp[i][2]=max(dp[i-1][1],dp[i-1][2]);
			
			//向左倒
			if(a[i].x-a[i].h>a[i-1].x){
				dp[i][1]=max(dp[i][1],dp[i-1][1]+1);
				if(a[i].x-a[i].h>a[i-1].x+a[i-1].h)dp[i][1]=max(dp[i][1],dp[i-1][2]+1);
			}
			
			//向右倒 
			if(a[i].x+a[i].h<a[i+1].x){
				dp[i][2]=max(dp[i][2],dp[i-1][1]+1);
				dp[i][2]=max(dp[i][2],dp[i-1][2]+1);
			} 
		}
	} 
	printf("%d\n",max(dp[n][1],dp[n][2]));
}
