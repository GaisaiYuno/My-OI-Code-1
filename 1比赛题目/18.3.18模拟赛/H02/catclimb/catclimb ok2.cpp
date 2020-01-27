#include<iostream>
#include<cstdio>
#define maxn 20
#define INF 2147483647
using namespace std;
int n,w;
int c[maxn],weight[maxn];
int ans=0;
int sum=0;
int dfs(int cat,int car){//猫编号，车厢数
	for(int i=1;i<=cat&&i<=car;i++){
	 	if(weight[i]+c[cat]<=w){//for车厢号，看奶牛能被放进哪个车厢
	 		weight[i]+=c[cat];
	 		if(cat==n) return 1;
			if(dfs(cat+1,car)) return 1;
			weight[i]-=c[cat];
		}
	}
	return 0;
}

int IDdfs(){
	for(int i=sum/w;i<=18;i++){
		if(dfs(1,i)) return i;
	}
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
	ans=IDdfs();
	printf("%d\n",ans); 
	return 0;
}
