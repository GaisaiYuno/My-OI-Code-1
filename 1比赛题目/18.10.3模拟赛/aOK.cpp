#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n,m;
struct edge{
	int from;
	int to;
	int len;
	int next;
	edge(){
		
	}
	edge(int u,int v,int w,int hd){
		from=u;
		to=v;
		len=w;
		next=hd;
	}
	friend bool operator <(edge a,edge b){
		return a.len>b.len;
	}
}E[maxn<<1];
int siz=0;
int head[maxn];
void add_edge(int u,int v,int w){
	siz++;
	E[siz]=edge(u,v,w,head[u]);
	head[u]=siz;
}

struct query{
	int x;
	int k;
	int id;
	friend bool operator <(query a,query b){
		return a.k>b.k;
	}	
}q[maxn];

int fa[maxn];
int sz[maxn];
inline int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
}
inline void merge(int x,int y){
	int fx=find(x);
	int fy=find(y);
	if(fx!=fy){
		fa[fx]=fy;
		sz[fy]+=sz[fx];
	}
}

int ans[maxn];
int main(){
	int u,v,w;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n-1;i++){
		scanf("%d %d %d",&u,&v,&w);
		add_edge(u,v,w);
	}
	sort(E+1,E+1+n-1);//�ѱߴ�С�������� 
	for(int i=1;i<=m;i++){
		scanf("%d %d",&q[i].k,&q[i].x);
		q[i].id=i;
	}
	sort(q+1,q+1+m);//ѯ�����ߣ���k���� 
	int num=1;
	for(int i=1;i<=n;i++){
		fa[i]=i;
		sz[i]=1;
	}
	for(int i=1;i<=m;i++){//����ÿ��ѯ��k������Ȩ>=k�ı߼���ͼ��������������ԭ���ĵ���ͨ�ĵ�ĸ����������ϴ�С�����Ǵ� 
		while(num<=n-1&&E[num].len>=q[i].k){
			merge(E[num].from,E[num].to);
			num++;
		} 
		ans[q[i].id]=sz[find(q[i].x)]-1;
	}
	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	}
}
