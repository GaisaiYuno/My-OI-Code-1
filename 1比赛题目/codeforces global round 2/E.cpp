#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 300005
using namespace std;
int n;
long long a[maxn];
long long ans=0;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	int cnt1=0;
	for(int i=1;i<=n;i++){
		if(a[i]>=cnt1*2){
			ans+=cnt1;
			a[i]-=cnt1*2;
			cnt1=0;
			ans+=a[i]/3;
			a[i]%=3;
			cnt1+=a[i]; 
		}else{
			ans+=a[i]/2;
			cnt1-=a[i]/2;
			a[i]%=2;
			cnt1+=a[i];
		}
	}
	printf("%I64d\n",ans);
}

