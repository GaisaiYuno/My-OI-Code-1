#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<queue>
using namespace std;
struct node{
	int x,y,t,color;
	bool magic;
};queue<node> q;
int tf[110][110];
const int next[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int s[110][110],a,b,c,n,m;
void bfs(node t){
	queue<node> tq;
	tq.push(t);
	while(!tq.empty()){
		node x=tq.front();tq.pop();
		for(int i=0;i<4;i++){
			int tx=x.x+next[i][0],ty=x.y+next[i][1];
			if(tx<1||ty<1||tx>m||ty>m||tf[tx][ty]<=t.t||x.color!=s[tx][ty])
				continue;
			tf[tx][ty]=t.t;
			q.push((node){tx,ty,t.t,x.color,false});
			tq.push((node){tx,ty,0,x.color,false});
		}
	}
}
/*
5 5
1 1 0
1 2 0
2 2 1
3 3 1
5 5 0
*/
/*
5 7
1 1 0
1 2 0
2 2 1
3 3 1
3 4 0
4 4 1
5 5 0
*/
int main(void)
{
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	memset(tf,127,sizeof(tf));
	tf[1][1]=0;
	int minn=2147483647;
	memset(s,-1,sizeof(s));
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++){
		scanf("%d%d%d",&a,&b,&c);
		s[a][b]=c;
	}
	q.push((node){1,1,0,s[a][b],false});
	tf[1][1]=true;
	while(!q.empty()){
		node x=q.front();q.pop();
		if(x.x==m&&x.y==m)
			minn=min(x.t,minn);
		bfs(x);
		for(int i=0;i<4;i++){
			int tx=x.x+next[i][0],ty=x.y+next[i][1];
			if(tx<1||ty<1||tx>m||ty>m)
				continue;
			if(s[tx][ty]==-1&&x.magic==false&&x.t+3<tf[tx][ty]){
				tf[tx][ty]=x.t+3;
				q.push((node){tx,ty,x.t+2,1,true});
				q.push((node){tx,ty,x.t+2,2,true});
			}else if(s[tx][ty]!=-1&&x.color!=s[tx][ty]&&x.t+1<tf[tx][ty]){
				tf[tx][ty]=x.t+1;
				q.push((node){tx,ty,x.t+1,s[tx][ty],false});
			}
		}
	}
	if(minn!=2147483647)
		printf("%d",minn);
	else
		printf("-1\n");
	return 0;
}
