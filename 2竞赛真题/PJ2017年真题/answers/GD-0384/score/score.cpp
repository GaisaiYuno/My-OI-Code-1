#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int a,b,c;

int main()
{
  freopen("score.in","r",stdin);
  freopen("score.out","w",stdout);
  
  cin>>a>>b>>c;
  cout<<a*2/10+b*3/10+c*5/10;
  return 0;
}
