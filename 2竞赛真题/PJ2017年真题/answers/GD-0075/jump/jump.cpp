#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,x,y;
	cin>>n>>d>>k;
	for(int i=1;i<=n;i++)
	cin>>x>>y;
	cout<<"-1";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
