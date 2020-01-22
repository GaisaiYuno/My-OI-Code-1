#include<iostream>
#include<cstdio>
#include<fstream>
#include<string>
using namespace std;
int ye,re,nr,ny,b,d,c,m,n,a[105][105],map[105][105],ans,t,dx[4],dy[4];
void dfs(int x,int y)
{
	if (x==m&&y==m)
	 {
	 	ans=min(ans,t);
	 	return;
	 }
	if (x>m||y>m||x<1||y<1||map[x][y]==0||a[x][y]==1)
	 return ;
	for (int i=1;i<=4;i++)
	 {
	 	if (map[x+dx[i]][y+dy[i]]==1&&map[x][y]==2)
	 	 {
	 	 	t++;
	 	 	a[x][y]=1;
	 	 	ye++;
	 	 	dfs(x+dx[i],y+dy[i]);
	 	 	t--;
	 	 	ye--;
	 	 	a[x][y]=0;
	 	 }
	 	if (map[x+dx[i]][y+dy[i]]==2&&map[x][y]==1) 
	 	 {
	 	 	t++;
	 	 	a[x][y]=1;
	 	 	re++;
	 	 	dfs(x+dx[i],y+dy[i]);
	 	 	t--;
	 	 	re--;
	 	 	a[x][y]=0;
	 	 }
	 	if (map[x+dx[i]][y+dy[i]]==0&&(nr!=re||ny!=ye))
	 	 {
	 	 	t+=2;
	 	 	map[x+dx[i]][y+dy[i]]=map[x][y];
	 	 	nr=re;
	 	 	ny=ye;
	 	 	a[x][y]=1;
	 	 	dfs(x+dx[i],y+dy[i]);
	 	 	t-=2;nr=ny=0;
	 	 	map[x+dx[i]][y+dy[i]]=0;
	 	 	a[x][y]=0;
	 	 } 
	 	 if (map[x+dx[i]][y+dy[i]]==map[x][y]&&map[x+dx[i]][y+dy[i]]!=0) 
	 	 {
	 	 	a[x][y]=1;
	 	 	if (map[x][y]==2)
	 	 	 re++;
	 	 	if (map[x][y]==1)
	 	 	 ye++;
	 	 	dfs(x+dx[i],y+dy[i]);
	 	 	a[x][y]=0;
	 	 }
	 } 
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
    cin>>m>>n;
    for (int i=1;i<=n;i++)
     {
     	cin >>b>>d>>c;
     	if (c==1)map[b][d]=1;
     	if (c==0)map[b][d]=2;
     }
  /*  for (int i=1;i<=m;i++)
    {
    	for (int j=1;j<=m;j++)
	     cout <<map[i][j]<<" ";
	    cout <<endl;
    }     
    for (int i=1;i<=n;i++)
     cout <<dx[i]<<" "<<dy[i]<<endl;*/
    ans=10005;
    dx[1]=1;dx[2]=-1;
    dy[3]=1;dy[4]=-1;
	if (map[1][1]==1)
     ye++;
    if (map[1][1]==2)
     re++;
    dfs(1,1);
    if (ans==10005)cout <<-1; else cout <<ans;
	return 0;
}

