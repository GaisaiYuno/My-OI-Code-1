#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c,ans=0;
	cin>>a>>b>>c;
	a=a*0.2;
	b=b*0.3;
	c=c*0.5;
	if(b!=0)b++;
	ans=a+b+c;
	cout<<ans;
	return 0;
}
