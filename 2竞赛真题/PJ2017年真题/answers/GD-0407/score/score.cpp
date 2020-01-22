#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
int a,b,c,s=0;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	s=s+a/10*2;
	s=s+b/10*3;
	s=s+c/10*5;
	cout<<s;
	return 0;
} 
