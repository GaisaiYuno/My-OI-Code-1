#include<bits/stdc++.h>
using namespace std;
int n,q,a[1200],b[1200],c[1200];

int main(){
	int s=1,h=0;
	bool f=true;
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=q;i++) scanf("%d%d",&b[i],&c[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=q;i++){
		for(int j=1;j<=b[i];j++){
			s*=10;
		}
		for(int j=1;j<=n;j++){
			h=a[j]-c[i];
			if(h%s==0){
				cout<<a[j]<<endl;
				f=false;
				break;
			}
		}
		if(f) cout<<-1<<endl;
		s=1;
		f=true;
	}
}
