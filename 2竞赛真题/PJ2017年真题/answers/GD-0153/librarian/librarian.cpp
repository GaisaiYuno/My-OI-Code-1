#include<iostream>
#include<algorithm>
#include<cmath> 
#include<cstdio>
using namespace std;
struct dz
{
	int xqm;
	int len;
};
int a[1001],n,q;
dz b[1001];
int hounwei(int g,int n)
{
	int m=0;
	for(int i=0;i<n;i++)
	{
		m=m+g%10*pow(10,i);
		g/=10;
	}
	return m;
}
int Search(int len1,int xqm1)
{
	for(int i=0;i<n;i++)
	{
		int m=hounwei(a[i],len1);
		if(m==xqm1)	return a[i];		
	}
	return -1;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>q;
	for(int i=0;i<n;i++)	cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<q;i++)
	{
		cin>>b[i].len>>b[i].xqm;
		cout<<Search(b[i].len,b[i].xqm)<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
