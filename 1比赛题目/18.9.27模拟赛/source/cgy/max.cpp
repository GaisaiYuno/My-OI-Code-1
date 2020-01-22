#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
#define maxn 1000005
int num[maxn];
int a[maxn];
int n;
int pre[maxn];
int last=0;
int main(){
//	freopen("max3.in","r",stdin);
    freopen("max.in","r",stdin);
    freopen("max.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		num[a[i]]++;
	}
	n=0;
	for(int i=1;i<=maxn;i++){
		pre[i]=last;
		if(num[i]){
			a[++n]=i;
			last=i;
		}
//	    cout<<i<<" "<<pre[i]<<endl;
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		for(int j=2;a[i]*j<=a[n]+a[i];j++){
			if(pre[i*j]<=(j-1)*i)continue;
		//	cout<<i*j<<endl;
			mx=max(pre[i*j]-(j-1)*i,mx);
		}
	}
	printf("%d\n",mx);
}
