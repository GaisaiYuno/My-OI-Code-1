#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a,b,c,sum;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	sum=(a/10*2)+(b/10*3)+(c/10*5);
	cout<<sum;
	return 0;
}
