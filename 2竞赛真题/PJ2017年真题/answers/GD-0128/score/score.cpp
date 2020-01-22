#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int x,y,z;
	cin>>x>>y>>z;
	cout<<x*0.2+y*0.3+z*0.5;
	return 0;
}
