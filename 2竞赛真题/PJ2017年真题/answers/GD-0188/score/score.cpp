#include<bits/stdc++.h>
using namespace std;
double a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a=0.2*a;
	b=0.3*b;
	c=0.5*c;
	cout<<(int)a+b+c;
}
