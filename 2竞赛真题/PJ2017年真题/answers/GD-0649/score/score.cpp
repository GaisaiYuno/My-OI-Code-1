#include<cstdio>
#include<iostream>
using namespace std;
double a,b,c,s;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	s=a*0.2+b*0.3+c*0.5;
	cout<<(long long)s<<endl;
	return 0;
}
