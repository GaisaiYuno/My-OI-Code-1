#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int a,b;
int fa[maxn];
int used[maxn];
void init() {
	memset(used,0,sizeof(used));
	for(int i=1; i<maxn; i++) fa[i]=i;
}
int find(int x) {
	if(fa[x]!=x) {
		fa[x]=find(fa[x]);
		return fa[x];
	} else return x;
}
void union_set(int a,int b) {
	int fx=find(a);
	int fy=find(b);
	fa[fy]=fx;
}
int main() {
	while(scanf("%d %d",&a,&b)!=EOF) {
		bool is_ring=false;
		int maxab=0;
		init();
		if(a==-1&&b==-1) break;
		if(a==0&&b==0) {
			printf("Yes\n");
			continue;
		}
		int fx=find(a);
		int fy=find(b);
		maxab=max(maxab,max(a,b));
		used[a]=used[b]=1;
		if(fx==fy) {
			is_ring=true;
			continue;
		} //有环
		union_set(a,b);
		while(scanf("%d %d",&a,&b)!=EOF&&a&&b) {
			int fx=find(a);
			int fy=find(b);
			maxab=max(maxab,max(a,b));
			used[a]=used[b]=1;
			if(fx==fy) {
				is_ring=true;
				continue;
			} //有环
			union_set(a,b);
		}
		if(!is_ring) {
			int cnt=0;
			for(int i=1; i<=maxab; i++) {
				if(used[i]==1&&fa[i]==i) {
					cnt++;
				}
			}
			if(cnt==1) printf("Yes\n");
			else printf("No\n");
		} else {
			printf("No\n");
		}

	}

}
