#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,p[1100],r,i,j,x;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
		scanf("%lld",&p[i]);
	sort(p+1,p+n+1);
	for(i=1;i<=m;i++){
		scanf("%lld%lld",&x,&r);
		long long l=1,ans=-1;
		while(x)x--,l*=10;
		for(j=1;j<=n;j++)
			if(p[j]%l==r){
				ans=p[j];
				break;
			}
		printf("%lld\n",ans);
	}
}
