#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f3f
#define maxn 3500
using namespace std;
int t;
int n,m,k;
int a[maxn+5];

int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&m,&k);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		int ans=0;
		k=min(k,m-1);
		for(int i=0;i<=k;i++){
			int tmp=INF;
			for(int j=0;j<=m-1-k;j++){
				tmp=min(tmp,max(a[i+j+1],a[n-m+i+j+1]));
			}
			ans=max(ans,tmp);
		}
		printf("%d\n",ans);
	}
}

