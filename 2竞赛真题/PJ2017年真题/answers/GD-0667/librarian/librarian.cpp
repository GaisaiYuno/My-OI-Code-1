#include<bits/stdc++.h>
using namespace std;
int q,n,i,j,t,a[1001],b[1001],d[1001],c[1001];
bool k;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(i=1;i<=q;i++){
		cin>>b[i]>>c[i];
	}
	j=1;
	while(q){
		k=1;
		t=1;
		for(i=1;i<=b[j];i++){
			t=t*10;
		}
		for(i=1;i<=n;i++){
			d[i]=a[i]%t;
			if(d[i]==c[j]){
				cout<<a[i]<<endl;
				k=0;
				break;
			}
		}
		if(k){
			cout<<-1<<endl;
		}
		j++;
		q--;
	}
	return 0;
}
