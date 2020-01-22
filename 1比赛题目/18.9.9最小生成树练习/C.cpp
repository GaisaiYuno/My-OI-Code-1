#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define INF 1e9
#define maxn 1005
#define eps 1e-5
using namespace std;
int n;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	} 
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar(); 
	}
	return x*sign;
}
struct point{
	int x;
	int y;
	int z;
}v[maxn];
double get_height(point a,point b){
	return abs(a.z-b.z);
}
double get_dist(point a,point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
struct edge{
	int from;
	int to;
	int next;
	int cost;
	double len;
	double r;//01分数规划用
	double d; //新距离 
	double cal(){
		return (double)cost-r*len; 
	}
	friend bool operator <(edge x,edge y){
		return x.cal()<y.cal();
	} 
}E[maxn*maxn];
int head[maxn];
int sz=0;
void add_edge(int u,int v,int w1,double w2){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].cost=w1;
	E[sz].len=w2;
	head[u]=sz;
}


int used[maxn];
double dist[maxn];
double f(double x){ //其实是prim
	for(int i=1;i<=sz;i++){
		E[i].r=x;
		E[i].d=E[i].cal();
	}
	for(int i=1;i<=n;i++){
		dist[i]=INF;
		used[i]=0;
	}
	dist[1]=0;
	for(int i=1;i<=n;i++){
		double maxv=dist[1];
		int x=1;
		for(int j=2;j<=n;j++){
			if(!used[j]&&dist[j]<maxv){
				maxv=dist[j];
				x=j;
			}
		}
		used[x]=1;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(!used[y]){
				dist[y]=E[i].d;
			}
		}
	}
	double ans=0;
	for(int i=1;i<=n;i++){
		ans+=dist[i];
	} 
	return ans;
} 

double frac_01(){
	double l=0,r=1e2,mid;
	while(fabs(r-l)>=eps){
		mid=(l+r)/2;
		double t=f(mid);
//		printf("[%.5Lf,%.5Lf] %.5Lf %.5Lf\n",l,r,mid,t);
		if(t>=0){
			l=mid;
		}else{
			r=mid;
		}
	}
	return r;
}

void ini(){
	sz=0;
	for(int i=0;i<=n;i++) head[i]=0;
}
int main(){
//	printf("%.4f",log2(1e11)*1000*1000);
	while(scanf("%d",&n)!=EOF){
		if(n==0) break;
        ini();
		for(int i=1;i<=n;i++){
//			scanf("%d %d %d",&v[i].x,&v[i].y,&v[i].z);
			v[i].x=qread();
			v[i].y=qread();
			v[i].z=qread();
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++){
				add_edge(j,i,get_height(v[i],v[j]),get_dist(v[i],v[j]));
			}
		}
		printf("%.3f\n",frac_01());
	}
} 
