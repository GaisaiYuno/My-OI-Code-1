#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a=0,b=0,c=0,ans=0;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	ans=ceil(a*0.2)+ceil(b*0.3)+ceil(c*0.5);
	cout<<ans;
	return 0;
}
