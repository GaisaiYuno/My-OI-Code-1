#include<algorithm>
#include<iostream>
#include<fstream>
#include<cstdio>
#include<cmath>
using namespace std;
long long a,b,c;
int main()
{
  freopen("score.in","r",stdin);
  freopen("score.out","w",stdout);
  cin>>a>>b>>c;
  cout<<a/5+b/10*3+c/2;
  return 0;
}
