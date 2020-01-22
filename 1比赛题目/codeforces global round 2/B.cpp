#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1005
using namespace std;
int n;
long long h;
long long a[maxn];
long long b[maxn];
bool check(int mid){
	for(int i=1;i<=mid;i++){
		b[i]=a[i];
	}
	sort(b+1,b+1+mid);
	long long ans=0;
	if(mid%2){
		ans+=b[1];
		for(int i=2;i<=mid;i+=2){
			ans+=max(b[i],b[i+1]);
		} 
		if(ans>h) return 0;
		else return 1;
	}else{
		for(int i=1;i<=mid;i+=2){
			ans+=max(b[i],b[i+1]); 
		}
		if(ans>h) return 0;
		else return 1;
	}
}
int main(){
	scanf("%d %I64d",&n,&h);
	for(int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	int l=0,r=n;
	int mid,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	printf("%d\n",ans);
}

