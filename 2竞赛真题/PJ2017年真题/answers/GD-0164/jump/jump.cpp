#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define MAXN 500005

int n,d,k;
int x[MAXN],s[MAXN];
int l,r,mid,ans=-1;
int f[MAXN],L,R,mx,mmx;

bool check(int t){
	if(t<d) L=d-t,R=d+t;
	else L=1,R=d+t;
	for(int i=1;i<=n;++i)
		f[i]=-9999999;
	f[0]=0;
	for(int i=1;i<=n;++i){
		mmx=-9999999;
		if(L==1){
			int j=0;
			while(x[j]<x[i]-R && j<=i-1) ++j;
			for(;j<=i-1;++j){
				mmx=max(mmx,f[j]);
			}
		} else{
			for(int j=0;j<=i-1;++j){
				if(L<=x[i]-x[j]&&x[i]-x[j]<=R){
					mmx=max(mmx,f[j]);
				}
			}
		}
		f[i]=mmx+s[i];
	}
	mx=-9999999;
	for(int i=0;i<=n;++i)
		mx=max(mx,f[i]);
	if(mx>=k) return 1;
	 else return 0;
}

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	x[0]=0;s[0]=0;
	for(int i=1;i<=n;++i){
		scanf("%d%d",&x[i],&s[i]);
	}
	l=0;r=x[n]-d;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			r=mid-1;ans=mid;
		} else{
			l=mid+1;
		}
	}
	printf("%d\n",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
