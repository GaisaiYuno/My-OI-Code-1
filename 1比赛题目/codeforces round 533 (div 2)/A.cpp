/*
[El Psy Congroo]
For Selina

Problem:
Source:Codeforces round 533 (div 2)
Description:
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1005
#define INF 0x7fffffff
using namespace std;
int n;
int a[maxn];
int solve(int t){
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=min(min(abs(t-a[i]),abs(t+1-a[i])),abs(t-1-a[i]));
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int ans=INF,now=0;
	int t;
	for(int i=1;i<=101;i++){
		now=solve(i);
		if(now<ans){
			t=i;
			ans=now;
		}
	}
	printf("%d %d\n",t,ans);
}

