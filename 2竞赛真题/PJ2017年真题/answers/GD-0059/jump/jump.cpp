#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
    int n,d,m;
    cin>>n>>d>>m;
    int sum=0;
    for(int i=1;i<=n;i++)
    {
    	int a,b;
    	cin>>a>>b;
    	if(b>0) sum+=b;
    }
    if(sum<m) cout<<-1;
    else cout<<2;
	return 0;
}
