#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;
int t[8]={1,10,100,1000,100000,1000000,10000000,100000000};
int wz[8],v;
int n,q,b,c;
int x[1010];
int y[1010];
int u,u2;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    	scanf("%d",&x[i]);
    
    sort(x+1,x+n+1);
    for(int i=1;i<=q;i++)
    {
	    scanf("%d%d",&b,&c);
    	for(int j=1;j<=n;j++)
    	{
		    u=0;u2=0;
	
    		if(x[j]%t[b]!=c%t[b])
                u=1;
    		if(u==0) {
    			cout<<x[j]<<endl;
    			break;}
    	}
		if(u==1) {cout<<-1<<endl;}
    }
    
	return 0;
}

