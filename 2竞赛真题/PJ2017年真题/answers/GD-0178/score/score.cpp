//score
//hrf
#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	int a,b,c;
	cin>>a>>b>>c;
	float ans=0;
	ans+=a*0.2;ans+=b*0.3;ans+=c*0.5;
	cout<<(int)ans;
	return 0;
}
