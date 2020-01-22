#include<bits/stdc++.h>
using namespace std;
int n,m,i,j,a[1100],x,f,l,k,ans[1100];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for (i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (i=1;i<=m;i++){
		cin>>l>>k;
		x=1,f=1;
		while (l) x*=10,l--;
		for (j=1;j<=n;j++){
			if (a[j]>=k) f=(a[j]-k)%x;	
			if (!f) break;
		}
		if (f) ans[i]=-1;
		else ans[i]=a[j];
	}
	for (i=1;i<=m;i++) cout<<ans[i]<<endl;
	return 0;
}
