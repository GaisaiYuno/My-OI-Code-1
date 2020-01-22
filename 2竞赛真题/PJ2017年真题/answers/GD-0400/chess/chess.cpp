#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int main() 
{
	int a[201][201],dl[111111],f[201],l,r,m,n,x[201],y[201],z[201],bj=0,k;
	freopen("chess.in","r",stdin); freopen("chess.out","w",stdout);
	 cin>>m>>n;
	 for (int i=1;i<=n;i++)
	 {
	 	cin>>x[i]>>y[i]>>z[i];
	 	a[i][i]=0;
	 	if ((x[i]==m)and(y[i]==m)) bj=i;
        for (int j=1;j<i;j++)
        {
        	if (x[i]-x[j]>0) a[i][j]=x[i]-x[j];
        	else a[i][j]=x[j]-x[i];
        	if (y[i]-y[j]>0) a[i][j]+=y[i]-y[j];
        	else a[i][j]+=y[j]-y[i];
        	if (a[i][j]>2) a[i][j]=32768;
			if ((z[i]!=z[j])and(a[i][j]==2)) a[i][j]++;
			if ((z[i]==z[j])and(a[i][j]==1)) a[i][j]--;
			a[j][i]=a[i][j];
        }
	 }
	 if (bj=0) 
     {  
	    n++; a[n][n]=0; bj=n;        
	    for (int j=1;j<n;j++)
        {
        	if (x[n]-x[j]>0) a[n][j]=x[n]-x[j];
        	else a[n][j]=x[j]-x[n];
        	if (y[n]-y[j]>0) a[n][j]+=y[n]-y[j];
        	else a[n][j]+=y[j]-y[n];
        	if (a[n][j]>2) a[n][j]=32768;
			if ((z[n]!=z[j])and(a[n][j]==2)) a[n][j]++;
			if ((z[n]==z[j])and(a[n][j]==1)) a[n][j]--;
			a[j][n]=a[n][j];
        }
	}
	 l=1; r=2;
	 dl[l]=1; f[1]=0;
	 cout<<l<<'~'<<r<<"   "<<dl[l];
	 for (int i=2;i<=n;i++) f[i]=f[1]+a[1][i];
	 while (l<r)
	 {
	 	cin>>k;
	 	cout<<l<<'~'<<r<<"   "<<a[dl[l]][2]+f[dl[l]]<<"   "<<f[2]<<endl;
	 	for (int i=1;i<=n;i++)
	 	  if (a[dl[l]][i]<=3)
	 	    if (a[dl[l]][i]+f[dl[l]]<=f[i])
		 {
		 	  cout<<"ÔËÐÐ"<<i<<endl; 
	 	      f[i]=a[dl[l]][i]+f[dl[l]];
	 	      dl[r]=i;
	 	 }
	 	 l++;
	 }
	 if (f[bj]>32000) cout<<-1;
	 else cout<<f[bj];
     fclose(stdin); fclose(stdout);
     return 0;
}
