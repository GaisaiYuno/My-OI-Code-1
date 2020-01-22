#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    double a,b,c,d;
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	d=a*0.2+b*0.3+c*0.5;
	cout<<d;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
