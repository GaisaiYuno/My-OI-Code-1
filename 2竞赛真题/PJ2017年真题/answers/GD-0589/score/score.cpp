#include<iostream>
#include<cstdio>
#include<cmath>
#include<string>
#include<algorithm>
#include<cstdlib>
using namespace std;
int a,b,c,s;
int main()
{
  freopen("score.in","r",stdin);
  freopen("score.out","w",stdout);
  cin>>a>>b>>c;
  a=a/5;
  b=b/10*3;
  c=c/2;
  s=a+b+c;
  cout<<s;
  return 0;
}
