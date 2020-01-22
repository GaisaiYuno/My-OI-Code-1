#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 5005
using namespace std;
int n,m;
int sx,sy; 
struct node {
	int x;
	int y;
	int step;
	int sl;
	int sr;
	node() {

	}
	node(int xx,int yy,int st,int l,int r) {
		x=xx;
		y=yy;
		step=st;
		sl=l;
		sr=r;
	}
	friend bool operator <(node x,node y){
		if(x.sl==y.sl) return x.sr>y.sr;
		else return x.sl>y.sl;
	} 
};
priority_queue<node>q;
int dirx[4]= {1,-1,0,0};
int diry[4]= {0,0,1,-1};
char tmp[maxn];
char a[maxn][maxn];
int used[maxn][maxn];
int usedl[maxn][maxn],usedr[maxn][maxn];
int ml,mr;
int bfs(int sx,int sy) {
	int ans=0;
	used[sx][sy]=1;
	q.push(node(sx,sy,0,0,0));
	if(a[sx][sy]=='*') return 0;
	while(!q.empty()) {
		node now=q.top();
		q.pop();
		ans++;
		for(int i=0; i<4; i++) {
			if(i<2) {
				int xx=now.x+dirx[i];
				int yy=now.y+diry[i];
				if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!used[xx][yy]&&a[xx][yy]!='*') {
					used[xx][yy]=1;
					usedr[xx][yy]=now.sr;
					usedl[xx][yy]=now.sl;
					q.push(node(xx,yy,now.step+1,now.sl,now.sr));
				}
			} else {
				int xx=now.x+dirx[i];
				int yy=now.y+diry[i];
				if(i==2) {
					if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!used[xx][yy]&&a[xx][yy]!='*'&&usedr[xx][yy]!=mr) {
						used[xx][yy]=1;
						q.push(node(xx,yy,now.step+1,now.sl,now.sr+1));
					}
				} else {
					if(xx>=1&&xx<=n&&yy>=1&&yy<=m&&!used[xx][yy]&&a[xx][yy]!='*'&&usedl[xx][yy]!=ml) {
						used[xx][yy]=1;
						q.push(node(xx,yy,now.step+1,now.sl+1,now.sr));
					}
				}
			}
		}
	}
	return ans;
}

int main(){
//	freopen("ans2.out","w",stdout);
//	freopen("data.txt","r",stdin);
	scanf("%d %d %d %d %d %d",&n,&m,&sx,&sy,&ml,&mr);
	for(int i=1;i<=n;i++){
		scanf("%s",tmp);
		for(int j=1;j<=m;j++){
			a[i][j]=tmp[j-1];
		}
	}
	printf("%d\n",bfs(sx,sy));
//	for(int i=1;i<=n;i++){
//		for(int j=1;j<=m;j++){
//			printf("%d ",used[i][j]);
//		}
//		printf("\n");
//	} 
} 

