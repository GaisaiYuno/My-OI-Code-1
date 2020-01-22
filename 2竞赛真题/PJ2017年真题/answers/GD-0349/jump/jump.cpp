#include<iostream>
#include<cstdio>
using namespace std;
int n,d,k,u,f[500005],a[500005],b[500005],y[500005],p1,p2,i,j,g,z,t[500005],k2;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	u=0;
	for(i=1;i<=n;++i)
	 {
	 	scanf("%d%d",&a[i],&b[i]);
	 	y[i]=y[i-1];
	 	if (a[i]>0) y[i]+=a[i];
	 }
	if (y[n]<k) {cout<<-1; return 0;}
	p1=d; p2=d;t[0]=1; 
	for(i=0;i<=10000005;++i)
	 {
	 	if (i<d) p1=d-i,p2=d+i; else p1=1,p2=d+i;
	 	for(j=1;j<=n;++j)
	 	 {
		    t[j]=0,f[j]=-1000000000;	
	 	 	for(g=0;g<=j-1;++g)
	 	 	 if (a[g]>=a[j]-p2&&a[g]<=a[j]-p1) if (t[g]) f[j]=max(f[j],f[g]),z=1;
	 	 	if (z)
	 	 	{
			 f[j]+=b[j]; t[j]=1;
	 	 	 if (f[j]>=k) {cout<<i; return 0;}
	 	     if (f[j]+(y[n]-y[j])<k) break;
			  z=0;
			 } 
		//	cout<<f[j]<<" ";
		  }
	//	cout<<endl;
	 }
	cout<<-1;
	return 0;
}
