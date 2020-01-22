#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 1000000
#define INF 0x3f3f3f3f
using namespace std;
int t;
int n,m;
int a[maxn+5];
int b[maxn+5];
int main(){
	scanf("%d",&t);
	while(t--){
		long long ans=0;
		int cnt0=0; 
		int sz=0;
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		for(int i=1;i<=n;i++){
			if(a[i]==0) cnt0++;
			else b[++sz]=a[i];
		}
		if(cnt0>m){
			printf("Impossible\n");
		}else if(n==m){
			printf("Richman\n"); 
		}else{
			m-=cnt0;
			for(int i=1;i<=m;i++){
				ans+=b[i];
			}
			int minv=INF;
			for(int i=m+1;i<=sz;i++) minv=min(minv,b[i]); 
			ans+=minv;
			ans--;
			printf("%lld\n",ans);
		}
	}
}

