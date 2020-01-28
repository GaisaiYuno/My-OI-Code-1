#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
int n,q,type;
int a[maxn],p[maxn];
int main(){
	freopen("e.in","r",stdin);
	freopen("e.out","w",stdout);
	scanf("%d %d %d",&n,&q,&type);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int u,v,r,k;
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
	}
	if(q==0) return 0;
	int lastans=0;
	for(int i=1;i<=q;i++){
		scanf("%d %d",&r,&k);
		for(int i=1;i<=k;i++) scanf("%d",&p[i]);
		for(int i=1;i<=n;i++){
			p[i]=(p[i]-1+(long long )lastans*type)%n+1;
		}
		if(k==1){
			lastans=a[p[1]]-r;
			printf("%d\n",a[p[1]]-r);
		}else{
			lastans=a[p[1]]-r;
			printf("%d\n",a[p[1]]-r);
		}
	}
}
