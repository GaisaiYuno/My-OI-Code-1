#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<cstring>
using namespace std;
int n,q,len;
string st[1005],st1;
bool Com(string st1,string st2)
{
	if (st1.size()<st2.size()) return true;
	if (st1.size()>st2.size()) return false;
	if (st1<st2) return true;
	return false;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++)
	  cin>>st[i];
	for (int i=1;i<=q;i++)
	  {
	  	scanf("%d",&len);
	  	cin>>st1;
	  	string mast="1000000000000";
	  	for (int j=1;j<=n;j++)
	  	  {
	  	  	if (st[j].size()<len) continue;
	  	  	string st2="";
	  	  	int len1=st[j].size()-len;
	  	  	for (int k=st[j].size()-1;k>=len1;k--)
	  	  	  {
	  	  	  	if (k==-1) cout<<st[j].size()-len;
	  	  	  	st2=st[j][k]+st2;
	  	  	  }
	  	  	
	  	  	if (st1==st2) if (Com(st[j],mast)) mast=st[j];
	  	  	
	  	  }
	  	if (mast=="1000000000000") printf("%d\n",-1);else cout<<mast<<endl;
	  }
	return 0;
}
