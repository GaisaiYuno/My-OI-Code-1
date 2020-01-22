#include<bits/stdc++.h>
using namespace std;
	const int f[8]={1,10,100,1000,10000,100000,1000000,10000000};
	int n,q,a[1100],s[1100],b[1100];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=q;i++){
		int x; bool bo=true;
		scanf("%d%d",&x,&s[i]);
		for(int j=1;j<=n;j++)if(a[j]%f[x]==s[i]){
			b[i]=a[j]; bo=false; break;
		}
		if(bo)b[i]=-1;
	}
	for(int i=1;i<=q;i++)printf("%d\n",b[i]);
}
