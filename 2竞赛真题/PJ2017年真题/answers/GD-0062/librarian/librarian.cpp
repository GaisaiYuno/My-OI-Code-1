#include<bits/stdc++.h>
using namespace std;
int zjy(int aa){
	int num=1;
	for(int ii=1;ii<=aa;ii++){
		num*=10;
	}
	return num;
}
int ans=100000000;
int n,m,a[1001],b[1001],l[1001],aans[1001];
bool flag=false;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=m;i++){
		flag=false;
		cin>>l[i];
		cin>>b[i];
		ans=1000000000;
		for(int j=1;j<=n;j++){
			if(a[j]%zjy(l[i])==b[i]){
				ans=min(ans,a[j]);
				flag=true;
			}
		}
		//if(flag==false) cout<<"-1"<<endl;
		//else cout<<ans<<endl;
		if(flag==false) aans[i]=-1;
		else aans[i]=ans;
	}
	for(int i=1;i<=m;i++) cout<<aans[i]<<endl;
	
}
