#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","r",stdout);
	long long n,q,a[10000],b[10000],c[10000],ans=1;
	bool flag=false;
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=q;i++) cin>>b[i]>>c[i];
	for(int i=1;i<=q;i++){
		for(int j=1;j<=n;j++){
			for(int k=1;k<=b[i];k++) ans*=10;
			if(a[j]%ans==c[i]){
				cout<<a[j]<<endl;
				flag=true;
				ans=1;
				break;
			}
			ans=1;
		}
		if(!flag) cout<<"-1"<<endl;
		flag=false;
	}
	return 0;
}
