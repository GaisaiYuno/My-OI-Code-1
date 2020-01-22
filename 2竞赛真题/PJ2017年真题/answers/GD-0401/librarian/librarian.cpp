#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
long long book[1005],ans[1005];
bool isok(int l,int j,int r)
{
	int a,b,c=book[j],d=r;
	while(l)
	{
		l--;
		a=c%10;b=d%10;
		if(a!=b)return 0;
		c/=10;d/=10;
	}
	return 1;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,p;cin>>n>>p;
	int l,r,s;
	for(int i=0;i<n;i++)
	cin>>book[i];
	sort(book,book+n);
	for(int i=0;i<p;i++)
	{
		s=0;
		cin>>l>>r;
		for(int j=0;j<n;j++)
		{
			if(isok(l,j,r))
			{
				ans[i]=book[j];s=1;break;
			}
		}
		if(s==0)
		{
			s=0;ans[i]=-1;
		}
	}
	for(int i=0;i<p;i++)
	cout<<ans[i]<<endl;
	return 0;
}
