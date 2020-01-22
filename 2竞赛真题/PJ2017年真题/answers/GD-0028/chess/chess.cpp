#include<bits/stdc++.h>
using namespace std;
int a[105][105],b[105][105],m,n,x,y,c,tot=20000;
int fx[5][2]={{1,0},{-1,0},{0,-1},{0,1}};
void dfs(int p,int q,int t,int ans,int k){
	if(p==m&&q==m&&tot>ans) tot=ans;
	else for(int i=0;i<4;i++){
		int xx=p+fx[i][0],yy=q+fx[i][1];
		if(xx>0&&yy>0&&xx<=m&&yy<=m&&a[xx][yy]==0){
			if(t==b[xx][yy]){
				a[xx][yy]=1;
				dfs(xx,yy,t,ans,0);
				a[xx][yy]=0;
			}
			else{
				if(b[xx][yy]!=0){
					ans++;
					a[xx][yy]=1;
					dfs(xx,yy,b[xx][yy],ans,0);
					a[xx][yy]=0;
					ans--;
				}
				else if(b[xx][yy]==0&&k!=1){
					ans+=2;
					a[xx][yy]=1;
					dfs(xx,yy,t,ans,1);
					a[xx][yy]=0;
					ans-=2;
				}
			}
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y>>c;
		if(c==0) b[x][y]=-1;
		if(c==1) b[x][y]=-2;
	}
	a[1][1]=1;
	dfs(1,1,b[1][1],0,0);
	if(tot==20000) cout<<"-1";
	else cout<<tot;
	return 0;
}
/*
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0

5 5
1 1 0
1 2 0
2 2 1
3 3 1
5 5 0

5 6
1 1 0
1 3 0
2 3 1
3 4 1
4 4 0
5 5 1
*/
