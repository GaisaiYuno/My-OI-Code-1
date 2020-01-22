#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[1001][1001],b[1001],c[1001];
int pd(int x)
{
	int k=0;
	while(x>=10)
	{
		k++;
		x/=10;
	}
	return k+1;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,m,l1,weishu=1,maxw=0;
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
	 cin>>b[i];
	 c[i]=b[i];
    }
	sort(b+1,b+m+1);
	sort(c+1,c+m+1); 
	for(int i=1; i<=n; i++)
	{
	 int k=pd(c[i]);
	 maxw=max(maxw,k);
	 for(int j=1; j<=k; j++)
	  weishu*=10;
	 while(k!=0)
	 {
	 	a[k][i]=c[i]%weishu;
		weishu/=10;
	 	k--;
		c[i]%=weishu;	 	
	 } 
    }
	for(int i=1; i<=m; i++)
	 {
	 	int l2,l3,light=0;
	 	cin>>l2>>l3;
	 	for(int j=1; j<=n; j++)
	 	 if(a[l2][j]==l3)
	 	 {
	 	  cout<<b[j]<<endl;
	 	  light=1;
	 	  break;
	     }
	    if(light==0) 
	     cout<<"-1"<<endl;
	    light=0; 
	 }
}
