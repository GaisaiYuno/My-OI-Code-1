#include<bits/stdc++.h>
using namespace std;

struct abc{
	int x,y,cl,use,mon;
}q[400000];

int ch[201][201],fx[4]={0,0,-1,1},fy[4]={1,-1,0,0};
int road[201][201][2],n;

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int m,i,a,b,c,rem;
	memset(ch,-1,sizeof(ch));
	memset(road,0x7f,sizeof(road));
	rem=road[1][1][1];
	cin>>n>>m;
	for(i=1;i<=m;i++) {
		cin>>a>>b>>c;
		ch[a][b]=c;
	}
	q[1].x=1,q[1].y=1,q[1].cl=ch[1][1],q[1].use=1,q[1].mon=0,road[1][1][1]=0,road[1][1][0]=0;
	int r=1,h=1,minn=2147483647;
	while(r<=h){
		for(i=0;i<4;i++){
			int xx=q[r].x+fx[i],yy=q[r].y+fy[i];
			if(xx>=1&&xx<=m&&yy>=1&&yy<=m){
				if(ch[xx][yy]==-1&&q[r].use){
					int mon0=q[r].mon+2,mon1=q[r].mon+2;
					if(q[r].cl!=0) mon0++;
					else mon1++;
					if(mon0<road[xx][yy][0]){
						h++;
						q[h].x=xx,q[h].y=yy,q[h].cl=0,q[h].use=0,q[h].mon=mon0;
						road[xx][yy][0]=mon0;
					}
					if(mon1<road[xx][yy][1]){
					h++;
					q[h].x=xx,q[h].y=yy,q[h].cl=1,q[h].use=0,q[h].mon=mon1;
					road[xx][yy][1]=mon1;
					}
				}
				else if(ch[xx][yy]!=-1){
					int t=q[r].mon;
					if(q[r].cl!=ch[xx][yy]) t++;
					if((road[xx][yy][ch[xx][yy]]==t&&q[r].use==0)||road[xx][yy][ch[xx][yy]]>t){
					h++;
					q[h].x=xx,q[h].y=yy,q[h].cl=ch[xx][yy],q[h].use=1,q[h].mon=t;
					road[xx][yy][ch[xx][yy]]=t;
					}
				}
			}
		}
		r++;
	}
	if(road[n][n][1]!=rem||road[n][n][0]!=rem) cout<<min(road[n][n][1],road[n][n][0]);
	else cout<<-1;
	return 0;
}
/*
3 3
1 1 0
2 2 1
2 3 1
*/
