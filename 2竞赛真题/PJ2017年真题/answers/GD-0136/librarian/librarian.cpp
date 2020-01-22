#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int n,q,len,b,a[1005];
/*void fan(int a,string st)
{
	string ss;
	for(int i=0;i<a;i++)
	{
		ss[i]=st[a-i+1];
	}
	check(ss);
}*/
int check(int x)
{
	int m=x,ans=0,f=0,r=0,t=0,w=0;
	for(int i=1;i<=n;i++)
	{
		w=a[i];f=0;ans=0;r=0;t=0;
		if(m>w)continue;
		if(m==w){ans=w;break;}
		if(m<w)
		{	
			while(w>0&&m>0)
			{
				r=w%10;
				t=m%10;
				if(r!=t){f=1;break;}
				w=w/10;
				m=m/10;
			}
		}
		if(f==0){ans=a[i];break;}
		if(f==1){ans=-1;}
	}
	return ans;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=q;i++)
	{
		cin>>len;
		cin>>b;
		//fan(len,b);
		cout<<check(b)<<endl;
	}
	return 0;
}
