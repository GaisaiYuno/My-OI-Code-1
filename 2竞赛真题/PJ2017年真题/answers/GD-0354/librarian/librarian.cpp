#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
using namespace std;
int n,q,a[1005],x,w,ans,t;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	for (int i=1;i<=q;i++){
		cin>>w>>x;
		ans=1000000000;
		for (int i=1;i<=n;i++){
			t=(int)pow(10,w);
			if (a[i]%t==x&&a[i]<ans) ans=a[i]; 
		}
		if (ans==1000000000) ans=-1;
		cout<<ans<<endl;
	}
	return 0;
}
