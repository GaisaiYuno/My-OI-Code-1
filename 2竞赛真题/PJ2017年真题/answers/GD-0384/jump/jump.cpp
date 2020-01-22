#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int n,d,T,x[15],s[15],ans;
bool p[15];

void find_(int k)
{
  if (k>n)
  {
  	int sum=0,g,g_max=0,L=0;
    for (int i=1;i<=n;i++)
      if (p[i]) sum+=s[i];
    if (sum<T) return;
    
    for (int i=1;i<=n;i++)
      if (p[i])
      {
      	g=0;
      	if (i-L==1) g=0; else
      	if (i-L==2) g=1; else
          g=s[i-1]-s[L+1];
      	
		g_max=max(g_max,g);
	    
		L=i;
	  }
	
	ans=min(ans,abs(d-g_max-1));
    return;
  }
  
  p[k]=true;
  find_(k+1);
  p[k]=false;
  find_(k+1);
}

int main()
{
  freopen("jump.in","r",stdin);
  freopen("jump.out","w",stdout);
  
  cin>>n>>d>>T;
  
  if (n>25) {cout<<-1;return 0;}
  
  for (int i=1;i<=n;i++) cin>>x[i]>>s[i];
  
  ans=2147483640;
  find_(1);
  if (ans==2147483640) cout<<-1; else cout<<ans;
  return 0;
}
