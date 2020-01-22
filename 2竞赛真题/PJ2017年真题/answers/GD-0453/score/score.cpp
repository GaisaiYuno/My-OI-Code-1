#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<string>
#include<cstring>
#include<cstdlib>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c,s;
	cin>>a>>b>>c;
	s=(a*20/100)+(b*30/100)+(c*50/100);
	cout<<s;
	return 0;
}
