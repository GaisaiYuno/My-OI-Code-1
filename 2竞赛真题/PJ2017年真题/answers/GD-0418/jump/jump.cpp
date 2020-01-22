#include<cstdio>
#include<iostream>
using namespace std;
int a[500001];
int n,d,k;
int best=999999999;
int pq[4]={0,0,1,-1};
int last;
int dfs(int x,int total,int coin,int ab)
{
	int i;
	if(x>=last)
	 return 0;
	if(ab<=0||ab>=n)
	 return 0;
	if(total>=k)
	 {
	 	if(best>coin)
	 	 best=coin;
        return 0;
	 }
	if(coin>best)
	 return 0;
	
	for(i=1;i<=3;i++)
	 {
	    int j=ab+pq[i];
	    int go=j+x;
	    if(i==1)
		dfs(go,total+a[go],coin,j);
		else dfs(go,total+a[go],coin+1,j);
	 }
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	int x,y;
	cin>>n>>d>>k;
	int i,j;
	int max=0;
	int sign=0;
	for(i=1;i<=n;i++)
	 {
	 cin>>x>>y;
	 a[x]=y;
	 if(y>=0)
	 max+=y;
	 if(i==1)
	  sign=x;
	 if(i==n)
	  last=x;
	 if(k==1&&y>=1)
	  {
	  	cout<<x-1;
	  	return 0;
	  }
     }
	if(max+a[sign]<k)
	 {
	 	cout<<-1;
	 	return 0;
	 }
	dfs(1,a[1],0,d);
	if(best!=999999999)
	cout<<best;
	 else cout<<-1;
	 return 0;
}
