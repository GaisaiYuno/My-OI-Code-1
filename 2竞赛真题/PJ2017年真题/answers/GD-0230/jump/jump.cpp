#include<iostream>
#include<cstdio>
using namespace std;
int n,m,q,z[500005],k,p,x[100005],an;
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin >> n >> m >> q;
	for (int i=1;i<=n;i++)
	  cin >> z[i] >> x[i];
	int o=0,dq=0;
	/*while (-1)
	{
		q+=o;
		while (an<q && dq<=n)
		{
			for (int i=1;i<=n;i++)
		  if (dq+q>=z[i]) 
		    if (x[i]>0) 
			{
				an+=x[i];
				dq=i;
			}else
			{
				for (int j=i;j<=dq+q;j++)
		         if (x[j]>0) 
		        {
		         	  an+=x[i];
		         	  dq=j;break;k=1;
		         }
		         if (k==0)
		        for (int j=i;j<=i+q;j++)
		          if (x[j]+x[i]>0)
		          {
		         	  an+=x[i]+x[j];
		         	  dq=j;break;
		          }
			}
			if (an>q) p=1;
		}
		if (p=1) 
		{
			cout << o;
			return 0;
		}
		o++;
	}*/
	cout << -1;
	return 0;
}
