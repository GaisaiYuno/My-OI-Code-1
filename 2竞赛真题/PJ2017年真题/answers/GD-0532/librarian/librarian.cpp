#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
const long long num=10000005;
long long xqm[1010],bm[1010],minb;
int xqml[1010],n,q;
bool check(int k,long long a)
{
	int x=1;
	for (int i=1;i<=k;i++) x*=10;
	for (int i=1;i<=n;i++)
	{
		if ((bm[i]%x==a)&&(bm[i]<minb)) minb=bm[i];
	}
	if (minb==num) return false;
	else return true;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++)
		scanf("%lld",&bm[i]);
	for (int i=1;i<=q;i++)
	{
		scanf("%d",&xqml[i]);
		scanf("%lld",&xqm[i]);
	}
	for (int i=1;i<=q;i++)
	{
		minb=num;
		if (check(xqml[i],xqm[i])) printf("%lld\n",minb);
		else cout<<-1<<endl;
	}
	return 0;
}
