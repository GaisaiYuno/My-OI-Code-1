#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;

int a,b,c,ans;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	ans=a/10*2;
	ans+=b/10*3;
	ans+=c/10*5;
	cout<<ans;
	return 0;
}
