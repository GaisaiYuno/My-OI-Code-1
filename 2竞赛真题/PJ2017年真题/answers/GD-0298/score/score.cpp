#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main(void)
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	double a,b,c,n;
	cin>>a>>b>>c;
	n=a*0.2+b*0.3+c*0.5;
	cout<<int(n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
