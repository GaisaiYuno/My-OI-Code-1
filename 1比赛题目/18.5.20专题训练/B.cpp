#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50005
using namespace std;
int n,m;
int d[maxn];
int is_ok(int x){
	int cnt=0;
	int last=0;
	for(int i=1;i<=n+1;i++){
		if(d[i]-last<x){
			cnt++;
			if(cnt>m) return 0;
		}else last=d[i];
	}
	if(cnt>m) return 0;
	else return 1;
}
int ll;
int main(){
	int l,r=0;
	scanf("%d %d %d",&ll,&n,&m);
	d[0]=0;
	d[n+1]=ll;
	for(int i=1;i<=n;i++){
		scanf("%d",&d[i]);
	} 
	sort(d,d+n+2);
	l=0,r=ll;
	int ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(is_ok(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}else {
			r=mid-1;
		}
	}
	printf("%d\n",ans);
}
