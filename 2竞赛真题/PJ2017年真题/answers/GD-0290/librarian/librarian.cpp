#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int n,m,q;
string st[1000],st1;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>st[i];
	for(int i=1;i<n;i++)
	 for(int j=i+1;j<=n;j++)
	   if(st[i].size()>st[j].size()||(st[i].size()==st[j].size())&&st[i]>st[j])
	   {
	   	 string stt;
	   	 stt=st[i];st[i]=st[j];st[j]=stt;
	   }
	for(int i=1;i<=m;i++)
	{
		int t1=0;
		cin>>q>>st1;
		for(int j=1;j<=n;j++)
		{
			int len=st[j].size(),t=0,z=0;
			for(int k=len-q;k<len;k++) 
			{
				if(st[j][k]!=st1[z]) {t=1;break;}
				z++; 
			}
			if(t==0) {cout<<st[j]<<endl;t1=1;break;}
		}
		if(t1==0) cout<<-1<<endl;
	}
	return 0;
}

