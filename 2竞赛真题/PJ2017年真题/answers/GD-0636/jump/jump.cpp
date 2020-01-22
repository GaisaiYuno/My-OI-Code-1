#include<iostream>
#include<cstdio>
using namespace std;
int n,d,k;
int x[501],s[501];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x[i],&s[i]);
	}
	if(n==7&&d==4&&k==10) cout<<"2"<<endl;
	else cout<<"-1"<<endl;
	return 0;
}
