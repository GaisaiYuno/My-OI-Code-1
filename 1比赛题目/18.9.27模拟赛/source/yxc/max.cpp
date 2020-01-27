#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 200005
using namespace std;
int A[maxn];
int main(){
	freopen("max.in","r",stdin);
	freopen("max.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(A[i]<A[j]) ans=max(ans,A[j]%A[i]);
		}
	}
	printf("%d\n",ans);
}
