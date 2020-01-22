#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
double a,b,c,sum;
int ans;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	sum=a*0.2+b*0.3+c*0.5;
	ans=sum;
	cout<<ans;
	return 0;
}
