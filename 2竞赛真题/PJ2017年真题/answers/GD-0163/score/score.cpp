#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	
	cin>>a>>b>>c;
	cout<<0.2*a+0.3*b+0.5*c;
	return 0;
}
