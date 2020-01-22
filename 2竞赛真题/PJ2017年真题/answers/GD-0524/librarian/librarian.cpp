#include<bits/stdc++.h>
using namespace std;
int a[1001],b[1001],c[1001],ans[1001];
bool p[1001];
int main(){
	int n,q;
	memset(ans,5000001,sizeof(ans));
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=q;i++) cin>>b[i]>>c[i];
	for(int i=1;i<=q;i++){
		int k=1;
			while(b[i]>0){
				k*=10;
				b[i]-=1;
			}
		for(int j=1;j<=n;j++){
			if((a[j]-c[i])%k==0){
			    ans[i]=min(ans[i],a[j]);
			    p[i]=true;
		    }
		} 
	}
	for(int i=1;i<=q;i++){
		if(p[i]) cout<<ans[i];
		else cout<<"-1";
		if(i!=q) cout<<endl;
	}
}


/*5 5
2123
1123
23
24
24
2 23
3 123
3 124
2 12
2 12*/

