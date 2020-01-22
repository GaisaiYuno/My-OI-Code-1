#include<algorithm>
#include<iostream>
#include<stdio.h>
using namespace std;
int n,m,i,j,l;
string st1,id,st[1001];
bool cmp(string a,string b)
{
	int n=a.size(),m=b.size();
	if (n!=m) return n<m;
	return a<b;
}
void Find()
{
	int i,j;
	for (i=1; i<=n; i++)
	{
		st1="";
		for (j=st[i].size()-l; j<st[i].size(); j++)
		st1=st1+st[i][j];
		if (st1==id) {cout<<st[i]<<endl; return ;} 
	}
	cout<<-1<<endl;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for (i=1; i<=n; i++)
	{
		cin>>st[i];
	}
	sort(st+1,st+1+n,cmp);
	for (j=1; j<=m; j++)
	{
		cin>>l>>id;
		Find();
	}
	return 0;
}
