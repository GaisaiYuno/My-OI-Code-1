#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn=500000+5;
int n,d,k;
struct Node{
	int s;
	int x;
}g[maxn];
int sum=0;
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=0;i<n;i++){
		scanf("%d%d",&g[i].s,&g[i].x); 
		if(g[i].x>0) sum+=g[i].x;
	} 
	if(sum<k){ printf("-1\n"); return 0; }
	if(d==1){
		int i=0;
		int ans=-1;
		int bef=0;
		while(k>0&&i<n){
			if(g[i].x>0){
				k-=g[i].x; ans=max(ans,g[i].s-bef);
			}
			i++;
		}
		if(k>0) printf("-1\n");
		else printf("%d\n",ans);
	}
	else{
		int minn=2e7;
		int i=0;
		int ans=-1;
		int bef=0;
		while(k>0&&i<=n){
			if(g[i].x>0){
				k-=g[i].x; minn=min(minn,g[i].s-bef); ans=max(ans,g[i].s-bef);
			}
			i++;
		}
		if(k>0) printf("-1\n");
		else printf("%d\n",max(ans-d,d-minn));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
