#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
int n,q,a[1001],x,b;
int c[9]={0,10,100,1000,10000,100000,1000000,10000000,100000000};
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&x,&b);
		int ans=10000002;
		for(int j=1;j<=n;j++){
			if(a[j]%c[x]==b)ans=min(ans,a[j]);
		}
		if(ans==10000002)printf("-1\n");
		else printf("%d\n",ans);
	}
	return 0;
	fclose(stdin);
	fclose(stdout);
}
