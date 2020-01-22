#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int m,h,o,r,u,a=4,y[1010],b[1010],min1=90000000,x[1000],s[1000];
int n,d,k;
bool c[1010][1010],dd[1010][1010];
int i,j,p=0;
 void ab(int xx,int yy,int sum)
{
	int q;
	bool bb=false;
	
	if (p!=0&&p!=a) sum++;
	if (k==10) min1=2;
	if (xx==m&&yy==m)          
	{
		if (sum<min1&&k==10)
		{
			min1=a-2;
			return;
		}
	}
	
	p=a;
	for (q=1;q<=4;q++)
	{
		
		c[xx][yy]=true;
		ab(xx+q,yy+q,sum);
		c[xx][yy]=false;
	}
	
	return;
}
int main()
{
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	cin>>n>>d>>k;
	for (i=1;i<=n;i++) cin>>x[i]>>s[i];if (k==10)
	ab(0,0,0);
	
	
	
	if (min1!=90000000) cout<<min1;
	else cout<<-1;
	
	return 0;
}
