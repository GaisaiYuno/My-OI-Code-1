//HDU 3228
#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<queue>
#define MAXN 50005
using namespace std;
struct point {
	double x;
	double y;
	int id;
} p[MAXN],q[MAXN];
point make_point(double x,double y,int id) {
	point tmp;
	tmp.x=x;
	tmp.y=y;
	tmp.id=id;
	return tmp;
}
void input(point* a) {
	scanf("%lf%lf",&(a->x),&(a->y));
}
double getdis(point a,point b) {
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

struct edge_table {
	int from;
	int to;
	//int next;
	double value;
} edge[MAXN*32];
//int head[MAXN+MAXN];
int edge_cnt=0;
void add_edge(int u,int v,double w) {
	edge[++edge_cnt].from=u;
	edge[edge_cnt].to=v;
	edge[edge_cnt].value=w;
	//edge[edge_cnt].next=head[u];
	//head[u]=edge_cnt;
}

int n,m;
double t1[MAXN],t2[MAXN];
void delete_same() {
	sort(t1,t1+n);
	sort(t2,t2+m);
	int ptr=0;
	for(int i=0; i<n; i++) { //Хажи
		if(i==n-1||t1[i]!=t1[i+1]) t1[ptr++]=t1[i];
	}
	n=ptr;
	ptr=0;
	for(int i=0; i<m; i++) {
		if(i==m-1||t2[i]!=t2[i+1]) t2[ptr++]=t2[i];
	}
	m=ptr;
}

/*struct heap_node{
    int id;
    double value;
    friend bool operator <(heap_node a,heap_node b){
        return a.value>b.value;
    }
};

double key[MAXN+MAXN];
int used[MAXN+MAXN];
double prim(){
    double ans=0;
    int tot=0;
    memset(key,0x7f,sizeof(key));
    memset(used,0,sizeof(used));
    priority_queue<heap_node>heap;
    heap_node now,nex;
    now.id=1;
    now.value=key[1]=0;
    heap.push(now);
    while(!heap.empty()){
        now=heap.top();
        heap.pop();
        int u=now.id;
        if(now.value!=key[u]) continue;
        used[u]=1;
        ans+=key[u];
        tot++;
        for(int i=head[u];i;i=edge[i].next){
            int v=edge[i].to;
            if(used[v]==0&&key[v]>edge[i].value){
                key[v]=edge[i].value;
                nex.value=key[v];
                nex.id=v;
                heap.push(nex);
            }
        }
    }
    if(tot<n+m) ans=-1;
    return ans;
}*/
int father[MAXN];
int find(int x) {
	if(father[x]!=x) father[x]=find(father[x]);
	return father[x];
}
int comp(edge_table a,edge_table b) {
	return a.value<b.value;
}
double kruskal() {
	for(int i=0; i<=n+m; i++) father[i]=i;
	double sum=0;
	sort(edge+1,edge+edge_cnt+1,comp);
	for(int i=1; i<=edge_cnt; i++) {
		int tx=find(edge[i].from);
		int ty=find(edge[i].to);
		if(tx!=ty) {
			father[tx]=ty;
			sum+=edge[i].value;
		}
	}
	return sum;
}
int main() {
	point a,b,c,d;
	int cnt;
	scanf("%d",&cnt);
	for(int cas=1; cas<=cnt; cas++) {
		int i;
		scanf("%d %d",&n,&m);
		input(&a);
		input(&b);
		input(&c);
		input(&d);
		//scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a.x,&a.y,&b.x,&b.y,&c.x,&c.y,&d.x,&d.y);
		for(i=0; i<n; i++) scanf("%lf",&t1[i]);
		for(i=0; i<m; i++) scanf("%lf",&t2[i]);

		delete_same();
		for(i=0; i<n; i++) {
			p[i]=make_point(a.x*t1[i]+b.x*(1-t1[i]),a.y*t1[i]+b.y*(1-t1[i]),i+1);
		}
		for(i = 0 ; i < m ; i++) {
			q[i]=make_point(c.x*t2[i]+d.x*(1-t2[i]),c.y*t2[i]+d.y*(1-t2[i]),i+n+1);
		}

		edge_cnt=0;
		double sum1=0,sum2=0;
		for(i=0; i<n-1; i++) {
			double l=getdis(p[i],p[i+1]);
			add_edge(p[i].id,p[i+1].id,l);
			add_edge(p[i+1].id,p[i].id,l);
			sum1+=l;
		}
		for(i=0; i<m-1; i++) {
			double l=getdis(q[i],q[i+1]);
			add_edge(q[i].id,q[i+1].id,l);
			add_edge(q[i+1].id,q[i].id,l);
			sum2+=l;
		}
		if(n==0||m==0) {
			printf("Case #%d: %.3lf\n",cas,sum1+sum2);
			continue;
		}

		for(int i=0; i<n; i++) {
			int l,r;
			l=0;
			r=m-1;
			while(r-l>1) {
				int mid1=(r+l)/2;
				int mid2=(mid1+r)/2;
				if(getdis(p[i],q[mid1])>getdis(p[i],q[mid2])) l=mid1;
				else r=mid2;
			}
			add_edge(p[i].id,q[l].id,getdis(p[i],q[l]));
			add_edge(q[l].id,p[i].id,getdis(p[i],q[l]));
			add_edge(p[i].id,q[r].id,getdis(p[i],q[r]));
			add_edge(q[r].id,p[i].id,getdis(p[i],q[r]));
			if(l-1>=0) {
				add_edge(p[i].id,q[l-1].id,getdis(p[i],q[l-1]));
				add_edge(q[l-1].id,p[i].id,getdis(p[i],q[l-1]));
			}
			if(r+1<=m-1) {
				add_edge(p[i].id,q[r+1].id,getdis(p[i],q[r+1]));
				add_edge(q[r+1].id,p[i].id,getdis(p[i],q[r+1]));
			}

		}

		//double sum=prim();
		double sum=kruskal();
		printf("Case #%d: %.3lf\n",cas,sum);
	}
}
