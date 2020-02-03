#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 300000
using namespace std;
void rsort(int *ans,int *fi,int *se,int n,int m){
	static int buck[maxn+5];
	for(int i=0;i<=m;i++) buck[i]=0;
	for(int i=1;i<=n;i++) buck[fi[i]]++;
	for(int i=1;i<=m;i++) buck[i]+=buck[i-1];
	for(int i=n;i>=1;i--) ans[buck[fi[se[i]]]--]=se[i];
}

int t,n;
int a[maxn+5];
int pre[maxn+5],nex[maxn+5];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		pre[0]=1;
		for(int i=1;i<=n;i++){
			if(a[i]>=i-1) pre[i]=pre[i-1];
			else pre[i]=0;
		}
		bool flag=0;
		nex[n+1]=1;
		for(int i=n;i>=1;i--){
			if(a[i]>=n-i) nex[i]=nex[i+1];
			else nex[i]=0;
			if(pre[i]&&nex[i]){
				flag=1;
				break;
			}
		}
		if(flag) puts("Yes");
		else puts("No");
	}
}

