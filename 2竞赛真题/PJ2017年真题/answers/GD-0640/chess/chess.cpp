#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

struct node{
	int v,next,w;
}a[400001];

int head[400001],d[100001],tot=0,map[201][201],n,m;
bool inq[100001];

int work(int x,int y){
	return n*(x-1)+y;
}

void add(int x,int y,int z){
	a[++tot].v=y;
	a[tot].w=z;
	a[tot].next=head[x];
	head[x]=tot;
}

void spfa(){
	queue<int>q;
	memset(inq,false,sizeof(inq));
	memset(d,0x7f,sizeof(d));
	d[1]=0;
	q.push(1);
	inq[1]=true;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		inq[x]=false;
		for(int i=head[x];i;i=a[i].next){
			int v=a[i].v;
			if(d[v]>d[x]+a[i].w){
				d[v]=d[x]+a[i].w;
				if(!inq[v])q.push(v),inq[v]=true;
			}
		}
	}
}

int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	int x,y,z;
	scanf("%d%d",&n,&m);
	memset(map,0,sizeof(map));
	memset(head,0,sizeof(head));
	for(int i=1;i<=m;i++){
		scanf("%d%d%d",&x,&y,&z);
		map[x][y]=z+1;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(!map[i][j]){
				if(map[i-1][j] && map[i+1][j]){
					add(work(i-1,j),work(i+1,j),2+abs(map[i-1][j]-map[i+1][j]));
				}
				if(map[i-1][j] && map[i][j+1]){
					add(work(i-1,j),work(i,j+1),2+abs(map[i-1][j]-map[i][j+1]));
				}
				if(map[i-1][j] && map[i][j-1]){
					add(work(i-1,j),work(i,j-1),2+abs(map[i-1][j]-map[i][j-1]));
				}
				if(map[i+1][j] && map[i][j+1]){
					add(work(i+1,j),work(i,j+1),2+abs(map[i][j+1]-map[i+1][j]));
				}
				if(map[i+1][j] && map[i][j-1]){
					add(work(i+1,j),work(i,j-1),2+abs(map[i][j-1]-map[i+1][j]));
				}
				if(map[i][j-1] && map[i][j+1]){
					add(work(i,j-1),work(i,j+1),2+abs(map[i][j+1]-map[i][j-1]));
				}
			}
			if(map[i][j]){
				if(map[i-1][j]){
					add(work(i,j),work(i-1,j),abs(map[i-1][j]-map[i][j]));
				}
				if(map[i+1][j]){
					add(work(i,j),work(i+1,j),abs(map[i+1][j]-map[i][j]));
				}
				if(map[i][j-1]){
					add(work(i,j),work(i,j-1),abs(map[i][j-1]-map[i][j]));
				}
				if(map[i][j+1]){
					add(work(i,j),work(i,j+1),abs(map[i][j+1]-map[i][j]));
				}
			}
		}
	}
	spfa();
	if(d[work(n,n)]!=2139062143)printf("%d",d[work(n,n)]);
	else printf("-1");
}
