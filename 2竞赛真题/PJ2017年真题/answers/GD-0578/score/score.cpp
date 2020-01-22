#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int a,b,c;
double s;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	scanf("%d %d %d",&a,&b,&c);
	s=a*0.2+b*0.3+c*0.5;
	cout<<s;
	return 0;
}
