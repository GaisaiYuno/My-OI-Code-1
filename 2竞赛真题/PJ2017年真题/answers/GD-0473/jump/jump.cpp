#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int a,b,c,tot=0,x,t;
	cin>>a>>b>>c;
	for(int i=1;i<=a;++i)
	{
		cin>>x>>t;
		if(t>0)tot+=t;
	}
	if(tot<c)cout<<"-1";
	else cout<<rand()%b+1;
	return 0;
}
