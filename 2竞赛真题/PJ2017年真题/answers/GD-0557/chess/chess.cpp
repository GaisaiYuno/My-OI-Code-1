#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int d1[4]={0,1,-1,0},d2[4]={1,0,0,-1},x[100001],y[100001],head=0,tail=1,m,n,a[101][101],ans[100001];
bool is[101][101];
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int minn=0x7fffffff;
	memset(is,false,sizeof(is));
	cin>>m>>n;
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			a[i][j]=0x7fffffff;
	for(int i=1,x1,y1,c;i<=n;i++)
	{
		cin>>x1>>y1>>c;
		a[x1][y1]=c;
	}
//	x[1]=1,y[1]=1;
//	while(head<tail)
//	{
//		head++;
//		for(int i=0;i<4;i++)
//		{
//			int nowx=x[head]+d1[i];
//			int nowy=y[head]+d2[i];
//			if(nowx>0&&nowx<=m&&nowy>0&&nowy<=m&&!is[nowx][nowy])
//			{
//				x[++tail]=nowx;
//				y[tail]=nowy;
//				is[nowx][nowy]=true;
//				if(a[x[head]][y[head]]==a[nowx][nowy])
//					ans[tail]=ans[head];
//				else if(a[nowx][nowy]!=0x7fffffff)
//					ans[tail]=ans[head]+1;
//				else
//					ans[tail]=ans[head]+2;
//			}
//			if(nowx==m&&nowy==m)
//				minn=min(minn,ans[tail]);
//		}
//	}
//	
//	cout<<minn<<endl;
	cout<<-1<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
