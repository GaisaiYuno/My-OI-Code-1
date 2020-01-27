//https://vjudge.net/contest/311234#problem/D
/*
首先min可以不用，直接连两条边 
按x排序，会发现对于三个点A(x1,y1) B(x2,y2) C(x3,y3) x1<x2<x3
|x1-x3|=|x1-x2|+|x2-x3|
所以不必要连(A,C)这条边 
然后跑最短路 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<queue>
#define maxn 200000
#define maxm 400000
using namespace std;
struct edge{
	int from;
	int to;
	int next;
	int len;
}E[maxm*2+5];
int head[maxn+5];
int sz;
void add_edge(int u,int v,int w){
//	printf("%d->%d len=%d\n",u,v,w);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].len=w;
	head[u]=sz;
}

int n;
struct point{
	int x;
	int y;
	int id;
}a[maxn+5];
int cmp1(point a,point b){
	return a.x<b.x;
}
int cmp2(point a,point b){
	return a.y<b.y;
}

struct node{
	long long dis;
	int id;
	node(){
		
	}
	node(int _id,long long _dis){
		id=_id;
		dis=_dis;
	}
	friend bool operator < (node p,node q){
		return p.dis>q.dis;
	}
};
priority_queue<node>q;
long long dist[maxn+5];
int vis[maxn+5];
long long dijkstra(int s,int t){
	memset(dist,0x3f,sizeof(dist));
	dist[s]=0;
	q.push(node(s,0));
	while(!q.empty()){
		node now=q.top();
		q.pop();
		int x=now.id;
		if(vis[x]) continue;
		vis[x]=1;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(dist[y]>dist[x]+E[i].len){
				dist[y]=dist[x]+E[i].len;
				q.push(node(y,dist[y]));
			}
		}
	}
	return dist[t];
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].x,&a[i].y);
		a[i].id=i;
	}
	sort(a+1,a+1+n,cmp1);
	for(int i=1;i<n;i++){
		add_edge(a[i].id,a[i+1].id,abs(a[i+1].x-a[i].x));
		add_edge(a[i+1].id,a[i].id,abs(a[i+1].x-a[i].x));
	}
	sort(a+1,a+1+n,cmp2);
	for(int i=1;i<n;i++){
		add_edge(a[i].id,a[i+1].id,abs(a[i+1].y-a[i].y));
		add_edge(a[i+1].id,a[i].id,abs(a[i+1].y-a[i].y));
	}
	printf("%lld\n",dijkstra(1,n));
}
