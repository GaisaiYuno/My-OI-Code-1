#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int n,m,i,j,p,t,l,b,j2,e,s,r;
int a[1005],c[1005][15];
int main()
{    
    freopen("librarian.in","r",stdin);
    freopen("librarian.out","w",stdout);
    
	scanf("%d%d",&n,&m);
	for (i=0;i<n;i++)
	 scanf("%d",&a[i]);
    for (i=0;i<n-1;i++)
     for (j=i;j<n;j++)
      if (a[i]>a[j]) { t=a[i]; a[i]=a[j]; a[j]=t; }
    for (i=0;i<n;i++)
    {
     t=0; p=a[i];
	 while (p>0)
	 {
	  t++; 
	  c[i][t]=p%10;
	  p=p/10;
	 }
	 c[i][0]=t;
    }
	for (i=0;i<m;i++)
	{
	 t=0; 
	 scanf("%d%d",&e,&b);
     for (j=0;j<n;j++)
      {
       s=0; r=1;
       for (j2=1;j2<=e;j2++)
       {
	    s=s+c[j][j2]*r; r=r*10;
       }
       if (s==b) { printf("%d\n",a[j]); t=1; break; }
      }
     if (t==0) printf("%d\n",-1);
	}
	
	return 0;
}
