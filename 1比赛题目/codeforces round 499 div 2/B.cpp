#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 105
using namespace std;
int n,m;
int a[maxn];
int cnt[maxn]; 
int check(int day){
	if(day==0) return 1;
	int peo=0;
	for(int i=1;i<=100;i++){
		if(cnt[i]==0) continue;
		else peo+=cnt[i]/day; 
	}
	if(peo<n) return 0;
	else return 1;
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	int l=0,r=maxn;
	int ans=0;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=max(ans,mid);
			l=mid+1;
		}else{
			r=mid-1;
		}
	}
	printf("%d\n",ans);
} 
