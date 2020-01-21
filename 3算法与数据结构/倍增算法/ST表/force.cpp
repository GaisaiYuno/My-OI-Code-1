#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int a[maxn];
int vis[maxn*2];
int n,q;
int main(){
	int l,r;
	while(scanf("%d",&n)!=EOF&&n!=0){
		scanf("%d",&q);
		for(int i=1;i<=n;i++){
			 scanf("%d",&a[i]);
			 a[i]+=100000; 
		} 
		while(q--){
			scanf("%d %d",&l,&r); 
			memset(vis,0,sizeof(vis));
			for(int i=l;i<=r;i++) vis[a[i]]++;
			
			int ans=0;
			for(int i=0;i<2*maxn;i++) ans=max(ans,vis[i]);
            printf("%d\n",ans);
		}
	} 
}
