#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int n,d,k,a,i,b,sum=0;
	cin>>n>>d>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		if(b>0) sum+=b;
	}
	if(sum>k) cout<<"2";
	if(sum<k) cout<<"-1";
	return 0;
}
