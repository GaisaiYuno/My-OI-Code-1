
#include<iostream>
#include<cstdio>
#include<cmath>
#include<sstream>
#include<algorithm>
using namespace std;



int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);

	int n,d,k,s[2000],x[2000],sum=0;
	cin>>n>>d>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>x[i]>>s[i];
		sum+=s[i];
	}
	
	if (sum<k) 
	{
		cout<<-1;
		return 0;
	}
	

}
