#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

struct block
{
	int x;
	int s;
}b[510];

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","r",stdout);
	int n,d,k,i,j,ans=0;
	cin>>n>>d>>k;
	for(i=1;i<=n;i++)
		cin>>b[i].x>>b[i].s;
	for(i=1;i<=n;i++)
		if(b[i].s>0)ans+=b[i].s;
	if(ans<k)
	{
		cout<<"-1";
		fclose(stdint);fclose(stdout);
		return 0;
	}
	fclose(stdint);fclose(stdout);
	return 0;
}
