#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c,sum;cin>>a>>b>>c;
	sum=a*2/10+b*3/10+c/2;
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
