//BZOJ 3232
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 55
#define INF 1e10
using namespace std;
int n,m;
int a[maxn][maxn];
int row[maxn][maxn];
int col[maxn][maxn];
int sum[maxn][maxn];

struct edge{
	int from;
	int to;
	int next;
	int lenv;
	int lenc;
	double w;
	void work_01(double mid){
		w=(double)lenv-lenc*mid;
	}
}E[maxn*maxn*4];
int head[maxn*maxn];
int sz=0;
void add_edge(int u,int v,int wv,int wc){
	printf("debug:%d %d %d %d\n",u,v,wv,wc); 
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].lenv=wv;
	E[sz].lenc=wc;
	head[u]=sz;
} 

int get_id(int x,int y){
	return (x-1)*(m+1)+y;
}

void init(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			sum[i][j]=sum[i-1][j]+a[i][j];
		}
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=m;j++){
			add_edge(get_id(i,j),get_id(i,j+1),-sum[i-1][j],row[i][j]);
			add_edge(get_id(i,j+1),get_id(i,j),sum[i-1][j],row[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m+1;j++){
			add_edge(get_id(i,j),get_id(i+1,j),0,col[i][j]);
			add_edge(get_id(i+1,j),get_id(i,j),0,col[i][j]);
		}
	}
}

int inq[maxn];
int cnt[maxn];
double dist[maxn];
int exist_neg_ring(){
	queue<int>q;
	for(int i=1;i<=(n+1)*(m+1);i++){
		dist[i]=INF;
		inq[i]=0;
		cnt[i]=0;
	}
	dist[1]=0;
	inq[1]=1;
	cnt[1]++;
	q.push(1);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		if(cnt[x]>(n+1)*(m+1)) return 1;
		inq[x]=0;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(dist[y]>dist[x]+E[i].w){
				dist[y]=dist[x]+E[i].w;
				if(!inq[y]){
					q.push(y);
					cnt[y]++;
					inq[y]=1;
				}
			}
		}
	}
	return 0;
}

int check(double mid){
	for(int i=1;i<=sz;i++){
		E[i].work_01(mid);
	}
	if(exist_neg_ring()) return 0;
	else return 1;
}

double bin_search(double l,double r){
	double mid;
	for(int i=1;i<=50;i++){
		mid=(l+r)/2;
		if(check(mid)) l=mid;
		else r=mid;
	}
	return mid; 
}
int main(){
	int tot=0;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&a[i][j]);
			tot+=a[i][j];
		}
	}
	for(int i=1;i<=n+1;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&row[i][j]);
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m+1;j++){
			scanf("%d",&col[i][j]);
		}
	}
	init();
	printf("%.3f\n",bin_search(0,tot));
} 
