#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
long long a[1001];
int n,q,b[1001],len,num,ans,tot;
bool f=true;
long long shi(int kk){
	ans=1;
	for (int j=1;j<=kk;j++) ans=ans*10;
	return ans;
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	sort (a+1,a+n+1);
	for (int i=1;i<=q;i++){
		cin>>len>>num;
		f=true;
		for (int k=1;k<=n;k++){
			tot=a[k]%shi(len);
			if (num==tot){
				cout<<a[k]<<endl;
				f=false;
				break;
			}
		}
		if (f==true) cout<<"-1"<<endl;
	}
}
