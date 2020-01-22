#include<iostream>
#include<cstdio>
#define maxn 100005
using namespace std;
int n,m;
int a[maxn];
int is_ok(long long x){
	int cnt=0;
	long long tot=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x) return 0;
		if(cnt>m) return 0;
		if(tot+a[i]==x){
			tot=0;
			cnt++;
		}else if(tot+a[i]>x){
			tot=a[i];
			cnt++;
		}else{
			tot=tot+a[i];
		}
	}
	if(cnt<m) return 1;
	else return 0;
}
int main(){
	scanf("%d %d",&n,&m);
	long long sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum=sum+a[i];
	} 
	long long l=sum/m,r=sum;
	long long ans=r;
	while(l<=r){
		long long mid=(l+r)>>1;
		if(is_ok(mid)){
			ans=min(ans,mid);
			r=mid-1;
		}else {
			l=mid+1;
		}
	}
	printf("%I64d\n",ans);
} 
