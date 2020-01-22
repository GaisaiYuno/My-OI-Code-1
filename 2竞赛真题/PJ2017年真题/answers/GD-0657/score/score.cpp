#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	freopen ("score.in","r",stdin);
	freopen ("score.out","w",stdout);
	double a,b,c;
	cin>>a>>b>>c;
	cout<<a*0.2+b*0.3+c*0.5;
	return 0;
}
