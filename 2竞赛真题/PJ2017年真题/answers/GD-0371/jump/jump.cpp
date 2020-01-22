#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,d,k,i,c[501],a[501],g,ans=0;
int main()
{
    freopen("jump.in","r",stdin);
    freopen("jump.out","w",stdout);
    cin>>n>>d>>k;
    for(i=1;i<=n;i++)
    {
    	cin>>a[i]>>g;
    	if(g>=0)
    	ans+=g;
    	c[i]=a[i]-a[i-1];
    }
    sort(c+1,c+n+1);
    if(ans<k){cout<<-1;return 0;
    }
    else cout<<c[n];
    return 0;
}

