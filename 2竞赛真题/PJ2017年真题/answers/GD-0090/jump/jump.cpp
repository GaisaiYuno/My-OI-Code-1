#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<queue>
using namespace std;
struct node{
	int id,x,s;
}a[500001];
int n,d,k,now,ans=0,sum=0;
bool dfs(int now,int sum){
	if(sum>=k)return true;
	for(int i=now+1;i<=n;i++){
		if(a[i].x-a[now].x>=d-ans&&a[i].x-a[now].x<=d+ans){
			if(dfs(i,sum+a[i].s))return true;
		}
	}
	return false;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	a[0].x=0;
	for(int i=1;i<=n;i++){
		a[i].id=i;
		scanf("%d%d",&a[i].x,&a[i].s);
		if(a[i].s>0)sum+=a[i].s;
	}
	if(sum<k){
		printf("-1");
		return 0;
	}
	for(;;){
		if(dfs(0,0)){
			printf("%d",ans);
			return 0;
		}
		ans++;
	}
	return 0;
}
