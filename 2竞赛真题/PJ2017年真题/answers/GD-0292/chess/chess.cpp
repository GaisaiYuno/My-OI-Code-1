#include<bits/stdc++.h>
using namespace std;

const int fx[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int m,n,x,y,col,co[110][110],c[110][110],kk;

bool check(int x,int y){
	if(x<=m&&x>0&&y<=m&&y>0) return true;
	return false;
}

int bu(int m,int n){
	if(m==n) return 0;
	return 1;
}

struct wxp{
	int x,y,ma,st;
};
queue<wxp>q;

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&x,&y,&col),co[x][y]=col?col:2;
	memset(c,0x7f,sizeof(c));
	c[1][1]=0,q.push((wxp){1,1,0,0});
	while(!q.empty()){
		int xx=q.front().x,yy=q.front().y,k=q.front().ma;
		if(k) co[xx][yy]=k,c[xx][yy]=q.front().st;
		q.pop();
		for(int i=0;i<4;i++) {
			int tmpx=xx+fx[i][0],tmpy=yy+fx[i][1];
			if(check(tmpx,tmpy)){
				if(co[tmpx][tmpy]){
					int tmpb=c[xx][yy]+bu(co[xx][yy],co[tmpx][tmpy]);
					if(c[tmpx][tmpy]>tmpb)
						c[tmpx][tmpy]=tmpb,q.push((wxp){tmpx,tmpy,0,0});
				}
				else if(!k) for(int i=1;i<=2;i++) {
					int tmpb=2+c[xx][yy]+bu(co[xx][yy],i);
					if(c[tmpx][tmpy]>tmpb)
						q.push((wxp){tmpx,tmpy,i,tmpb});
				}
			}
		}
		if(k) co[xx][yy]=0;
	}
	if(c[m][m]<=1000000)cout<<c[m][m];
	else cout<<"-1";
}
