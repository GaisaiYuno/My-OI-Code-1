//若A类边权值越大，则A类边在最小生成树中出现的越少，显然有单调性 
//所以给A类边统一加上d,再跑最小生成树，求出A类边个数x ,最小生成树大小sum 
//二分d
//若x>k，则d增加，否则d减少
//当x=k时ans=sum-k*d 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define INF 0x7fffffff
#define maxn 50005
#define maxm 100005
using namespace std;
const double eps=1e-6;
int n,m,k;
struct edge{
	int from;
	int to;
	double len;
	int type;
	friend bool operator <(edge x,edge y){
		if(x.len==y.len) return x.type<y.type;
		else return x.len<y.len;
	}
}E[maxm<<1];
int head[maxn];
int sz=0;
void add_edge(int u,int v,double w,int t){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].type=t;
}

int fa[maxn];
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
void kruskal(int& x,int& sum){
	x=0;
	sum=0;
	sort(E+1,E+m+1);
	for(int i=1;i<=n;i++) fa[i]=i;
	int u,v,fu,fv;
	double ans;
	for(int i=1;i<=m;i++){
		u=E[i].from;
		v=E[i].to;
		fu=find(u);
		fv=find(v);
		if(fu!=fv){
			fa[fu]=fv;
			if(E[i].type==0) x++;
			sum+=E[i].len;
		}
	}
} 

int bin_search(){
	double l=-100,r=100;
	double mid;
	int x,sum;
	int ans=0;
	while(fabs(r-l)>=eps){
//		printf("[%.6f,%.6f] %.6f\n",l,r,fabs(r-l));
		mid=(l+r)/2;
		x=sum=0;
		for(int i=1;i<=m;i++)if(E[i].type==0)E[i].len+=mid;
		kruskal(x,sum);
		for(int i=1;i<=m;i++)if(E[i].type==0)E[i].len-=mid;
		if(x>k){
			l=mid+eps;
		}else if(x==k){
			ans=sum-mid*k;
			break;
		}else{
			r=mid-eps;
		}
	}
	return ans;
}

void ini(){
	sz=0;
	memset(head,0,sizeof(head));
	memset(E,0,sizeof(E));
}
int main(){
	int a,b,c,x;
	int cnt=0;
	while(scanf("%d %d %d",&n,&m,&k)!=EOF){
		ini();
		for(int i=1;i<=m;i++){
			scanf("%d %d %d %d",&a,&b,&c,&x);
			a++;
			b++;
			add_edge(a,b,c,x);
//			add_edge(b,a,c,x);
		}	
		printf("Case %d: %d\n",++cnt,bin_search());
	}
}
/*
4 5 2
0 2 5 0
0 1 6 0
0 3 3 0
2 3 1 1
1 3 2 1

*/
