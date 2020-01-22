#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	int ans;
	cin>>a>>b>>c;
	a=a/10;
	b=b/10;
	c=c/10;
	ans=2*a+3*b+5*c;
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
