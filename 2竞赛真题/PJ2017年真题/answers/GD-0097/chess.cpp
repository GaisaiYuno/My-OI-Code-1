#include<bits/stdc++.h>
using namespace std;
int f[110][110],s[110][110],n,m,fx[4][2]={{1,0},{0,1},{-1,0},{0,-1}},x,y,c,co[110][110];
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&c);
		if(c==1) s[x][y]=1;
		else if(c==0) s[x][y]=2;
	}
	memset(f,0x7f,sizeof(f));
	f[1][1]=0;
	for(int i=1;i<=m;i++) for(int j=1;j<=m;j++){
		for(int k=0;k<4;k++){
			int xx=i+fx[k][0],yy=j+fx[k][1];
			if(xx<=m&&xx>=1&&yy<=m&&yy>=1){
				if(!s[i][j]&&!s[xx][yy]) continue;
			
				else if(s[i][j]==s[xx][yy])
				f[xx][yy]=min(f[i][j],f[xx][yy]);
			
				else if(!s[xx][yy]&&f[i][j]+2<=f[xx][yy]){
					f[xx][yy]=f[i][j]+2;
					co[xx][yy]=s[i][j];
				}
			
				else if(!s[i][j]&&co[i][j]&&co[i][j]==s[xx][yy])
				f[xx][yy]=min(f[i][j],f[xx][yy]);
			
				else if(!s[i][j]&&co[i][j]&&co[i][j]!=s[xx][yy])
				f[xx][yy]=min(f[i][j]+1,f[xx][yy]);
			
				else f[xx][yy]=min(f[i][j]+1,f[xx][yy]);
			}
		}
		co[i][j]=0;
	}
	if(f[m][m]>200) cout<<-1;
	else cout<<f[m][m];
}
