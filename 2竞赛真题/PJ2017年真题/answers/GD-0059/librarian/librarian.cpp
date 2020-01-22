#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
int b[1005];
using namespace std;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++) cin>>b[i];
    sort(b+1,b+n+1);
    for(int i=1;i<=m;i++)
    {
    	int l,a;
    	cin>>l>>a;
    	int s=1;
    	while(l)
    	{
    		s*=10;
    		l--;
    	}
    	int f=0;
    	for(int j=1;j<=n;j++)
    	if(b[j]%s==a)
    	{
    		cout<<b[j]<<endl;
    		f=1;
    		break;
    	}
    	if(f==0) cout<<-1<<endl;
    }
	return 0;
}
