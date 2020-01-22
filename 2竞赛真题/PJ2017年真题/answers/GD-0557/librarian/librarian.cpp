#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
int n,q,book[1001],reader;
bool p=1;
int mi(int b)
{
	long long a=1;
	for(int i=1;i<=b;i++)
		a*=10;
	return a;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>book[i];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n-i;j++)
			if(book[j]>book[j+1])
				swap(book[j],book[j+1]);
	for(int i=1,x;i<=q;i++)
	{
		cin>>x>>reader;
		for(int j=1;j<=n;j++)
			if(book[j]%mi(x)==reader)
			{
				cout<<book[j]<<endl;
				p=0;
				break;
			}
		if(p==1)
			cout<<-1<<endl;
		p=1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
