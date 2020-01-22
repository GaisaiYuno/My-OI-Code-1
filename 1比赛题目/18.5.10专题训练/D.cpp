#include<iostream>
#include<cstdio>
#define maxn 2005
using namespace std;
int fa[maxn],d[maxn];
int find(int x){
	if(fa[x]!=x){
		int root=find(fa[x]);
		d[x]+=d[fa[x]];
		fa[x]=root;
		return fa[x];
	}
}
bool flag;
void union_set(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx==fy){
		if((d[x]%2)==(d[y]%2)) flag=true;
		return;
	} 
	fa[fx]=fy;
	d[fx]=d[x]+d[y]+1;
}
int t,n,k;
int main(){
	int cas=1,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		for(int i=1;i<=n;i++){
			fa[i]=i;
			d[i]=0;
		} 
		flag=false;
		for(int i=1;i<=k;i++){
			scanf("%d %d",&a,&b);
			if(flag) continue;
			union_set(a,b); 
		}
		printf("Scenario #%d:\n",cas++);
		if(flag)printf("Suspicious bugs found!\n");
        else printf("No suspicious bugs found!\n");
        printf("\n");
	}
} 
