#include<bits/stdc++.h>
using namespace std;
int m,n,a[110][110],fx[4][2]={{0,-1},{0,1},{1,0},{-1,0}},x,y,col,ans=10001;
bool f[110][110];
void dfs(int x1,int y1,int coi,int mag,int now){
	if(x1==m&&y1==m){
		ans=min(ans,coi);
		return;
	}
	if(coi>=ans) return;
	for(int i=0;i<4;i++){ 
	    int x2=x1+fx[i][0],y2=y1+fx[i][1];
		if(x2>=1&&x2<=m&&y2>=1&&y2<=m&&f[x2][y2]==false) if(a[x2-1][y2]*a[x2+1][y2]||a[x2-1][y2]*a[x2][y2-1]||a[x2-1][y2]*a[x2][y2+1]||a[x2+1][y2]*a[x2][y2-1]||a[x2+1][y2]*a[x2][y2+1]||a[x2][y2-1]*a[x2][y2+1]||a[x2-1][y2-1]||a[x2-1][y2+1]||a[x2+1][y2-1]||a[x2+1][y2+1]){
			f[x2][y2]=true;
			if(now) a[x1][y1]=now;
			if(a[x2][y2]){
				if(a[x1][y1]==a[x2][y2]){
					if(now) a[x1][y1]=0;
					dfs(x2,y2,coi,0,0);
				}
				else{
					if(now) a[x1][y1]=0;
					dfs(x2,y2,coi+1,0,0);
				}
			}
			else if(mag==0&&(a[x2-1][y2]*a[x2+1][y2]||a[x2-1][y2]*a[x2][y2-1]||a[x2-1][y2]*a[x2][y2+1]||a[x2+1][y2]*a[x2][y2-1]||a[x2+1][y2]*a[x2][y2+1]||a[x2][y2-1]*a[x2][y2+1])) dfs(x2,y2,coi+2,1,a[x1][x2]);
			f[x2][y2]=false;
			if(now) a[x1][y1]=0;
	    }
	}
	return;
}
int main(){
	freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=n;i++){
		cin>>x>>y>>col;
		a[x][y]=col+1;
	}
	f[1][1]=true;
	dfs(1,1,0,0,0);
	if(ans!=10001) cout<<ans;
	else cout<<-1;
}
