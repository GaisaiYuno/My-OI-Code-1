#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
int n,q,a[20005],mi,x,y,sum;
string l,ll,st[20005],st1;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&q);
	for (int i=1;i<=n;i++)
	{
		cin>>ll;
		sum=0;
		for (int j=0;j<ll.size();j++) sum=sum*10+(ll[j]-48);
		st[i]=ll;a[i]=sum;
	}
	for (int i=1;i<=q;i++)
	{
		cin>>x>>st1;
		mi=100000000;
	    for (int j=1;j<=n;j++)
	    {
	        l="";
	        int len=st[j].size();
	        string st2=st[j];
	        for (int k=len-x;k<len;k++) l+=st2[k];
	        if (l==st1) mi=min(mi,a[j]);
	    }
	    if (mi==100000000) cout<<-1<<endl;else cout<<mi<<endl;
	}
	return 0;
}
