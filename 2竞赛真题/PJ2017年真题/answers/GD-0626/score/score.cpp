#include<iostream>
#include<cmath>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
using namespace std;
double ans=0,a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	ans+=a*0.2+b*0.3+c*0.5;
	cout<<ans;
	return 0;
}
