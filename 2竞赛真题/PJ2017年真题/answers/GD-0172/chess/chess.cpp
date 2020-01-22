#include<bits/stdc++.h>
#define X cx+fx[p][0]
#define Y cy+fx[p][1]
#define IN X<=m&&X>=1&&Y<=m&&Y>=1
using namespace std;
const int fx[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int m,n,i,j,x,y,ans[1],mg,mx,my;
int ces[6][6];
bool ap[101][101],flag;
void dfs(int cx,int cy,int coin){
	if (cx==m&&cy==m){
		ans[0]=min(ans[0],coin);
		flag=true;
	}
	else for (int p=0;p<=3;p++){
		if (IN&&!ap[X][Y]){
			if (mg>0) mg--;
			if (mg==0) mx=0,my=0;
			int mny=0;
			if (mg&&ces[X][Y]==-1){mg=0;return;}
			else if (ces[X][Y]==-1){mg=2;mx=cx;my=cy;mny=2;}
			else if (!mg&&ces[cx][cy]!=ces[X][Y]){mny=1;}
			else if (mg&&ces[mx][my]!=ces[X][Y]){mny=1;}
			ap[X][Y]=true;coin+=mny;
			dfs(X,Y,coin);
			ap[X][Y]=false;coin-=mny;
		}
	}
}
int main(){
	freopen ("chess.in","r",stdin);
	freopen ("chess.out","w",stdout);
	memset(ans,0x7f,sizeof(ans));
	memset(ces,-1,sizeof(ces));
	cin>>m>>n;
	for (i=1;i<=n;i++){
		cin>>x>>y;
		cin>>ces[x][y];
	}
	dfs(1,1,0);
	if (flag)
	cout<<ans[0];
	else cout<<-1;
	return 0;
}

