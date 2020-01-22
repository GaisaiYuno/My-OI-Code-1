#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n1[1001]={0},q1[1001]={0},q2[1001],a=0,b,c,i,j,k,x,y,t1,t2,n,q,ans[1001]={0};
bool found=false;
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	cin>>n>>q;
	for (i=1;i<=n;i++) scanf("%d",&n1[i]);
	for (i=1;i<=q;i++) scanf("%d%d",&q1[i],&q2[i]);
	sort(n1+1,n1+1+n);
	for (i=1;i<=q;i++)
	{
		found=false;
        for (j=1;j<=n;j++)
        {
        	t1=n1[j];
        	t2=q2[i];
        	for (k=1;k<=q1[i];k++)
        	{
        		x=t1%10;
        		t1/=10;
        		y=t2%10;
        		t2/=10;
        		if (x!=y) break;
        	}
        	if (k==q1[i]+1) 
        	{
        		ans[++a]=n1[j];
        		found=true;
        		break;
        	}
        }
        if(!found) ans[++a]=-1;
	}
	for (i=1;i<=q;i++) printf("%d\n",ans[i]);
	return 0;
}
