#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<string>
using namespace std;
int n,m,i,j;
int a[1005][12];
int s[1005];
int temp;
int x,y;
bool cmp(const int& xx,const int& yy)
{
	return xx<yy;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	for(i=0;i<1005;i++)
	{
		for(j=0;j<12;j++)
		{
			a[i][j]=-1;
		}
	}
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&s[i]);
	}
	sort(s+1,s+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		temp=1;
		j=0;
		while(1)
		{
			j++;
			if(temp>s[i]) break;
			temp*=10;
			a[i][j]=s[i]%temp;
		}
	}
	bool tf=false;
	for(i=1;i<=m;i++)
	{
		tf=false;
		scanf("%d%d",&x,&y);
		for(j=1;j<=n;j++)
		{
			if(a[j][x]==y)
			{
				tf=true;
				printf("%d\n",s[j]);
				break;
			}
		}
		if(!tf) printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
