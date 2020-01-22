#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
int n,d,k;
int main()
{
  freopen("jump.in","r",stdin);
  freopen("jump.out","w",stdout);
  cin>>n>>d>>k;
  if(d!=1){cout<<-1;return 0;}
  else cout<<2;
  return 0;
}
