//http://119.29.55.79/problem/302
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000
using namespace std;
int t,n,m;
int fa[maxn+5];
long long d[maxn+5];
int find(int x) {
	if(fa[x]==x) return x;
	else {
		int root=find(fa[x]);
		d[x]+=d[fa[x]];
		fa[x]=root;
		return root;
	}
}

void merge(int x,int y,long long val) {
	long long dx=d[x],dy=d[y];
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy) {
		fa[fx]=fy;
		d[fx]=dy-dx+val;
		//x-[dx]->fx-[edge]->fy<-[dy]-y
		//dx+edge+(-dy)=val
		//edge=dy-dx+val
	}
}
void ini(int n) {
	memset(fa,0,sizeof(fa));
	memset(d,0,sizeof(d));
	for(int i=1; i<=n+1; i++) fa[i]=i;
}

bool check(int x,int y,long long val){
	int fx=find(x),fy=find(y);
	if(fx==fy&&d[x]-d[y]!=val) return false;
	else{
		merge(x,y,val);
		return true;
	}
}

int main() {
	int l,r;
	long long v;
	scanf("%d",&t);
	while(t--) {
		bool flag=true;
		scanf("%d %d",&n,&m);
		ini(n);
		for(int i=1; i<=m; i++) {
			scanf("%d %d %lld",&l,&r,&v);
			if(!check(l,r+1,v)){
				//实际上是[l-1,r]，为了避免坐标0,把坐标统一+1 
				flag=false;
				break;
			}
		}
		if(flag) printf("true\n");
		else printf("false\n");
	}

}
