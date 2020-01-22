#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	int a1=a*2/10;
	int b2=b*3/10;
	int c1=c*5/10;
    c=a1+b2+c1;
	cout <<c;
	return 0;
}

