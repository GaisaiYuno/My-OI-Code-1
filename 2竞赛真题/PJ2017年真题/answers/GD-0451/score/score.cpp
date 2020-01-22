#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	a=(a/10)*2;
	b=(b/10)*3;
	c=c/2;
	cout<<a+b+c<<endl;
	return 0;
}
