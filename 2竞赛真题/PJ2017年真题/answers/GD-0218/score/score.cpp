#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
using namespace std;
int a,b,c,d;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	d=a/10*2+b/10*3+c/10*5;
	cout<<d<<endl;
	return 0;
}
