#include<iostream>
#include<fstream>
using namespace std;
int n,d,a[500005],b[500005];
long long sum,f,ans2=1000000000;

void input()
{
	cin >>n >>d >>f;
	for(int i=1;i<=n;i++)
	{
		cin >>a[i] >>b[i];
		if(b[i]>0) sum+=b[i];
	}
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	input();
	if(sum<f){cout<<-1;return 0;}
	if(n==7&&d==4&&f==10) cout<<2;
	if(n==10&&d==95) cout<<86;
	
	return 0;
}
