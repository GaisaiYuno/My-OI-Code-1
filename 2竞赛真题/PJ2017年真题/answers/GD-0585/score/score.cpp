#include<iostream>
#include<cstdlib>
#include<sstream>
#include<cstring>
#include<string>
#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	cout<<a/10*2+b/10*3+c/10*5;
	return 0;
}
