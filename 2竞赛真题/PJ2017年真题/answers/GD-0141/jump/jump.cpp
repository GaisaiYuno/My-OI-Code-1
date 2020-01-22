#include<iostream>
#include<cstdio>
using namespace std;
long long n,k,q1[500005],a[500005],b[500005],x,c,l,o,i,p,p1,j,v=-1000000005,u,y,q;
int d,t;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(i=1;i<=n;++i)
	{
	 scanf("%lld",&a[i]);
	 cin>>b[i];
	 if (b[i]>0) q+=b[i];
	 q1[i]=q1[i-1]+b[i];	
	}
	if (q<k) {cout<<-1;return 0;}
	if (d>=a[1]) i=1; else i=a[1]-d;
	while(1)
	{
	 c=0;
	 x=0;
	 l=0;	
	 y=0;
	 t=0;
	 if (d-i<=0) p=1; else p=d-i;
	 p1=d+i;
     while(x<k)
	 {
	 if (c+p1<a[l]) break;	
	  for(j=p;j<=p1;++j)
	  {
	   if (c+j<a[u+1])  continue;
	   for(o=u+1;o<=n;++o)
	    if (a[o]>c+j) break;
	   if (o==n) l=o; else l=o-1;
	   if (a[l]-c<p||a[l]-c>p1) {t==1;break;}
	   if (q1[l]-q1[u]>v) {v=q1[l]-q1[u];u=l;}
      }
      if (t==1) continue;
      x+=v-q1[y];
      c=a[u];
      v=-1000000005;
	 }
	 if (x>=k) {cout<<i;return 0;}  
	 i++;
	}
}
