#include<bits/stdc++.h>
using namespace std;
int a[1006],b,i,j,n,m,tot,k,l;
bool flag;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>m>>n;
	for(i=1;i<=m;i++) cin>>a[i];
	for(i=1;i<=n;i++){
		tot=10000007;b=1;flag=false;
		cin>>l>>k;
		for(j=1;j<=l;j++) b*=10;
		for(j=1;j<=m;j++){
			if(a[j]%b==k) {
				tot=min(tot,a[j]);
				flag=true;
			}
		}
		if(flag) cout<<tot<<endl;
		else cout<<"-1"<<endl;
	}
}
