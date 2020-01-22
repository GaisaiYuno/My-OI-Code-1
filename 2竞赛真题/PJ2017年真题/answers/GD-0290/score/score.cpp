#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
using namespace std;
int a,b,c,p;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	p=(a/10)*2+(b/10)*3+(c/10)*5;
	cout<<p;
	return 0;
}

