#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	int a,b,c,sum;
	double sum1;
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	sum1=a*0.2+b*0.3+c*0.5;
	sum=(int)sum1;
	cout<<sum;
	return 0;
	fclose(stdin);
    fclose(stdout);
}
