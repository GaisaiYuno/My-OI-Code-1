#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[1005],b[1005],k,d;
bool du;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	  scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		du=false;
		d=1;
		scanf("%d%d",&k,&b[i]);
		for(int j=1;j<=k;j++)
		  d*=10;
		for(int j=1;j<=n;j++)
		{
			if(a[j]%d==b[i])
			{
				cout<<a[j]<<endl;
				du=true;
				break;
			} 
		}
		if(du==false) cout<<-1<<endl;
	}
	return 0;
}
