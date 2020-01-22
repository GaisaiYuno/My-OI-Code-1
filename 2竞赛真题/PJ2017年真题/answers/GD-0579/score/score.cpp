#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
int a,b,c,s=0;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	a=a/10*2;b=b/10*3;c=c/10*5;
	s+=a+b+c;
	cout<<s<<endl;
}
