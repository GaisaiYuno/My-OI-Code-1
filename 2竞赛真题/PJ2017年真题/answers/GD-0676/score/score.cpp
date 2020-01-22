#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
double a,b,c,ans;
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	ans=a*0.2+b*0.3+c*0.5;
	cout<<ans;
	return 0;
}
