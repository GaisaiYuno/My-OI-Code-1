#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 2000000
using namespace std;
int t,n,m;
int p[maxn+5];

int fa[maxn+5];
int sz[maxn+5];
void ini(int n){
	for(int i=1;i<=n;i++){
		fa[i]=i;
		sz[i]=1;
	}
}
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx==fy) return;
	fa[fx]=fy;
	sz[fy]+=sz[fx];
}

int cnt;
int block[maxn+5];//贪心，对连通块按大小从大到小排序，选前m个连起来
int cmp(int x,int y){
	return x>y;
} 
int main(){
	freopen("tel20a.in","r",stdin);
	int u,v;
	scanf("%d %d",&t,&m); 
	for(int i=1;i<=t;i++){
		scanf("%d %d",&u,&v);
		n=max(n,max(u,v));
		p[u]=v;
		p[v]=u;
	}
	ini(n);
	int ans=m;
	for(int i=1;i<=n;i++){
		if(p[i]){
			for(int j=p[i]+1;j<=n;j++){
				if(p[j]!=0){
					merge(i,j);
					break;
				}
			}
		}
	}
	int start=0;
	for(int i=1;i<=n;i++){
		if(p[i]){
			start=i;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(p[i]&&fa[i]==i){
			if(i==find(start)) ans+=sz[i];
			else block[++cnt]=sz[i];
		}
	}
	sort(block+1,block+cnt+1,cmp);
	for(int i=1;i<=min(m,cnt);i++){
		ans+=block[i]+1;
	}
	ans+=((m-min(m,cnt))/2)*2;
	printf("%d\n",ans); 
}/*
4
3
12 14
7 8
20 22
15 18
*/
