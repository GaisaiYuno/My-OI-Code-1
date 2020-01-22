#include<bits/stdc++.h>
using namespace std;
int f(int x){
	int p=1;
	for(int j=1;j<=x;j++){
		p*=10;
	}
	return p;
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,i,a[1001],b1[1001],b2[1001],t=1,tmp,ans;
	cin>>n>>q;
	for(i=1;i<=n;i++) cin>>a[i];
	for(i=1;i<=q;i++) cin>>b1[i]>>b2[i];
	while(t<=q){
		tmp=f(b1[t]);
		ans=10000001;
		for(i=1;i<=n;i++){
			if(a[i]%tmp==b2[t]&&a[i]<ans) ans=a[i];
		}
		if(ans==10000001) cout<<-1<<endl;
		else cout<<ans<<endl;
		t++;
	}
	return 0;
}
