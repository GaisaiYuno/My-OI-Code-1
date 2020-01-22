#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<string>
using namespace std;
string st;int n,q,p,x,y,Min,z,a[1005];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
	{
	    cin>>st;
        for(int j=0;j<st.size();j++) a[i]=a[i]*10+int(st[j])-'0';
    }
    sort(a+1,a+1+n);
	for(int i=1;i<=q;i++)
	{		
	    scanf("%d%d",&x,&y);
		p=0;Min=10000005;z=10;
	    for(int j=2;j<=x;j++) z*=10;
		for(int k=1;k<=n;k++)
		{
	        if (a[k]%z==y) {printf("%d\n",a[k]);p=1;break;}	
	    }
	    if (p==0) cout<<-1<<endl;
	}
	return 0;
}
