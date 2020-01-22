#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	cout<<a/5+b*3/10+c/2;
	return 0;
}
