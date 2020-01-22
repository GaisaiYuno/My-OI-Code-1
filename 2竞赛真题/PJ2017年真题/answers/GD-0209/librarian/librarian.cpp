#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
int b[1010],n,m,le,a,q;
double mm;
int check(int c,int d)
{
	int m1=0,d1,c1;
	while(c>0 && d>0)
	{
		c1=c%10;
		d1=d%10;
		c=c/10;
		d=d/10;
		m1++;
		if(c1!=d1) return false; 
		if(m1==le) return true;
	}
	if(m1<le) return false;
	  else   return true;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&b[i]);		
	for(int i=1;i<=q;i++)
	{
		mm=false;
		int num=10000009;
		scanf("%d%d",&le,&a);
		for(int j=1;j<=n;j++)
		{
			if(check(b[j],a)) {num=min(num,b[j]);mm=true;}
		}
		if(mm) printf("%d\n",num);
		  else printf("%d\n",-1);
	}
	return 0;
}
