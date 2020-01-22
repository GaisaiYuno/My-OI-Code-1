#include<bits/stdc++.h>
using namespace std;
int s[10]={0,10,100,1000,10000,100000,1000000,10000000,100000000};
int n,q,b,l,ans;
int a[10001];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=q;i++){
		cin>>l>>b;
		ans=2147483647;
		for(int j=1;j<=n;j++)if((a[j]-b)%s[l]==0) ans=min(ans,a[j]);
		if(ans==2147483647) cout<<"-1\n";
		else cout<<ans<<"\n";
	}
	return 0;
}
