#include<iostream>
#include<cstdio>
#include<cmath>
#include<fstream>
#include<algorithm>
#include<string>
#include<cstring>
#include<iomanip> 
using namespace std;
int a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	cout<<a/10*2+b/10*3+c/10*5;
	return 0;
}
