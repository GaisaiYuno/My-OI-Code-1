#include<bits/stdc++.h>
using namespace std;
long long a[1001],n,q,i,j,k,b,m,c;
bool f;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for (i=1;i<=q;i++) {
		cin>>c>>b;
		f=false;
		for (j=1;j<=n;j++) if (f==false) {
			if (a[j]==b) {
				f=true;
				cout<<a[j]<<endl;
			}
			if (a[j]>b) {
				m=a[j];
				k=b;
				while (m%10==k%10&&k!=0) {
					m/=10;
					k/=10;
				}
				if (k==0) {
					f=true;
					cout<<a[j]<<endl;
				}
			}
		}
		if (f==false) cout<<"-1"<<endl;
	}
}
