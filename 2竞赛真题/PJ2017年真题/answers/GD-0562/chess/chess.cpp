#include<bits/stdc++.h>
using namespace std;
const int fx[4][2]={{1,0},{0,-1},{-1,0},{0,1}};
int m,n,a[101][101],maxn=INT_MAX,ans;
bool f[101][101],flag;
void dfs(int,int,int,bool);
int main()
{
	int x,y;
	memset(a,-1,sizeof(a));
	f[1][1]=true;
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y;
		cin>>a[x][y];
	}
	dfs(0,1,1,true);
	if(flag) cout<<maxn+1;
	else cout<<-1;
}
void dfs(int dep,int x,int y,bool o)
{
	if(x==m&&y==m){
		if(dep<maxn) maxn=dep;
		flag=true;
		return;
	}
	for(int i=0;i<=3;i++){
		int xi=x+fx[i][0];
		int yi=y+fx[i][1];
		if(xi>=1&&xi<=m&&yi>=1&&yi<=m&&!f[xi][yi]){
			f[xi][yi]=true;
			if(a[xi][yi]==a[x][y]||!o){
				if(a[xi][yi]!=-1) dfs(dep,xi,yi,true);
				else continue;
			}
			else{
				if(a[xi][yi]!=-1) dfs(dep+1,xi,yi,true);
				else dfs(dep+2,xi,yi,false);
			}
			f[xi][yi]=false;
		}
	}
}
