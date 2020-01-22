#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,q;
#define maxn 1010
int a[maxn];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int x,y,hehe;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	while(q--){
		scanf("%d%d",&x,&y);
		hehe=1;
		for(int j=1;j<=x;++j)hehe*=10;
		int ans=10000010;
		for(int i=1;i<=n;++i)
		if(a[i]>=y&&(a[i]-y)%hehe==0)ans=min(ans,a[i]);
		if(ans==10000010)puts("-1");
		else printf("%d\n",ans);
	}
	return 0;
}
