#include<iostream>
#include<cstdio>
using namespace std;
struct tt
{
	int x,y,cl,s;
} r[100005];
int e[105][1005],g[105][105],v[105][105],h,t,i,k,m,n,a,b,c,x2,y2;
int dx[5]={0,1,-1,0,0},dy[5]={0,0,0,1,-1};
void bfs()
{
	r[1].x=1; r[1].y=1; r[1].cl=e[1][1];h=1; t=1; v[1][1]=1;
	while(h<=t)
	 {
	   for(i=1;i<=4;++i)
	    {
	     x2=r[h].x+dx[i]; y2=r[h].y+dy[i];
	     if (v[x2][y2]) 
		  {
		   k=0;
		   if (e[x2][y2]==0) 
		   {
	        if (r[h].s) continue;
		     k=2;
		     if (g[x2][y2]>g[r[h].x][r[h].y]+k)
		     {
		     for(int j=h+1;j<=t;++j)
		      if (r[j].x==x2&&r[j].y==y2)
		      {
		  	    r[j].x=x2; r[j].y=y2; r[j].cl=e[r[h].x][r[h].y]; r[j].s=1;
		      }
		      g[x2][y2]=min(g[x2][y2],g[r[h].x][r[h].y]+k);
			 }
	       } else
	       {
		     if(e[x2][y2]!=r[h].cl) k=1;
	        g[x2][y2]=min(g[x2][y2],g[r[h].x][r[h].y]+k);
	       }
		   continue;
		  }
		 if (x2<1||y2<1||x2>m||y2>m||v[x2][y2]) continue;
		 v[x2][y2]=1;
		 if (e[x2][y2]==0&&!r[h].s)
		  {
		  	if (e[r[h].x][r[h].y]==1)
		  	{
		  	++t;
		  	r[t].x=x2; r[t].y=y2; r[t].cl=1;r[t].s=1;
		    }
		    else
		    {
			 ++t;
			 r[t].x=x2; r[t].y=y2; r[t].cl=2;r[t].s=1;
		    }
			g[x2][y2]=g[r[h].x][r[h].y]+2;
		  } else if (e[x2][y2]!=0)
		  {
		  	 ++t;
		  	 r[t].x=x2; r[t].y=y2; r[t].cl=e[x2][y2];
		     if (e[x2][y2]!=r[h].cl) g[x2][y2]++;
			 g[x2][y2]+=g[r[h].x][r[h].y];	
		  }
        }
       ++h;
	 }
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(i=1;i<=n;++i)
	 {
	 	scanf("%d%d%d",&a,&b,&c);
	 	e[a][b]=c+1;
	 }
	bfs();
/*	for(i=1;i<=m;++i)
	 {
	  for(int j=1;j<=m;++j)
       cout<<e[i][j]<<" ";
       cout<<endl;
	 } 
	 cout<<endl;
	for(i=1;i<=m;++i)
	 {
	  for(int j=1;j<=m;++j)
       cout<<g[i][j]<<" ";
       cout<<endl;
	 }*/ 
	if (v[m][m]) cout<<g[m][m]; else cout<<-1;
	return 0;
}
