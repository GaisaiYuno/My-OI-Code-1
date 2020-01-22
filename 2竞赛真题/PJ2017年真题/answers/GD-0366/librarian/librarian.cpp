#include<bits/stdc++.h>
using namespace std;
int a[1100],ans,n,q,k,b,c,i,j,tot[1100];
int main(){
	
	freopen("librarian.in","read",stdin);
	freopen("librarian.out","write",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=q;i++){
		scanf("%d%d",&b,&c);
		k=1;
		ans=11000000;
		for(j=1;j<=b;j++) k=k*10;
		for(j=1;j<=n;j++) if(a[j]%k==c) ans=min(ans,a[j]);
		if(ans==11000000) ans=-1;
		tot[i]=ans;
	}
	for(i=1;i<=q;i++) cout<<tot[i]<<endl;
}

