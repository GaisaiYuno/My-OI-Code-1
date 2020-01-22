#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,q,c,i,p,k;
int j[1010];
int s[1010],dz[1010];
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	
	cin>>n>>q;
	for(i=1;i<=n;i++)
		cin>>s[i];
	for(i=1;i<=q;i++)
	{
		cin>>j[i];
		cin>>dz[i];
	}
	sort(s,s+n+1);
	
    for(i=1;i<=q;i++)
    {
    	for(p=1;p<=n;p++)
    	{
    		int S=s[p];
    		int m=j[i];
    		int Q=dz[i];
    		while(m--)
    		{
    			if(S%10!=Q%10)
    				break;
    			S/=10; Q/=10;
    		}
    		if(m==-1)
    		{
    			cout<<s[p]<<endl;
    			break;
    		}
    	}
    	if(p>n)
    		cout<<-1<<endl;
    }
	return 0;
}
