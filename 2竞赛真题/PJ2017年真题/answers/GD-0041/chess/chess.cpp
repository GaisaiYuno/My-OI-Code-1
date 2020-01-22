#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
int read()
{
	int x=0,f=1; char c=getchar();
	while (c>'9'||c<'0') {if (c=='-') f=-1; c=getchar();}
	while (c>='0'&&c<='9') {x=x*10+c-'0'; c=getchar();}
	return x*f;
}
int m,n,x,c,y,head,tail,ans=1<<25;
int D[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
int map[110][110]={0};
bool foot[110][110]={0};
struct QUE
{
	int x;
	int y;
	int coin;
	bool flag;
	int color;
}q[1100000];
int main()
{	
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	foot[1][1]=1;
	m=read(); n=read();
	for (int i=1; i<=n; i++) {
		x=read(); y=read(); c=read();
		if (c==0) map[x][y]=2;
		else map[x][y]=1;
	}
	head=1;tail=2;
	q[1].x=1; q[1].y=1; q[1].coin=0; q[1].flag=1; q[1].color=map[1][1];
	while(head<tail) {
		for (int i=0; i<4; i++) {
			int xx=q[head].x+D[i][0],yy=q[head].y+D[i][1];
			if (xx>=1&&xx<=m&&yy>=1&&yy<=m&&foot[xx][yy]==0) {
				if (map[xx][yy]==0) {
					if (q[head].flag) {
						q[tail].x=xx; 
						q[tail].y=yy;
						q[tail].coin=q[head].coin+2;
						q[tail].flag=0;
						q[tail].color=1;
						if (q[head].color!=q[tail].color) q[tail].coin++;else; 
						if (q[tail].x==m&&q[tail].y==m&&q[tail].coin<ans) ans=q[tail].coin; 
						tail++;
						
						q[tail].x=xx; 
						q[tail].y=yy;
						q[tail].coin=q[head].coin+2;
						q[tail].flag=0;
						q[tail].color=2;
						if (q[head].color!=q[tail].color) q[tail].coin++;else;
						foot[xx][yy]=1;
						if (q[tail].x==m&&q[tail].y==m&&q[tail].coin<ans) ans=q[tail].coin; 
						tail++;
					} else;
				}
				else {
					
					q[tail].x=xx; 
					q[tail].y=yy;
					q[tail].flag=1;
					q[tail].color=map[xx][yy];
					if (q[head].color!=q[tail].color) q[tail].coin=q[head].coin+1; else q[tail].coin=q[head].coin;
					foot[xx][yy]=1;
					if (q[tail].x==m&&q[tail].y==m&&q[tail].coin<ans) ans=q[tail].coin; 
					tail++;
				}	
			}
		}
		head++;
	}
	if (ans!=1<<25) cout<<ans; else cout<<-1;
	fclose(stdin); fclose(stdout);
	return 0;
}
