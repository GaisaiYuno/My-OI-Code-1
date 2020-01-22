#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,n,sum=0,x,y,z,c=0,d=0,k=1,a[101][101];
	bool f1=0,f2=0,f3=0;
	cin>>m>>n;
	for(int i=0;i<=m+1;i++)
	for(int j=0;j<=m+1;j++)
	a[i][j]=-1;
	for(int i=1;i<=n;i++)
	{
		cin>>x>>y>>z;
		a[x][y]=z;
	}
	while(k!=m)
	{
		k++;
		d=c;
		for(int i=m;i>=k;m--)
		for(int j=k;j<=m;j++)
		{
			if(f2==f1||d-c!=k) f3=1;
			f1=f2;
			if((a[i][j]-a[i][j-1]<a[i][j]-a[i-1][j])&&(a[i][j-1]!=-1)&&(a[i-1][j]!=-1))
			a[i][j]-=a[i][j-1];
			else
			{
				if((a[i][j-1]==a[i-1][j])&&(a[i][j]!=-1)&&(a[i][j-1]!=-1)&&(a[i-1][j]!=-1))
				{
					a[i][j]-=a[i-1][j];
				}
				else
				{
					if((a[i][j]==-1)&&(a[i][j-1]==-1)&&(a[i-1][j]==-1))
					{
						f3=1;
						break;
					}
					if((a[i][j-1]==-1)&&(a[i-1][j]==-1))
					{
						
						if(f2==0) f2=1;
						if(f2==1) f2=0;
						c+=k;
					}
				}
			}
		}
	}
	c=0;
	d=0;
	while(k!=1)
	{
		k--;
		d=c;
		for(int i=m;i>=k;m--)
		for(int j=k;j<=m;j++)
		{
			if(f2==f1||d-c!=k) f3=1;
			f1=f2;
			if((a[i][j]-a[i+1][j]<a[i][j]-a[i-1][j+1])&&(a[i+1][j]!=-1)&&(a[i][j+1]!=-1))
			a[i][j]-=a[i+1][j];
			else
			{
				if((a[i+1][j]==a[i][j+1])&&(a[i][j]!=-1)&&(a[i+1][j]!=-1)&&(a[i][j+1]!=-1))
				{
					a[i][j]-=a[i+1][j];
				}
				else
				{
					if((a[i][j]==-1)&&(a[i+1][j]==-1)&&(a[i][j+1]==-1))
					{
						f3=1;
						break;
					}
					if((a[i+1][j]==-1)&&(a[i][j+1]==-1))
					{
						if(f2==0) f2=1;
						if(f2==1) f2=0;
						c+=k;
					}
				}
			}
		}
	}
	sum=a[1][1]+a[m][m];
	if(f3==0) cout<<sum<<endl;
	else cout<<-1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
