#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;
int book[1000001],read[1001],chang[1001],i,n,q;
int find()
{
	int k=pow(10,chang[i]);
	for(int j=read[i];j<=1000001;j=j+k)
	{
		if(book[j]==1)
			return j;
	}
	return -1;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int ch;
	cin>>n>>q;
	for(i=1;i<=n;i++)
	{
		cin>>ch;
		book[ch]=1;	
	}
	for(i=1;i<=q;i++)cin>>chang[i]>>read[i];
	for(i=1;i<=q;i++)
	{
		cout<<find()<<endl;
	}
	return 0;
}
