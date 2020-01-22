#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	
	cin>>a>>b>>c;
	a=a/5;
	b=b/10*3;
	c=c/2;
	cout<<(a+b+c)<<endl;
	return 0;
}
