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
