#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstdlib>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int a,b,c;double s;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	s=a*0.2+b*0.3+c*0.5;
	cout<<s;
	return 0;
}
