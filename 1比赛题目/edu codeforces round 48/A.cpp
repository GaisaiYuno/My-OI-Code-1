#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200005
using namespace std;
int n,m;
int a[maxn];
long long ans[maxn];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int now=0;
	for(int i=1;i<=n;i++){
//		printf("%d %d\n",a[i],m-now);
		if(a[i]>=m-now){
			a[i]-=(m-now);
			ans[i]=a[i]/m+1;
			now=a[i]%m;
		}else{
			ans[i]=0;
			now+=a[i];
		}
	}
	for(int i=1;i<=n;i++){
		printf("%I64d ",ans[i]);
	}
}
