#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,q,b[1005];string a[1005],c[1005];
int main()
{
  freopen("librarian.in","r",stdin);
  freopen("librarian.out","w",stdout);
  cin>>n>>q;
  for(int i=1;i<=n;i++)
  {
    cin>>a[i];
  }
  for(int i=1;i<=q;i++)
  {
    cin>>b[i]>>c[i];
  }
  for(int i=1;i<=q;i++)
  {
  	int mi=100000000,z=-1;
    for(int j=1;j<=n;j++)
    {
      int w=-1;
	  if(a[j].size()>=b[i])
	  {
	    for(int k=a[j].size()-b[i];k<a[j].size();k++)
	    {
		  w++;
		  if(a[j][k]!=c[i][w]) {w=-1;break;}
		}
	  }
	  if(w!=-1)
	  {
	  	int p=0;
	    for(int k=0;k<a[j].size();k++)
	    {
		  p=p*10+(a[j][k]-48);
		}
		mi=min(mi,p);
		z=0;
	  }
	}
	if(z!=-1) cout<<mi<<endl;
	else cout<<-1<<endl;
  }
  return 0;
}
