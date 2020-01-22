#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int a[1100],b[1100][5],_min,s[100];
int n,q;
int change(int x,int y)
{
   int k=0;int ans=0;
   while (x!=0 && k<y)
     {
     	k++;
     	s[k]=x%10;
     	x=x/10;
     }	
   for (int d=k; d>=1; d--)
     ans=ans*10+s[d];
   return ans;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
   cin>>n>>q;
   for (int i=1; i<=n; i++) scanf("%d",&a[i]);
   for (int i=1;  i<=q; i++) scanf("%d %d",&b[i][0],&b[i][1]);
   for (int i=1; i<=q; i++)
    {
      _min=2147483645;
      for (int j=1; j<=n; j++)
     	if (change(a[j],b[i][0])==b[i][1]) _min=min(_min,a[j]);
      if (_min!=2147483645) cout<<_min<<endl;
        else cout<<-1<<endl;
    }
    return 0;  
   
}
