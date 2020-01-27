//如果消除所有卡牌，则第i小的和第i-1小的数满足a[i]-cnt[a[i]]=a[i-1]
//如果不满足，就需要修改
//把差值转化成覆盖，那么a[i]显然是能覆盖[a[i]-cnt[a[i]]+1,a[i]]区间内的数
//然后差分一下，变成单点修改 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200000
using namespace std;
int n,m;
int a[maxn+5];
int cnt[maxn+5];
int tot[maxn+5];
int ans=0; 
void add(int v){
	cnt[v]++;
	if(v-cnt[v]+1>0){
		tot[v-cnt[v]+1]++;
		if(tot[v-cnt[v]+1]==1) ans++;
	}
}
void del(int v){
	if(v-cnt[v]+1>0){
		tot[v-cnt[v]+1]--;
		if(tot[v-cnt[v]+1]==0) ans--;
	}
	cnt[v]--;
}
int main(){
	int x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		add(a[i]);
	}
	for(int i=1;i<=m;i++){
		scanf("%d %d",&x,&y);
		del(a[x]);
		a[x]=y;
		add(a[x]);
		printf("%d\n",n-ans);
	}
}
