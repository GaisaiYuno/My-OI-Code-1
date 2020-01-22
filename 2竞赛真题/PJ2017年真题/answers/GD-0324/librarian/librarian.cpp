#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,q,a[10005],b[10005],c[10005],s,f[10005],g[100],p1,k1,k,p,t,p11,s1;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=q;i++) cin>>b[i]>>c[i];
	sort(a+1,a+1+n);
	for (int i=1;i<=q;i++)
	{
		p1=0;
		for (int j=1;j<=n;j++)
		{
			  s=a[j];
		      k=0;
		      while (s!=0)
		      {
			  k++;
			  g[k]=s%10;
			  s=s/10;
		      }
		     for (int o=1;o<=k/2;o++) 
			 {
			  t=g[o];g[o]=g[k-o+1];g[k-o+1]=t;
			 }
		     k1=0;
	         s=c[i];
	         while (s!=0)
	         {
	        	  k1++;
	        	  f[k1]=s%10;
	        	  s=s/10;
           	 }
           	 for (int o=1;o<=k1/2;o++) 
			 {
			  t=f[o];f[o]=f[k1-o+1];f[k1-o+1]=t;
			 }
			 p=0;
			 if (k>=k1)
			 {
			  s1=k1;p11=0;
			  for (int r=k;r>=k-k1+1;r--)
		      {
				 if (g[r]!=f[s1]) p11=1;
				 s1--; 
		      }	
			  if (p11==0) {
	          cout<<a[j]<<endl;p=1;break;}		 
			 }
		}
		if (p==0) cout<<-1<<endl;
	}
	return 0;
}
