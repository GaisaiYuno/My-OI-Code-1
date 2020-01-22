#include<iostream>
#include<fstream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int a,b,c;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	int ans=0;
	ans=a/5;
	ans+=b*3/10;
	ans+=c/2;
	cout<<ans;
	return 0;
}

