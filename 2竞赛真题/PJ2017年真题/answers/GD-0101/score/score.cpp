#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c,ans=0;
int main()
{
	  freopen("score.in","r",stdin);
	  freopen("score.out","w",stdout);
	  cin>>a>>b>>c;
	  a=a*2/10;
	  b=b*3/10;
	  c=c*5/10;
	  ans=a+b+c;
	  cout<<ans;
	  return 0;
}
