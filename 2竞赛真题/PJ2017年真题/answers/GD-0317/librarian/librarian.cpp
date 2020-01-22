#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,q,i,a[1100],j;
struct hs{
	int len;
	int z;
}b[1100];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=q;i++){
		int ans;j=1;
		cin>>b[i].len>>b[i].z;
		bool p=false;
		while(j<=n&&p==false){
			int chu=pow(10,b[i].len);
			if(a[j]%chu==b[i].z){
				ans=a[j];p=true;
			}
			else j++;
		}
		if(p==true)cout<<ans<<endl;
		else cout<<-1<<endl;
	}
}
