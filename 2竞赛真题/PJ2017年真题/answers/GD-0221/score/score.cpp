#include<bits/stdc++.h>
using namespace std;
int a,b,c;
double t;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	t=a*0.2+b*0.3+c*0.5;
	cout<<floor(t);
}
