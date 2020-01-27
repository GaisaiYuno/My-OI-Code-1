#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
#define INF 0x3f3f3f3f
using namespace std;
int n,k;
int a[maxn+5];
int lb[maxn+5],rb[maxn+5];
int check(int x,int y){
	if(x==y){
		if(lb[x]==INF) return 1;
		else return 0;
	}
//	if(lb[x]>rb[y]) printf("(%d,%d)\n",x,y);
	if(lb[x]>rb[y]) return 1;
	else return 0;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;i++){
		scanf("%d",&a[i]);
	}
	memset(lb,0x3f,sizeof(lb));
	for(int i=1;i<=k;i++){
		if(lb[a[i]]==INF) lb[a[i]]=i;
		rb[a[i]]=i;
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=check(i,i);
	}
	for(int i=1;i<n;i++){
		ans+=check(i,i+1);
	}
	for(int i=1;i<n;i++){
		ans+=check(i+1,i);
	}
	printf("%d\n",ans);
}

