#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 1005
#define INF 0x7fffffff
using namespace std;
int n;
struct point{
	int x;
	int y;
	point(){
		
	}
	point(int xx,int yy){
		x=xx;
		y=yy;
	} 
}a[maxn];
double get_dis(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
struct edge{
	int from;
	int to;
	int next;
	double len;
	friend bool operator <(edge x,edge y){
		return x.len<y.len;
	}
}E[maxn*maxn];
int sz=0;
int head[maxn];
void add_edge(int u,int v,double w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
}

double dist[maxn];
int used[maxn];
double prim(){
	int x=1;
	double ans=0;
	double maxv=INF;
	for(int i=1;i<=n;i++) dist[i]=INF;
	dist[1]=0;
	for(int i=1;i<=n;i++){
		maxv=INF;
		for(int j=1;j<=n;j++){
			if(!used[j]&&dist[j]<maxv){
				maxv=dist[j];
				x=j;
			}
		}
		used[x]=1;
//		printf("%d\n",x);
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(!used[y]&&dist[y]>E[i].len){
				dist[y]=E[i].len;
//				ans=max(ans,E[i].len);
//				printf("%d ",y);
			}
		}
//		printf("\n");
//		for(int i=1;i<=n;i++){
//			printf("%lf ",dist[i]);
//		}
//		printf("\n");
	}
	for(int i=1;i<=n;i++){
		ans=max(ans,dist[i]);
	}
	return ans*ans;
} 

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i].x,&a[i].y); 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			add_edge(i,j,get_dis(a[i],a[j]));
		}
	}
	double tmp=prim();
	printf("%.0lf\n",tmp);
} 
