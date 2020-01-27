//BZOJ 1082 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1005
using namespace std;
int n,m;
int a[maxn],b[maxn],tmp[maxn];
int suma[maxn],sumb[maxn];
int t;
int dfs(int x,int last,int mid){
	if(x<=0) return 1;
	if(suma[n]-t<sumb[mid]) return 0;
	for(int i=last;i<=n;i++){
		if(tmp[i]>=b[x]){
            tmp[i]-=b[x];
            if(tmp[i]<b[1]) t+=tmp[i];
            if(b[x]==b[x-1]){
                if(dfs(x-1,i,mid)) return 1;
            }
            else {
            	if(dfs(x-1,1,mid)) return 1;
			}
            if(tmp[i]<b[1])t-=tmp[i];
            tmp[i]+=b[x];
        }
	}
	return 0;
} 
int check(int mid){
	t=0;
	for(int i=1;i<=n;i++) tmp[i]=a[i];
	return dfs(mid,1,mid);
}
int bin_search(){
	int l=1,r=m;
	int ans=0;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	} 
	scanf("%d",&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&b[i]);
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+m);
	for(int i=1;i<=n;i++){
		suma[i]=suma[i-1]+a[i];
	} 
	for(int i=1;i<=m;i++){
		sumb[i]=sumb[i-1]+b[i];
	}
	while(suma[n]<sumb[m]) m--;
	printf("%d\n",bin_search());
	return 0;
} 
