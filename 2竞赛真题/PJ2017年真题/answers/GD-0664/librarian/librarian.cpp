#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	long long n,q,x,y,a[1001],b[1001]={0};
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	for(int i=1;i<=q;i++)
	{
		cin>>x>>y;
		long long min=10000000;
		for(int j=1;j<=n;j++)
		{
			int k=1;
			for(int h=1;h<=x;h++)
			k*=10;
			if(a[j]%k==y)
			if(a[j]<min) min=a[j];
		}
		if(min!=10000000) b[i]=min;
	}
	for(int i=1;i<=q;i++)
	if(b[i]==0) cout<<-1<<endl;
	else cout<<b[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
