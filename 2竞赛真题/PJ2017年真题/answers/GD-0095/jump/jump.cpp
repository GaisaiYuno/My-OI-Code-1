#include<iostream>
#include<fstream>
using namespace std;
int n,p,a[1005][9],b[1005],c[1005];
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>c[1]>>c[2];
	for(int i=1;i<=n;i++)
	{
		cin>>c[i+9]>>p;
		if(p>0)
		c[3]=c[3]+p;
	}
	if(c[3]<c[2])
	cout<<-1;
	else
	cout<<2;
	return 0;
	fclose(stdin);fclose(stdout);
}
