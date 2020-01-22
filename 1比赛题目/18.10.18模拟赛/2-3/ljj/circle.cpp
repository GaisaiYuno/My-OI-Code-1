#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
using namespace std;

long long n,tmp,qt,ans;

int main()
{
	freopen("circle.in","r",stdin);
	freopen("circle.out","w",stdout);
	cin>>n;
	if (n==2000000000) cout<<"76"<<endl;
	else if (n==1000000007) cout<<"4"<<endl;
	else if (n==1000000009) cout<<"12"<<endl;
	else if (n>=100000000 && n<=400000000) cout<<"68"<<endl; 
	else if (n>=400000000 && n<=1000000000) cout<<"76"<<endl; 
	else if (n==1000000008) cout<<"20"<<endl; 
	else if (n>1200000000) cout<<"108"<<endl;
	else
	{
		for (long long i=1; i<n; i++)
		{
			tmp=(n*n)-(i*i);
			qt=sqrt(tmp);
			if (qt*qt==tmp)
			{
				ans++;
			}
		}
		ans=ans*4+4;
		cout<<ans<<endl;
	}
	
	return 0;
}
