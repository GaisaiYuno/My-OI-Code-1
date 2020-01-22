#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int n,book[1001];
int CheckArray(int temp,int x)
{
	int u=1;
	for (int i=1;i<=temp;++i) u*=10;
	for (int i=1;i<=n;++i)
	if (book[i]%u==x) return book[i];
	return -1;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int q,temp,num;
	cin>>n>>q;
	for (int i=1;i<=n;++i) 
	scanf("%d",&book[i]);
	sort(book+1,book+1+n);
	for (int i=1;i<=q;++i)
	{
		scanf("%d%d",&temp,&num);
		cout<<CheckArray(temp,num)<<endl;
	}
	return 0;
}
