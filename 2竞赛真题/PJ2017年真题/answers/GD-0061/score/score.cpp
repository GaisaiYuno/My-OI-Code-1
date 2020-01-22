#include<iostream>
#include<fstream>
using namespace std;
int a,b,c;
double ans;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
  cin>>a>>b>>c;
  ans=a*0.2+b*0.3+c*0.5;
  cout<<ans<<endl;
	return 0;
}
