#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<iostream>
using namespace std;
int a,b,c;
int main()
{
	freopen("score.in","r",stdin);freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	cout<<(a*2+b*3+c*5)/10;
	return 0;
}
