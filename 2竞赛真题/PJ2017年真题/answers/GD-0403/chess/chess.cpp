#include <iostream>
#include  <cstdio>
using namespace std;
int i,j,n,m,c[101][101],ji[101][101],l1,l2,c1,o1,o2;
bool d,p1,p2;
void zuo()
{
		if (c[i][j]==c[i][j-1])			{				l1=ji[i][j-1];	p1=true;		}
		if (c[i][j]==1&&c[i][j-1]==-4)  
		{
		 l1=ji[i][j-1];	p1=true;
		}
		if (c[i][j]==0&&c[i][j-1]==-3) 
		{
			l1=ji[i][j-1];p1=true;
		} 	
		if (c[i][j]==1&&c[i][j-1]==-3)  
		{
			l1=ji[i][j-1]+1;p1=true;
		}
		if (c[i][j]==0&&c[i][j-1]==-4)  
		{
			l1=ji[i][j-1]+1;p1=true;
		}
	    if ( (c[i][j]==0&&c[i][j-1]==1)||(c[i][j]==1&&c[i][j-1]==0) )
		{
			l1=ji[i][j-1]+1;p1=true;
		} 
}
void shang()
{
		if (c[i][j]==c[i-1][j]&&ji[i-1][j]!=-1)			{				l2=ji[i-1][j]; p2=true;			}
		if (c[i][j]==1&&c[i-1][j]==-4)  
		{
			l2=ji[i-1][j];p2=true;	
		}
		if (c[i][j]==0&&c[i-1][j]==-3)  
		{
			l2=ji[i-1][j];	p2=true;	
		}
		if (c[i][j]==1&&c[i-1][j]==-3)  
		{
			l2=ji[i-1][j]+1;p2=true;	
		}
		if (c[i][j]==0&&c[i-1][j]==-4)  
		{
			l2=ji[i-1][j]+1;p2=true;	
		}
	    if ( (c[i][j]==0&&c[i-1][j]==1)||(c[i][j]==1&&c[i-1][j]==0) )
		{
			l2=ji[i-1][j]+1;p2=true;	
		}
}
//-3表示伪红色.-4表示伪黄色. 1是黄色,0是红色. 
int main()
{
	freopen ("chess.in","r",stdin);
	freopen ("chess.out","w",stdout);
	cin>>n;
	cin>>m;
	memset(c,-1,sizeof(c));
	memset(ji,-1,sizeof(ji));
	for (i=1;i<=m;i++)
	{
		cin>>l1>>l2>>c1;
		c[l1][l2]=c1;
	}
	ji[1][1]=0;
	for (i=2;i<=n;i++)
	{
		if (c[1][i]!=-1)
		{
			if (c[1][i-1]==c[1][i])			{				ji[1][i]=ji[1][i-1];			}
			if (c[1][i-1]!=c[1][i])            ji[1][i]=ji[1][i-1]+1;
		}
		else 
		{
			if ( c[1][i-1]==1||c[1][i-1]==0)
			{
				ji[1][i]=ji[1][i-1]+2;
				if (c[1][i-1]==1)				c[1][i]=-4;
				else c[1][i]=-3;
			}
		}
	}
		for (i=2;i<=n;i++)
	{
		if (c[i][1]!=-1)
		{
			if (c[i-1][1]==c[i][1])			{				ji[i][1]=ji[i-1][i];			}
		    if (c[i-1][1]!=c[i][1])            ji[i][1]=ji[i-1][1]+1;
		}
		else 
		{
		    if (c[i-1][1]==1||c[i-1][1]==0)
			{
				ji[i][1]=ji[i-1][1]+2;
				if (c[i-1][1]==1)				c[i][1]=-4;
				else c[i][1]=-3;
			}
		}
	}
	
	for (i=2;i<=n;i++)
	{
		for (j=2;j<=n;j++)
		{
			d=false;l1=0;l2=0;o1=0;o2=0;p1=false;p2=false;
			if (c[i][j]!=-1)
			{
				zuo();
				shang();
			}
			if (c[i][j]==-1)
			{
				if (c[i][j-1]==0)
				{					l1=ji[i][j-1]+2;					o1=-3;		p1=true;		}
			    if (c[i][j-1]==1)
				{					l1=ji[i][j-1]+2;					o1=-4;		p1=true;			}
				 
				if (c[i-1][j]==0)
				{					l2=ji[i-1][j]+2;					o2=-3;		p2=true;			}
			    if (c[i-1][j]==1)
				{					l2=ji[i-1][j]+2;					o2=-4;		p2=true;			}
				d=true;
			}
			if (d)
			{
				if (l1==l2&&l1==0)				ji[i][j]=-1;
				if (l1==l2&&l2!=0)              ji[i][j]=l2;
				if (l1<l2&&p1&&p2)
				{
					ji[i][j]=l1;
					c[i][j]=o1;
				} 
				if (l1>l2&&p1&&p2)
				{
					ji[i][j]=l2;
					c[i][j]=o2;
				}
				if (p1&&p2==false)
				{
					ji[i][j]=l1;
					c[i][j]=o1;
				}
				if (p2&&p1==false)
				{
					ji[i][j]=l2;
					c[i][j]=o2;
				}
			}
			else 
			{
				if (l1==l2&&l1==0) ji[i][j]=-1;
				if (l1<l2&&p1&&p2) ji[i][j]=l1;
				if (l1>l2&&p1&&p2) ji[i][j]=l2;
				if (p1&&p2==false) ji[i][j]=l1;
				if (p2&&p2==false) ji[i][j]=l2;
				if (l1==l2&&l2!=0) ji[i][j]=l2;
			}
		}
	}
	
	cout<<ji[n][n];
	return 0;
}
