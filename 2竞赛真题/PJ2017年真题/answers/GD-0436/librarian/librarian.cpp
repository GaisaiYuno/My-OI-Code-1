#include<cstdio>
#include<iostream>
#include<cstdlib>
#include<map>
#include<algorithm>
#include<math.h>
using namespace std;
int n,q,a[1001],b[1001],w,d[1001],ant;
const int c[9]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=q;++i)
	{
		ant=0;
		cin>>w>>b[i];
		for(int j=1;j<=n;++j)
		{
		//	cout<<a[j]<<" "<<c[w]<<" "<<a[i]%c[w]<<endl;
			if(a[j]%c[w]==b[i])
			{
				ant++;
				d[ant]=a[j];
		//		cout<<"fuck!"<<endl;
			}
		}
		if(ant==0)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			sort(d+1,d+ant+1);
			cout<<d[1]/*<<" "<<d[2]<<" "<<d[3]&*/<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
