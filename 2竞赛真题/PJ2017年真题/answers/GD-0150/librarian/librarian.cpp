#include<bits/stdc++.h>
using namespace std;
int f,n,q,a[1001],b,i,j,l,p;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+1+n);
	for(i=1;i<=q;i++){
		scanf("%d%d",&l,&b);
		p=1;
		while(l){
			p*=10;
			l--;
		}
		f=1;
		for(j=1;j<=n;j++){
			
			if(a[j]%p==b&&f!=0){
				cout<<a[j]<<endl;
				f=0;
			}
		}
		if(f==1) cout<<-1<<endl;
	}
}
