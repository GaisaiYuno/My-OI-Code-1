#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a,b,c,d[500001],s[500001],tot[500001],dd[500001],ans,r,tt,o;
int check(int f,int st)
{
	if(tt>=c&&st<=a) return 1;
	if(tt<c&&st>a) return 0;
	else 
	{
	int xx=max(b-f,0);
		int yy=min(a,st+b+f);
		for(int i=st+1;i<=a;i++)
		{
			if(dd[i]-dd[st]<=b+f&&dd[i]-dd[st]>=xx)
			{
				tt+=s[i];
				if(check(f,i)==1) return 1;
				tt-=s[i];
			}
		}
	}
	return 0;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>a>>b>>c;tot[0]=0;ans=0;d[0]=0;
	for(int i=1;i<=a;i++) 
	{
		cin>>dd[i]>>s[i];
		r=max(r,dd[i]);
		tot[i]=tot[i-1];
		if(s[i]>0)	tot[i]+=s[i];
	}
	if(tot[a]<c) 
	{
		cout<<"-1"<<endl;
		return 0;
	}
	int l=1;ans=100000;
	while(l<=r)
	{
		 tt=0;
		int mid=(l+r+1)/2;
		if(check(mid,0)==1)
		{
			ans=min(mid,ans);
		//	cout<<ans<<endl;
			r=mid-1;
		}
		else 
		{
			l=mid+1;
		}
	}
	cout<<ans<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
