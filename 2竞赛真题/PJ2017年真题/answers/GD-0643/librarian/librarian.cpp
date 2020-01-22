#include<iostream>
#include<fstream>
using namespace std;
long long n,q,t=10000005,sum=0,a[1005],num=1,z,g;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i];
    for(int i=1;i<=q;i++)
    {
    	  t=10000005; num=1;sum=0;
    	 cin>>z>>g;
       for(int i=1;i<=z;i++)
       num=num*10;
	for(int i=1;i<=n;i++)
	{
		if(g==a[i]||g==a[i]%num)
		{
			sum++;
			if(a[i]<t) t=a[i];
		} 	
	}
	if(sum!=0)	cout<<t<<endl;
	else cout<<-1<<endl;
    }
	return 0;
}
