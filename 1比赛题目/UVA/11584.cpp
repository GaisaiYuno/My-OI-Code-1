#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
#define INF 10000000
using namespace std;
char a[maxn];
int dp[maxn];
int judge(int L,int R){
	int l=L,r=R;
	while(l<r){
		if(a[l]==a[r]){
		    l++;
		    r--;
		}
		else return 0; 
	}
	return 1;
}
int t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",a);
		int len=strlen(a);
		int ans=INF;
		for(int i=0;i<len;i++){
			dp[i]=INF;
			if(judge(0,i)) dp[i]=1;
			else{
				for(int k=0;k<i;k++){
					if(judge(k+1,i)) dp[i]=min(dp[i],dp[k]+1);
				}
			}
		}
        printf("%d\n",dp[len-1]);
	}
} 
