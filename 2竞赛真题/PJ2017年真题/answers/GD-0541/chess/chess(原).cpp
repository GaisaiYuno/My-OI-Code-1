#include<cstdio>
#define sr c=getchar()
#define INF 2147483647
#define input read()
#define pd (c<'0'||c>'9')
using namespace std;
bool b[1001][1001];
int x,y,z;
int ans=INF;
int read()
{
	char c;int d=1,f=0;
	while (sr,pd) if (c=='-') d=-1;f=f*10+c-48;
	while (sr,!pd) f=f*10+c-48;
	return d*f;
}
void dfs(int x,int y,int dep)
{
	if (x==n&&y==n)
	{
		if (dep<ans) ans=dep;
		return;
	}
    
}
int main()
{
	n=input;m=input;
	for (int i=1;i<=m;i++)
     b[x=input][y=input]=z=input;
    dfs(1,1,0);
    printf("%d",ans==INF? -1:ans);
}
