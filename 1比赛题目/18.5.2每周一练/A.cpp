#include<iostream>
#include<cstdio>
#define maxn 505
using namespace std;
int n,k;
int a[maxn];
int is_ok(int x,int y){
	if(a[x]+a[y]>=k) return 1;
	else return 0;
}
int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int t=0,ans=0;
	for(int i=2;i<=n;i++){
		if(!is_ok(i-1,i)){
			ans+=k-a[i]-a[i-1];
			a[i]+=(k-a[i]-a[i-1]);
		}
	}
	printf("%d\n",ans);
	for(int i=1;i<=n;i++) printf("%d ",a[i]); 
}
