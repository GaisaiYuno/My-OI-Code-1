#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define INF 0x7fffffff
#define maxn 1005
using namespace std;
int n,m;
int a[maxn];
int b[maxn];
int tmp[maxn];
int check(int k){
	for(int i=1;i<=n;i++) tmp[i]=a[i];
	for(int i=k;i>=1;i--){
		int minv=INF;
		int pos=0;
		for(int j=1;j<=n;j++){
			if(tmp[j]>=b[i]){
				if(tmp[j]<=minv){
					minv=tmp[j];
					pos=j;
				}
			}
		}
		if(pos==0) return 0;
		tmp[pos]-=b[i];
	}
	return 1;
}
int main(){
	freopen("cqfj.in","r",stdin);
	freopen("cqfj.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++) {
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(int i=1; i<=m; i++) {
		scanf("%d",&b[i]);
	}
	sort(b+1,b+1+m);
	int l=0,r=m,mid;
	int ans=0;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	printf("%d\n",ans);
}
//Dedicated to Selina. She is my love forever.
