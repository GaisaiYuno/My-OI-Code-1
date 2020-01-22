#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[100005],f,s;
string st[10005],st1[10005],st2[10005],st3,st4,st5;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>st[i];
	for (int i=1;i<=m;i++)
	  cin>>a[i]>>st1[i];
	for (int i=1;i<=n-1;i++)
	 for (int j=i+1;j<=n;j++)
	   if (st[i]>st[j]||st[i].size()>st[j].size()) swap(st[i],st[j]);
	for (int i=1;i<=m;i++)
	{
		f=0;
		for (int j=1;j<=n;j++)
		{
		  s=0;
		  st3="";
		  st4=st[j];
		  st5=st1[i];
		  if (st4==st5) {cout<<st4<<endl;break;}
		  for (int k=st4.size()-a[i];k<=st4.size();k++)
		    st3=st3+st4[k];
		  for (int k1=0;k1<a[i];k1++)
		    if (st3[k1]==st5[k1]) s++;
		   if (s==a[i]) {f=0;cout<<st4<<endl;break;}
		   else f=1;
	    }
	    if (f==1) {cout<<"-1"<<endl;}
	}
	return 0;
}
