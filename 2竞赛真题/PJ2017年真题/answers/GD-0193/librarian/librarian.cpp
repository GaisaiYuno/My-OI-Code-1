#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<vector>
#include<queue>
using namespace std;

int n,q,s[1010],inf=10000010,a,w;

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    
    scanf("%d%d",&n,&q);
    
    for (int i=1; i<=n; i++)
      scanf("%d",&s[i]);
    
    for (int i=1; i<=q; i++)
      {
      	scanf("%d%d",&w,&a);
      	int cnt=1,pr=inf;
		for (; w!=0; w--) cnt*=10;
		for (int j=1; j<=n; j++)
		  if (s[j]%cnt==a) pr=min(pr,s[j]);
		if (pr==inf) cout<<-1<<endl; else cout<<pr<<endl; 
      }
    
	return 0;
}

