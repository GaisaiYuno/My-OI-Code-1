#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	cout<<trunc(a*0.2+b*0.3+c*0.5);
	return 0;
}
