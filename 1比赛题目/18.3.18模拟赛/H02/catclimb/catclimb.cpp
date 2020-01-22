#include<iostream>
#include<cstdio>
#define maxn 20
#define INF 2147483647
using namespace std;
int n,w;
int c[maxn],used[maxn];
int ans=0;
int sum=0;
void dfs(int cat,int car,int now_w/*当前车上重量*/,int tot_w){
	//printf("%d %d %d %d\n",cat,car,now_w,tot_w);
	if(cat==n){
		ans=min(ans,car);
		return;
	}
	if(now_w==w&&cat==n-1&&sum-tot_w<=w){
		ans=min(ans,car+1);
		return;
	}
	if(car>ans) return;
	for(int i=1;i<=n;i++){
		if(now_w+c[i]>w&&used[i]==0){
			used[i]=1; 
			dfs(cat+1,car+1,c[i],tot_w+c[i]);
			used[i]=0;
		}
		if(used[i]==0&&now_w+c[i]<=w){
			used[i]=1;
			dfs(cat+1,car,now_w+c[i],tot_w+c[i]);
			used[i]=0;
		}
	}
	//dfs(cat,car,now_w,tot_w); 
}
int main(){
	//freopen("catclimb.in","r",stdin);
	//freopen("catclimb.out","w",stdout);
	sum=0;
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++){
		 scanf("%d",&c[i]);
		 sum+=c[i]; 
	} 
	if(n>10){
		if(sum/w==0) printf("%d\n",sum/w);
		else printf("%d\n",sum/w+1);
		return 0;
	}
	ans=INF;
	dfs(0,1,0,0);
	printf("%d\n",ans); 
	return 0;
}
/*
5 1996
1
2
1994
12
29

11 10
5 5 6 5 5 5 5 5 5 5 5 5 5 5 5 5 5 5
*/
