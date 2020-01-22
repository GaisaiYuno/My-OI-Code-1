#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
using namespace std;
int n,q;
struct node
{
	int v;
	int len;
}a[1010];
bool cmp(node x,node y)
{
	return x.v<y.v;
}
int num(int x)
{
	int k=x;
	int c=0;
	while(k!=0)
	{
		k/=10;
		c++;
	}
	return c;
}
bool check(int x,int y,int v)
{
	int k=x,kk=x;
	int sum=0,cheng=1;
	while(k!=0)
	{
		cheng*=10;
		k--;
	}
	if(v%cheng==y) return true;
	else return false;
}
int main()
{

	 freopen("librarian.in","r",stdin);
	 freopen("librarian.out","w",stdout);
	 scanf("%d %d",&n,&q);
	 for(int i=1;i<=n;i++)
	 {
       scanf("%d",&a[i].v);
       a[i].len=num(a[i].v);
       
     }
	 sort(a+1,a+n+1,cmp);
	 for(int i=1;i<=q;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        for(int j=1;j<=n;j++)
        {
        	if(check(x,y,a[j].v)) {cout<<a[j].v<<endl;break;}
        	if(j==n) cout<<-1<<endl;
        }
	
	}
	 return 0;
}

