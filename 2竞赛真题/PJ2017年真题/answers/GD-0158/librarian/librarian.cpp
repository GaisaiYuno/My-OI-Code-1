#include<bits/stdc++.h>
using namespace std;
long long an[1010],aq2;
int n,q,aq1;
int sq(int a){
	long long b=1;
	while(a!=0) b*=10,a--;
	return b;
}
int main(){
	freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>an[i];
	sort(an+1,an+n+1);
	for(int i=1;i<=q;i++){
		cin>>aq1>>aq2;
		bool f=false;
		long long k=sq(aq1);
		for(int j=1;j<=n;j++) if(an[j]%k==aq2){
			cout<<an[j];
			f=true;
			break;
		}
		if(f==false) cout<<-1;
	}
}
