#include<algorithm>
#include<iostream>
#include<stdio.h>
#include<cstring>
#include<string>
using namespace std;
int n,q;
struct pp{
	string str;
	int len;
}a[1005];
bool cmp(pp a,pp b)
{
	if(a.len==b.len)
	return a.str<b.str;
	return a.len<b.len;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);

	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].str;
		a[i].len=a[i].str.size();
	}
	sort(a+1,a+1+n,cmp);
	int len,k=0;
	string size,str5;
	for(int i=1;i<=q;i++)
	{int xx=0;
		str5="";
		k=0;
		scanf("%d",&len);
		cin>>size;
		for(int j=1;j<=n;j++)
		{   xx=a[j].len-len;
		    str5="";
		    if(xx<0)xx=0;
		    str5="";
			for(int x=xx;x<a[j].len;x++)
			{
				str5+=a[j].str[x];
			}
			if(size==str5){cout<<a[j].str<<endl;k=1;break;}
			
		}
		if(k!=1)printf("-1\n");
	}
	return 0;
}
