#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
struct data{int num;int fen;};
data a[1001];
int n,m,i,j,k,t,o,p;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>m>>k;
	  for(int i=1;i<=n;i++)
	  {
	    cin>>a[i].num>>a[i].fen;
	    if(a[i].fen>0)
		t+=a[i].fen;
	  }p=a[1].fen;
	  if(t<k)
	  {
      cout<<-1;return 0;
      }
      for(int i=1;i<=n;i++)
      {
      	if(o<m&&a[i+1].num-a[i].num<=o+m&&a[i+1].fen>0)
      	{
      	  o+=abs(a[i+1].num-a[i].num-m);
      	  p+=a[i+1].fen;
        }else
        if(a[i+1].fen>0)
        p+=a[i+1].fen;
        if(p>=k){cout<<o;return 0;}
      }
}
