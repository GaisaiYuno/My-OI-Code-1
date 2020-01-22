#include<bits/stdc++.h>
using namespace std;
int n,q,lb[1001],a[1001],b[1001],k,mina,wu;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	mina=-1;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=q;i++)cin>>wu>>b[i];
	for(int i=1;i<=q;i++){
		k=1;
		mina=-1;
		int c=b[i];
		while(c>=10){
			c=c/10;
			k++;
		}
		int op=1;
		while(k>0){
			op=op*10;
			k--;
		}
		for(int j=1;j<=n;j++){
			if((a[j]-b[i])%op==0)
			  if(a[j]<mina||mina==-1)mina=a[j];
		}
		cout<<mina<<endl;
	}
}
