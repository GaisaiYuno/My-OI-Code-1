#include<iostream>
#include<cstring>
#include<cstdio>
#define maxn 100005
using namespace std;
int A[maxn];
int B[maxn];
int F[maxn];
int main(){
	freopen("sabotage.in","r",stdin);
	freopen("sabotage.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&A[i]);
	for(int i=1;i<=n;i++) B[i]=B[i-1]+A[i];
	double ans=1e10;
	for(int len=2;len<n;len++){
		for(int i=1;i+n-len+1<=n;i++){
			int j=i+n-len+1;
			ans=min(ans,(double)(B[i]+B[n]-B[j-1])/(len));
		}
	}
	printf("%.3f",ans);
}
