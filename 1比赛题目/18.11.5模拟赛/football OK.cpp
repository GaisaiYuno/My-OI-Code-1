//loj 2335
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#define maxn 1250005
using namespace std;
struct point{
	int x;
	int y;
}a[200005];
int H,W,A,B,C,n;
struct edge{
	int to;
	int len;
	edge(){
		
	}
	edge(int v,int w){
		to=v;
		len=w;
	}
};
vector<edge>E[maxn];
int get_id(int x,int y,int k){
	return ((x-1)*W+y-1)*5+k;
}

int dirx[4]={1,-1,0,0},diry[4]={0,0,1,-1};
int check(int x,int y){
	if(x>=1&&x<=H&&y>=1&&y<=W) return 1;
	else return 0;
}

struct node{
	int x;
	long long d;
	node(){
		
	}
	node(int u,long long dis){
		x=u;
		d=dis;
	}
	friend bool operator < (node p,node q){
		return p.d>q.d;
	}
};
long long dist[maxn];
int used[maxn];
int ma[505][505];
priority_queue<node>q;
void dijkstra(){
	memset(dist,0x3f,sizeof(dist));
	dist[get_id(a[1].x,a[1].y,4)]=0;
	q.push(node(get_id(a[1].x,a[1].y,4),0));
	while(!q.empty()){
		node now=q.top();
		q.pop();
		int x=now.x;
		int s=E[x].size();
		if(used[x]) continue;
		used[x]=1;
		for(int i=0;i<s;i++){
			int y=E[x][i].to;
			if(dist[y]>dist[x]+E[x][i].len){
				dist[y]=dist[x]+E[x][i].len;
				q.push(node(y,dist[y]));
			}
		}
	}
}
int main(){
	scanf("%d %d",&H,&W);
	scanf("%d %d %d",&A,&B,&C);
	scanf("%d",&n);
	H++;
	W++;
//	printf("ok\n");
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
		a[i].x++;
		a[i].y++;
		ma[a[i].x][a[i].y]=1;
	}
	for(int i=1;i<=H;i++){
		for(int j=1;j<=W;j++){
			for(int k=0;k<4;k++){
//				printf("%d %d %d ok\n",i,j,k);
				if(ma[i][j])E[get_id(i,j,k)].push_back(edge(get_id(i,j,4),0));
				if(!check(i+dirx[k],j+diry[k])) continue;
				E[get_id(i,j,k)].push_back(edge(get_id(i+dirx[k],j+diry[k],k),A));
			}
			for(int k=0;k<4;k++){
//				printf("%d %d %d ok\n",i,j,k);
				E[get_id(i,j,4)].push_back(edge(get_id(i,j,k),B));
				if(!check(i+dirx[k],j+diry[k])) continue;
				E[get_id(i,j,4)].push_back(edge(get_id(i+dirx[k],j+diry[k],4),C));
			}
		}
	}
	dijkstra();
	printf("%lld\n",dist[get_id(a[n].x,a[n].y,4)]);
}
