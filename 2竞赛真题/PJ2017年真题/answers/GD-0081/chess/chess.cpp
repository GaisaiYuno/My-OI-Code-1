#include<bits/stdc++.h>
using namespace std;

int m,n;
int r=1,h=1,xx,yy;
int fx[4][2]={{-1,0},{0,-1},{0,1},{1,0}};
bool a[120][120];
int cc[120][120];

struct abc{
	int x,y,c,step;
}q[1200];

int main(){
	memset(a,1,sizeof(a));
	memset(cc,2,sizeof(cc));
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++) scanf("%d%d%d",&q[i].x,&q[i].y,&q[i].c);
	for(int i=1;i<=n;i++){
		cc[q[i].x][q[i].y]=q[i].c;
	}
	q[1].step=0;
	while(r<h){
		for(int i=1;i<=n;i++){
			for(int j=1;j<4;j++){
				xx=q[i].x+fx[i][0];
				yy=q[i].y+fx[i][1];
				if(xx>0&&xx<=m&&yy>0&&yy<=m&&a[xx][yy]){
					if(q[i].c==cc[xx][yy]){
						q[h].step=q[r].step;
						a[xx][yy]=false;
					}
					else if(cc[xx][yy]==2){
						q[h].step=q[r].step+2;
						a[xx][yy]=false;
					}
					else if(cc[xx][yy]!=2&&q[i].c!=2&&cc[xx][yy]!=q[i].c){
						q[h].step=q[r].step+1;
						a[xx][yy]=false;
					}
				}
				h++;
			}
			r++;
		}
	}
	if((xx==yy)==m) cout<<q[h].step;
	else cout<<-1;
}
