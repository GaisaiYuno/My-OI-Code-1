#include<bits/stdc++.h>
using namespace std;

int n,q,a[1005],l[1005],p[1005],ans[1005];

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	memset(ans,0x7f,sizeof(ans));
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=q;i++) {
		cin>>l[i]>>p[i];
		for(int j=1;j<=n;j++){
			int cnt=pow(10,l[i]);
			if(a[j]%cnt==p[i]) ans[i]=min(ans[i],a[j]);
		}
		if(ans[i]>10000001) ans[i]=-1;
		cout<<ans[i]<<endl;
	}
	return 0;
}
