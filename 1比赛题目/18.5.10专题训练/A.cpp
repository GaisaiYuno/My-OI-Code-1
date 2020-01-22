#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1005
#define maxm 1000*999/2
using namespace std;
int fa[maxn];
int father(int x) {
	if(fa[x]==x) return fa[x];
	else {
		fa[x]=father(fa[x]);
		return fa[x];
	}
}
int n,m;
int main() {
	int u,v,w;
	while(scanf("%d",&n)!=EOF) {
		if(n==0) break;
		scanf("%d",&m);
		for(int i=1;i<=n;i++) fa[i]=i;
		for(int i=1; i<=m; i++) {
			scanf("%d %d",&u,&v);
			int fu=father(u);
			int fv=father(v);
			if(fu!=fv){
				fa[fu]=fv;
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(father(i)==i) cnt++;
		}
		printf("%d\n",cnt-1);
	}
}
