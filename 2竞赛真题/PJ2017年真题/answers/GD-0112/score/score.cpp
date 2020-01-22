#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);	
	cin>>a>>b>>c;
	cout<<a*0.2+b*0.3+c/2;
	return 0;
}
