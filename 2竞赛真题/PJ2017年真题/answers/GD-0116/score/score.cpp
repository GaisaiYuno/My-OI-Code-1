#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;
int a,b,c,tot;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a/=10;
	b/=10;c/=10;
	tot=a*2+b*3+c*5;
	cout<<tot<<endl;
	return 0;
	fclose(stdin);
	fclose(stdout);
}
