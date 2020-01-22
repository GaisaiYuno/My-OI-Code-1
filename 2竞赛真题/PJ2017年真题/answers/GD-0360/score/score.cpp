#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,c;
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	cout<<a/10*2+b/10*3+c/10*5;
	return 0;
}
