#include<iostream>
#include<cstdio>
#define maxx 100005
using namespace std;
int x[maxx];
int sum[maxx]; 
int n,w;
int query(int l,int r){
	return sum[r]-sum[l-1];
} 
int main(){
	int u,v;
	scanf("%d %d",&n,&w);
	int l=0;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&u,&v);
		x[u]+=v;
		l=max(l,u);
	}
	for(int i=1;i<=l;i++){
		sum[i]=sum[i-1]+x[i]; 
	}
	int ans=-1;
	for(int i=1;i+w-1<=l;i++){
		ans=max(ans,query(i,i+w-1));
	}
	printf("%d\n",ans);
}
