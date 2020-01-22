#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	a=a/5;
	b=b/10*3;
	c=c/2;
	cout<<a+b+c;
	fclose(stdin);fclose(stdout);
	return 0;
}
