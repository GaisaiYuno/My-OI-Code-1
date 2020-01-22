#include<bits/stdc++.h>
using namespace std;
int fx1[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
int fx2[4][2]={{1,1},{-1,1},{-1,-1},{1,-1}};
int m,n,x,y,c,mp[110][110],cango[110][110],i,j,coinmap[110][110];
struct wxp{
	int xx,yy,coin;
}now,to;
queue<wxp> q;
long long ans=0X3f;
bool o=false;
void bfs(){
	while (!q.empty()){
		int xx,yy;
		now=q.front();	q.pop();
		now.coin=coinmap[now.xx][now.yy];
		if (now.xx==m&&now.yy==m){
			if (now.coin<ans)	ans=now.coin;
			o=true;
		}
		for (i=0;i<=3;i++){
			to.xx=now.xx+fx1[i][0];	to.yy=now.yy+fx1[i][1];
			if (cango[to.xx][to.yy]!=-1&&mp[to.xx][to.yy]!=9){
				if (cango[to.xx][to.yy]==1){
					if (mp[to.xx][to.yy]!=mp[now.xx][now.yy])	to.coin=now.coin+1;
					else to.coin=now.coin;
					if (to.coin<coinmap[to.xx][to.yy])	coinmap[to.xx][to.yy]=to.coin;
				}
				if (cango[to.xx][to.yy]==0){
					cango[to.xx][to.yy]=1;
					if (mp[to.xx][to.yy]!=mp[now.xx][now.yy])	to.coin=now.coin+1;
					else to.coin=now.coin;					
					coinmap[to.xx][to.yy]=to.coin;
					q.push(to);
				}
			}
		}
		for (i=0;i<=3;i++){
			to.xx=now.xx+fx2[i][0];	to.yy=now.yy+fx2[i][1];
			if (cango[to.xx][to.yy]!=-1&&mp[to.xx][to.yy]!=9){
				if (cango[to.xx][to.yy]==1){
					if (mp[to.xx][to.yy]!=mp[now.xx][now.yy])	to.coin=now.coin+3;
					else to.coin=now.coin+2;
					if (to.coin<coinmap[to.xx][to.yy])	coinmap[to.xx][to.yy]=to.coin;
				}
				if (cango[to.xx][to.yy]==0){
					cango[to.xx][to.yy]=1;
					if (mp[to.xx][to.yy]!=mp[now.xx][now.yy])	to.coin=now.coin+3;
					else to.coin=now.coin+2;
					coinmap[to.xx][to.yy]=to.coin;
					q.push(to);
				}
			}
		}
	}
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&m,&n);
	memset(coinmap,0,sizeof(coinmap));
	memset(cango,-1,sizeof(cango));
	for (i=1;i<=m;i++)	for (j=1;j<=m;j++){cango[i][j]=0;mp[i][j]=9;}
	for (i=1;i<=n;i++){scanf("%d%d%d",&x,&y,&c);	mp[x][y]=c;}
	cango[1][1]=1;
	now.xx=1;	now.yy=1;	now.coin=0;
	q.push(now);
	bfs();
	if (!o)	printf("-1");
	else printf("%lld",ans);
	return 0;
}
