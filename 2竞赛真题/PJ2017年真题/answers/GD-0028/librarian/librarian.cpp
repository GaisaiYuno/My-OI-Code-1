#include<bits/stdc++.h>
using namespace std;
int a[1005],b[1005],c[1005],n,q;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=q;i++) cin>>b[i]>>c[i];
	for(int i=1;i<=q;i++){
		bool f=false;
		int tot=10000000;
		for(int j=1;j<=n;j++){
			int sum=1;
			for(int k=1;k<=b[i];k++) sum*=10;
			if(a[j]%sum==c[i]){
				tot=min(a[j],tot);
				f=true;
			}
		}
		if(f==false) cout<<"-1"<<endl;
		else cout<<tot<<endl;
	}
	return 0;
}
