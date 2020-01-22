#include<iostream>
using namespace std;
int x,y,z,z1,y1,x1;
int main()
{
	freopen("score.in","r",stdin);
	freopen("score.out","w",stdout);
	cin>>x>>y>>z;
	x1=x*20/100;
	y1=y*30/100;
	z1=z*50/100;
	cout<<x1+y1+z1;
	return 0;
}
