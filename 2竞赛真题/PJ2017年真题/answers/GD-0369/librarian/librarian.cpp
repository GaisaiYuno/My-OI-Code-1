#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int n,m,num[1010],Len,nee,minn,mo,ans[1010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>num[i];
	for (int i=1;i<=m;i++) 
	{
		cin>>Len>>nee;
	    minn=2147483647;
	    mo=pow(10,Len);
	    for (int j=1;j<=n;j++)
	      if (num[j]%mo==nee) minn=min(num[j],minn);
        if (minn!=2147483647) ans[i]=minn; else ans[i]=-1;
	}
	for (int i=1;i<=m;i++) cout<<ans[i]<<endl;
	return 0;
}
