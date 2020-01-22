#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	cout<<a*0.2+b*0.3+c*0.5;
	return 0;
}

