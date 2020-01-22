#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string s;
int a[100000],b[1001],n,q,min1=10000000;
bool flag=false; 
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
for(int i=1;i<=n;++i)cin>>a[i];
for(int i=1;i<=q;++i)
{
	int x,y;
	cin>>x>>y;
	for(int j=1;j<=n;++j)
{
	if(y==a[j])
	{
		min1=min(min1,a[j]);
		flag=true;
	}
  else	if(flag==false&&j+1>n)
	{
		cout<<-1<<endl;
		continue;
	}
}
}
cout<<endl;
}
