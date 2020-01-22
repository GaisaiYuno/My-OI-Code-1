#include<iostream>
#include<cstdio>

using namespace std;
long long a,b,c;
long long ans=0;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>a>>b>>c;
	ans=a/10*2+b/10*3+c/10*5;
	cout<<ans<<endl;
	return 0;
}
