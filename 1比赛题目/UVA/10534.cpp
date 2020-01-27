#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10005
#define INF 1000000
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
inline int bin_search(int *a,int L,int R,int x){
	int l=L,r=R;
	while(l<r){
		int mid=(l+r)>>1;
		if(a[mid]<x) l=mid+1;
		else r=mid;
	}
	return l;
}
int n;
int a[maxn];
int LIS1[maxn],LIS2[maxn];
int g[maxn];
int main(){
	while(scanf("%d",&n)!=EOF){
		memset(LIS1,0,sizeof(LIS1));
		memset(LIS2,0,sizeof(LIS2));
		for(int i=1;i<=n;i++) a[i]=qread();
		
		for(int i=1;i<=n;i++) g[i]=INF;
		for(int i=1;i<=n;i++){
			int k=bin_search(g,1,n,a[i]);
			LIS1[i]=k;
			g[k]=a[i];
		}
		for(int i=1;i<=n;i++) g[i]=INF;
		for(int i=n;i>=1;i--){
			int k=bin_search(g,1,n,a[i]);
			LIS2[i]=k;
			g[k]=a[i];
		}
		int ans=0,tmp=INF;
		for(int i=1;i<=n;i++){
		     tmp=min(LIS1[i],LIS2[i]);
		     ans=max(tmp*2-1,ans);
		}
		printf("%d\n",ans);
	}
}
