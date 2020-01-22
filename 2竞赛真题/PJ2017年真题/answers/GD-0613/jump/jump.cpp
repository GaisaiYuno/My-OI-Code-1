#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
int k,d,n,x,ans,g,o,times[10000000],s[10000000];
void jump(int walk,int sum,int was)
{
    if (sum>=k) 
	{
		ans=min(ans,was);
		return;
	} else if (walk>=g+d) return;
	for (int i=o;i<=d+g;i++) 
	  if (times[walk+i]!=0&&i<ans) 
	    jump(walk+i,sum+s[walk+i],max(was,i));
}

int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	if (n<=10)
	{
	ans=2000000000;
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		scanf("%d",&s[x]);
		times[x]++;
		g=max(g,x);
	}
	g-=d;
	if (g<d) o=d-g; else o=1;
	jump(0,0,0);
	if (ans==2000000000) cout<<-1; else cout<<abs(ans-d+1);
	} else cout<<-1;
	
	return 0;
}
