#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define maxn 600005
using namespace std;
int n,m;
int a[maxn],b[maxn];
long long suma[maxn],sumb[maxn];
map<long long,int>visa,visb;
int main() {
	scanf("%d",&n);
	for(int i=1; i<=n; i++) scanf("%d",&a[i]);
	scanf("%d",&m);
	for(int i=1; i<=m; i++) scanf("%d",&b[i]);
	for(int i=1; i<=n; i++) {
		suma[i]=suma[i-1]+a[i];
	}
	for(int i=1; i<=m; i++) {
		sumb[i]=sumb[i-1]+b[i];
	}
	if(suma[n]!=sumb[m]) {
		printf("-1\n");
	} else {
		int i1=0,i2=0,sum1=0,sum2=0;
		int ans=n;
		for(i1;i1<=n;){
			if(sum1==sum2) {
				i1++,i2++;
				sum1=a[i1];
				sum2=b[i2];
			} else if(sum1<sum2) {
				i1++;
				sum1+=a[i1];
				ans--;
			} else {
				i2++;
				sum2+=b[i2];
			}
		}
		printf("%d\n",ans);
	}

}
/*
5
1 10 100 1000 10000
3
1 1110 10000
*/
