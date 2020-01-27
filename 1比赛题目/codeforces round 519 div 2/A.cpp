#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
#define INF 1e9
using namespace std;
int n;
int a[maxn];
int t,s;
int check(int x){
	long long te=0,ta=0;
	for(int i=1;i<=n;i++){
		te+=a[i];
		ta+=(x-a[i]);
	}
	if(ta>te) return 1;
	else return 0;
}
int bin_search(){
	int l=t,r=s*3;
	int mid;
	int ans=s*3;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	} 
	return ans;
} 
int main(){
	scanf("%d",&n);
	t=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		t=max(a[i],t);
		s+=a[i];
	}
	printf("%d\n",bin_search());
}
