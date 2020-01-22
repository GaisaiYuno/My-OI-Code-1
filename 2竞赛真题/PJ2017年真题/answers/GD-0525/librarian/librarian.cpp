#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;
int n,q,_book[2000],_wei[2000],mu[2000],ans[2000],o=1;
bool p=true;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
    cin>>n;
    cin>>q;
    for(int i=1;i<=n;i++)
    scanf("%d",&_book[i]);	
     sort(_book+1,_book+1+n);
    for(int i=1;i<=q;i++)
    {
       p=true;
	   scanf("%d",&_wei[i]);
	   scanf("%d",&mu[i]);
    	int u= pow(10,_wei[i]);
	   for(int j=1;j<=n;j++)
    	if(_book[j]>=mu[i]&&(_book[j]%u==mu[i]))
    	{
    		p=false;
    		ans[o++]=_book[j];
			break;
    	}
    	if(p) ans[o++]=-1;
    }
    for(int i=1;i<o;i++)
    printf("%d\n",ans[i]);
	return 0;
}
