#include<iostream>
#include<cstdio>
using namespace std;
int a,b,c,j;
double k;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	k=a*0.2+b*0.3+c*0.5;
	j=int(k);
	cout<<j;
	return 0;
}
