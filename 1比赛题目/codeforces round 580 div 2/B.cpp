#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000
using namespace std;
int n;
int a[maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	long long ans=0;
	int cnt0=0,cntm1=0,cnt1=0;
	for(int i=1;i<=n;i++){
		if(a[i]>0){
			ans+=(a[i]-1);
			a[i]=1;
			cnt1++;
		}else if(a[i]<0){
			ans+=(-1-a[i]);
			a[i]=-1;
			cntm1++;
		}else cnt0++;
	}
	if(cntm1%2==1){
		if(cnt0>=1) ans+=cnt0;
		else ans+=cnt0+2;
	}else ans+=cnt0;
	printf("%I64d\n",ans);
}

