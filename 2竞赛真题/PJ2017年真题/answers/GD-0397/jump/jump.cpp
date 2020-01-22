#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long n,d,k,i,a,b,m,l[100005],z,t;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a>>b;
		if(b>0&&z<k) 
	    {
    	    t++;
    	    l[t]=a;
    	    if(m<abs(a-l[t-1])) m=abs(a-l[t-1]);
    	    z+=b;
		}
	}
	if(z<k)
	{
		cout<<-1;
	}else
	{
		cout<<m-d;
	}
	return 0;
}

