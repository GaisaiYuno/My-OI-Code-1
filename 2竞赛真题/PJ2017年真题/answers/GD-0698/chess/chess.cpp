#include<iostream>
#include<cstdio>
using namespace std;
int r[5]={0,0,-1,+1,0},tt[5]={0,+1,0,0,-1},m,n,a,s,c,w[105][105],ans,h,t,x[1000005],y[1000005],vi[1000005],ma[1000005];
bool v[105][105];
void bfs()
{
	while (h<=t)
	{
		if (x[h]==y[h]&&x[h]==m) ans=min(ans,vi[h]);
		for (int i=1;i<=4;i++)
    	{
	     int d,f;
	     d=x[h]+r[i];f=y[h]+tt[i];
	     if (v[d][f]||d<1||f<1||d>m||f>m) continue;
		 if (w[x[h]][y[h]]==w[d][f]) 
		 {
		 	t++;
		 	v[d][f]=1;
		 	x[t]=d;y[t]=f;
		 	vi[t]=vi[h];
		 	ma[t]=0;
		 }
	    }
	    for (int i=1;i<=4;i++)
    	{
	     int d,f;
	     d=x[h]+r[i];f=y[h]+tt[i];
	     if (v[d][f]||d<1||f<1||d>m||f>m) continue;
		 if (w[x[h]][y[h]]!=w[d][f]&&w[d][f]!=-1) 
		 {
		 	t++;
		 	v[d][f]=1;
		 	x[t]=d;y[t]=f;
		 	vi[t]=vi[h]+1;
		 	ma[t]=0;
		 }
    	}
		for (int i=1;i<=4;i++)
    	{
	     int d,f;
	     d=x[h]+r[i];f=y[h]+tt[i];
	     if (v[d][f]||d<1||f<1||d>m||f>m) continue;
		 if (w[x[h]][y[h]]!=w[d][f]&&w[d][f]==-1&&!ma[h]) 
		 {
		 	t++;
		 	v[d][f]=1;
		 	x[t]=d;y[t]=f;
		 	vi[t]=vi[h]+2;
		 	w[d][f]=w[x[h]][y[h]];
		 	ma[t]=1;
		 }
	    }
	    h++;
	}
	
}
int main()
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d\n",&m,&n);
	for (int i=1;i<=m;i++)
	 for (int j=1;j<=m;j++) w[i][j]=-1;
	for (int i=1;i<=n;i++)
	 {
	 	scanf("%d%d%d\n",&a,&s,&c);
	 	w[a][s]=c;
	 }
	/* for (int i=1;i<=m;i++)
	 {
	 	for (int j=1;j<=m;j++) cout<<w[i][j]<<" ";
	 	cout<<endl;
	 }*/
	 ans=100000000;
	 h=1;t=1;v[1][1]=1;
	 x[h]=1;y[h]=1;
	 vi[1]=0;
	 ma[1]=0;
     bfs();  
	 if (ans==100000000) cout<<-1; else cout<<ans;
	return 0;
}
