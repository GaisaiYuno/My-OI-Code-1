#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;
struct data
{
	int a,b[50];
}a[1005];
int n,m,s,w,q,t,b[50];
bool f,ff;
bool cmp(data a,data b)
{
	return a.a<b.a;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++) 
	{
		scanf("%d",&a[i].a); 
		s=a[i].a; w=0;
		while (s>0)
		{
			w++;
			a[i].b[w]=s%10;
			s/=10;
		}
		a[i].b[0]=w;
	}
	sort(a+1,a+1+n,cmp);
	for (int i=1;i<=m;i++)
	{
		scanf("%d%d",&q,&t);
		s=t; w=0; ff=false;
		while (s>0) { w++; b[w]=s%10; s/=10; }
		for (int j=1;j<=n;j++)
		  if (q<=a[j].b[0])
		  {
		  	  f=true;
		  	  for (int k=1;k<=q;k++)
		  	    if (b[k]!=a[j].b[k]) {  f=false; break; }
		  	  if (f) { ff=true; cout<<a[j].a<<endl; break; }
		  }
		if (!ff) cout<<-1<<endl;
	}
	return 0;
}
