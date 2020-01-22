#include<iostream>
#include<cstdio>
#include<cstring> 
#define INF 0x3f3f3f3f
#define maxn 7000
using namespace std;
int n,m;
int g[maxn+5][maxn+5];
int bin_count(int x){
	int ans=0;
	while(x){
		if(x&1) ans++;
		x>>=1;
	}
	return ans;
}

int tmp[maxn+5];
bool check(int x){
	int sz=0;
	for(int i=1;i<=n;i++){
		if(x&(1<<(i-1))) tmp[++sz]=i;
	}
	for(int i=1;i<=sz;i++){
		for(int j=i+1;j<=sz;j++){
			if(!g[tmp[i]][tmp[j]]) return 0;
		}
	}
	return 1;
}
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		g[u][v]=g[v][u]=1; 
	} 
	if(n>25){
		printf("-1\n");
		return 0;
	}
	int ans=INF;
	for(int i=0;i<(1<<n);i++){
		int p=bin_count(i),q=bin_count((1<<n)-1-i);
		if(p==0||q==0) continue;
		if(check(i)&&check((1<<n)-i)){
			ans=min(ans,p*(p-1)/2+q*(q-1)/2);
		}
	}
	if(ans==INF) ans=-1;
	printf("%d\n",ans);
}

