#include<iostream>
#include<cstdio>
using namespace std;
int a[150][150],x1[4]={0,-1,0,1},y1[4]={-1,0,1,0};
int ans=0x7ffff,m,n,t,s=0;
bool b[150][150];
void search(int x,int y,bool z)
{
	for(int i=0;i<=3;i++)
	if(x+x1[i]>=1&&y+y1[i]>=1&&x+x1[i]<=m&&y+y1[i]<=m&&!b[x+x1[i]][y+y1[i]])
	{
		if(a[x+x1[i]][y+y1[i]]!=a[x][y])
		s++;
		b[x+x1[i]][y+y1[i]]=true;
		if(x+x1[i]==m&&y+y1[i]==m)
		ans=min(s,ans);
		else	
		if(a[x+x1[i]][y+y1[i]]==2)
		{
			if(z)
			{
				b[x+x1[i]][y+y1[i]]=false;
				if(a[x+x1[i]][y+y1[i]]!=a[x][y])
				s--;
				continue;
			}
			t=0;
			if(s+2<ans)
			for(int j=0;j<=3;j++)
			if(a[x+x1[i]+x1[j]][y+y1[i]+y1[j]]!=2&&!b[x+x1[i]+x1[j]][y+y1[i]+y1[j]]&&x+x1[i]+x1[j]>=1&&x+x1[i]+x1[j]<=m&&y+y1[i]+y1[j]>=1&&y+y1[i]+y1[j]<=m)
			{
				s++;
				a[x+x1[i]][y+y1[i]]=a[x][y];
				search(x+x1[i],y+y1[i],true);
				s--;
				a[x+x1[i]][y+y1[i]]=2;
			}
		}
		else
		{
			if(s<ans)
			search(x+x1[i],y+y1[i],false);
		}
		b[x+x1[i]][y+y1[i]]=false;
		if(a[x+x1[i]][y+y1[i]]!=a[x][y])
		s--;
	}
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int x,y,c;
	cin>>m>>n;
	for(int i=1;i<=m;i++)
	for(int j=1;j<=m;j++)
	a[i][j]=2;
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&x,&y);
		scanf("%d",&a[x][y]);
	}
	b[1][1]=true;
	search(1,1,false);
	if(ans>=0x7fff)
	cout<<-1<<endl;
	else
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
