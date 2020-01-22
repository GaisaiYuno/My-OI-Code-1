#include<bits/stdc++.h>
using namespace std;
int n,q,a[1001],b[1001],c[1001];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=q;i++) cin>>b[i]>>c[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=q;i++) {
		for (int j=1;j<=n;j++) {
			int k=1;
			for (int i=1;i<=b[i];i++) k*=10;
			if (a[j]%k==c[i]) {
				cout<<a[j]<<endl;
				break;
			}
			if (j==n) cout<<-1<<endl;
		}
	}
	return 0;
}
