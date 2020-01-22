#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
int a,b,c;
int ans=0;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	ans=ans+a/10*2;
	ans=ans+b/10*3;
	ans=ans+c/2;
	cout<<ans;
	return 0;
}
