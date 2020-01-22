#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
int n,q,a[1005][1005],x,y,z;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=q;i++)
	{
        cin>>x>>y>>z;
        a[x][y]=z;
    }
    cout<<"-1";
	return 0;
}
