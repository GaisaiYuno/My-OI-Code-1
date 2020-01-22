#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int n,Q,len;
string st[1005],s;

bool cmp(string a,string b)
{
  if (a.size()!=b.size()) return a.size()<b.size();
  return a<b;
}

int main()
{
  freopen("librarian.in","r",stdin);
  freopen("librarian.out","w",stdout);
  
  cin>>n>>Q;getchar();
  for (int i=1;i<=n;i++) cin>>st[i];
  sort(st+1,st+1+n,cmp);
  
  while (Q--)
  {
  	bool v=false;
    cin>>len>>s;
    for (int i=1;i<=n;i++)
    {
      if (len>st[i].size()) continue;
      
      bool f=false;
      
      for (int j=0,k=st[i].size()-len;j<len;j++,k++)
        if (s[j]!=st[i][k]) {f=true;break;}
      
      if (!f) {cout<<st[i]<<endl;v=true;break;}
    }
    
    if (!v) cout<<-1<<endl;
  }
  return 0;
}

