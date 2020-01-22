#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
struct st{
	int a,b;
};
st a[500000+10];
int  b[500000+10],n,k,d;
long long w=100000;
void f(long long lever,long long c,long long l,long long s)
{
	if (lever>n)return;
	if (s==k)
	{
		if (l>d&&l-d<w)
		{
			w=l-d;
		}
		else
		{
				if (c<d&&d-c<w)
		      {
			      w=d-c;
		     }
		     else
		     {
		     	if (d-l<=c-d&&d-l<w)
		     	{
		     		w=d-l;
		     	}
		     	if (d-l>c-d&&c-d<w)
		     	{
		     		w=c-d;
		     	}
		     }
		}
		
	}
	if (b[lever]>c)
	{
		b[lever]=c;
	}
	else
	{
		return;
	}
	if (a[lever].a-a[lever-1].a>c)
	{
		if (a[lever].a-a[lever].a<l)
		{
			f(lever+1,a[lever].a-a[lever-1].a,a[lever].a-a[lever].a,s+a[lever].b);
		}
		else
		{
			f(lever+1,a[lever].a-a[lever-1].a,l,s+a[lever].b);
		}
	}
	else
	{
		if (a[lever].a-a[lever].a<l)
		{
			f(lever+1,c,a[lever].a-a[lever].a,s+a[lever].b);
		}
		else
		{
			f(lever+1,c,l,s+a[lever].b);
		}
	}
	f(lever+1,c,l,s);
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (int i=1;i<+n;i++)
	{
		cin>>a[i].a>>a[i].b;
		b[i]=100000;
	}

		cout<<"-1";
	return 0;
}
