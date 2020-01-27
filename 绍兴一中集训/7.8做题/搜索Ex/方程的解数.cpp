#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 7
#define maxs 33750005
using namespace std;
int n,m;
int k[maxn];
int p[maxn];
int x[maxn];
int lcnt; 
long long lans[maxs];
int rcnt; 
long long rans[maxs];
inline long long fast_pow(long long x,long long k){
	int ans=1;
	while(k){
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1;
	}
	return ans;
}

void dfs(long long *ans,int &size,int deep,int l,int r,long long sum){
	if(deep==r+1){
		ans[++size]=sum;
		return;
	}
	for(int i=1;i<=m;i++){
		x[deep]=i;
		dfs(ans,size,deep+1,l,r,sum+k[deep]*fast_pow(x[deep],p[deep]));
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&k[i],&p[i]);
	}
	dfs(lans,lcnt,1,1,n/2,0);
	dfs(rans,rcnt,n/2+1,n/2+1,n,0);
	sort(lans+1,lans+1+lcnt);
	sort(rans+1,rans+1+rcnt);
	int j=rcnt;
	long long ans,cnt1,cnt2;
	ans=0;
	for(int i=1;i<=lcnt;i++){
		while(lans[i]+rans[j]>0){
			j--;
		}
		if(j<=0) break;
		if(lans[i]+rans[j]!=0) continue;
		cnt1=cnt2=1;
		while(i<lcnt&&lans[i+1]==lans[i]){
			i++;
			cnt1++;
		}
		while(j>1&&rans[j-1]==rans[j]){
			j--;
			cnt2++;
		}
		ans+=cnt1*cnt2;
	}
	printf("%lld\n",ans);
} 
