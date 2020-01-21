#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000 
#define INF 0x3f3f3f3f
#define sz 5000
using namespace std;
int n;
int a[maxn+5];
int b[maxn+5];
int posa[maxn+5],posb[maxn+5]; 
int ans[maxn*2+5];
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		posa[a[i]]=i;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&b[i]);
		posb[b[i]]=i;
	}
	memset(ans,0x3f,sizeof(ans));
	for(int i=0;i<=min(sz,n*2-2);i++){
		for(int j=0;j<=i;j++){
			if(i-j>=n||j>=n) continue;
			ans[posa[j]+posb[i-j]]=min(ans[posa[j]+posb[i-j]],j+i-j);
		}
	}
	for(int i=0;i<=n*2-2;i++){
		if(ans[i]==INF){
			for(int j=0;j<=i;j++){
				if(i-j>=n||j>=n) continue;
				ans[i]=min(ans[i],a[i-j]+b[j]);
			}
		}
	}
	for(int i=0;i<=n*2-2;i++) printf("%d ",ans[i]);
}

