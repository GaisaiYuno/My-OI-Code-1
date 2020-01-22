#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <fstream>
using namespace std;
int a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	cout<<a*0.2+b*0.3+c*0.5;
	return 0;
}
