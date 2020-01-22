#include<bits/stdc++.h>
using namespace std;

long long b[1001],s[1001],w[1001],sum=1;
int n,q;
bool f[1001],flag=true;

int m(int k) {
	sum=1;
	for (int ii=1;ii<=k;ii++) sum*=10;
	return sum;
}

int main () {
	freopen ("librarian.in","r",stdin);
	freopen ("librarian.out","w",stdout);
	memset (f,true,sizeof (f));
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>b[i];
	for (int i=1;i<=q;i++) cin>>s[i]>>w[i];
	sort (b+1,b+n+1);
	for (int i=1;i<=q;i++) {
		m(s[i]);
		flag=true;
		for (int j=1;j<=n;j++) {
			if (b[j]%sum==w[i] && f[j] && flag) {
				f[j]=flag=false;
				cout<<b[j]<<endl;
			}
			if (j==n && flag) cout<<"-1"<<endl;
		}
	}
	return 0;
}
