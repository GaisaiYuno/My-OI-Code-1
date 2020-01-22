#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
int a,b,c,ans=0;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a=a*20;
	a=a/100;
	b=b*30;
	b=b/100;
	c=c*50;
	c=c/100;
	ans=a+b+c;
	cout<<ans;
	return 0;
}
