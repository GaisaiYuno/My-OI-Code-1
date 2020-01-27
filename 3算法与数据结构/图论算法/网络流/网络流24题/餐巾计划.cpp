/*
Problem:�ͽ�ƻ�����
Source:https://www.luogu.org/problemnew/show/P1251
Description:
[copy]
���ȣ����ǲ�㣬��һ�������Ϻ����ϣ�ÿ�����ϻ��ܵ���ͽ���Դ��������������Ĳͽ���������п����Ϊ��ԭ���ã���ÿ���������иɾ��Ĳͽ���Դ�����򡢿�ϴ�ꡢ��ϴ�꣩��

1.��ԭ����ÿһ��������һ������Ϊ�������òͽ�x������Ϊ0�ıߣ���ʾÿ�����ϴ������x����ͽ�

2.��ÿһ������������һ������Ϊ�������òͽ�x������Ϊ0�ıߣ�ÿ�����,��ʾ�����ṩx���ɾ��Ĳͽ�,����ʱ��ʾ��i��Ĳͽ��� �� 3.��ÿһ��������ڶ���������һ������ΪINF������Ϊ0�ıߣ���ʾÿ�����Ͽ��Խ���ͽ������ڶ������ϣ�ע�ⲻ�����ϣ���Ϊ��ͽ������ϲ�����ʹ�ã���

4.��ÿһ����������һ��+��ϴ��������t1����һ��������һ������ΪINF������Ϊ��ϴ����Ǯ���ıߣ���ʾÿ�����Ͽ�����ȥ��ϴ��,�ڵ�i+t1�������յ��ͽ� ��

5.ͬ����ÿһ����������һ��+��ϴ��������t2����һ��������һ������ΪINF������Ϊ��ϴ����Ǯ���ıߣ���ʾÿ�����Ͽ�����ȥ��ϴ��,�ڵ�i+t2�������յ��ͽ� ��

6.�������ÿһ��������һ������ΪINF������Ϊ����ͽ�����Ǯ���ıߣ���ʾÿ�����Ͽ��Թ���ͽ� �� ע�⣬����6����Ҫ������ߣ�3~6����Ҫ���жϣ�������ı߱���<=n��
*/ 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 10005
#define maxm 500005
#define INF 0x3f3f3f3f3f3f3f3f  
using namespace std; 
int n; 

struct edge{
    int from;
    int to;
    int next;
    long long flow;
    long long cost;
}E[maxm<<1];
int head[maxn];
int sz=1;
void add_edge(int u,int v,long long w,long long c){
//	printf("%d->%d vol=%d cost=%d\n",u,v,w,c);
    sz++;
    E[sz].from=u;
    E[sz].to=v;
    E[sz].next=head[u];
    E[sz].flow=w;
    E[sz].cost=c; 
    head[u]=sz;
    
    sz++;
    E[sz].from=v;
    E[sz].to=u;
    E[sz].next=head[v];
    E[sz].flow=0;
    E[sz].cost=-c; 
    head[v]=sz;
} 

long long dist[maxn];
long long minf[maxn];
int pre[maxn];
int inq[maxn]; 
bool spfa(int s,int t){
    memset(dist,0x3f,sizeof(dist));
    memset(inq,0,sizeof(inq));
    queue<int>q;
    q.push(s);
    inq[s]=1;
    dist[s]=0;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        inq[x]=0; 
        for(int i=head[x];i;i=E[i].next){
            int y=E[i].to;
            if(E[i].flow){
                if(dist[y]>dist[x]+E[i].cost){
                    dist[y]=dist[x]+E[i].cost;
                    minf[y]=min(minf[x],E[i].flow);
                    pre[y]=i;
                    if(!inq[y]){
                        inq[y]=1;
                        q.push(y);
                    } 
                }
            }
        }
    } 
    if(dist[t]==INF) return 0;
    else return 1;
}

void update(int s,int t){
    int x=t;
    while(x!=s){
        int i=pre[x];
        E[i].flow-=minf[t];
        E[i^1].flow+=minf[t];
        x=E[i^1].to;
    }
}

long long mcmf(int s,int t){
    memset(minf,0x3f,sizeof(minf));
    long long mincost=0,maxflow=0;
    while(spfa(s,t)){
        update(s,t);
        mincost+=dist[t]*minf[t];
        maxflow+=minf[t];
    }
    return mincost;
}
int p,fcost,fday,scost,sday;
int r[maxn];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&r[i]);
	scanf("%d %d %d %d %d",&p,&fday,&fcost,&sday,&scost);
	int s=0,t=n*2+1;
	for(int i=1;i<=n;i++){
		add_edge(s,i+n,r[i],0);
		add_edge(i,t,r[i],0);
	}
	for(int i=1;i<n;i++){
		add_edge(i+n,i+1+n,INF,0);
	}
	for(int i=1;i+fday<=n;i++){
		add_edge(i+n,i+fday,INF,fcost);
	}
	for(int i=1;i+sday<=n;i++){
		add_edge(i+n,i+sday,INF,scost);
	}
	for(int i=1;i<=n;i++){
		add_edge(s,i,INF,p);
	}
//	for(int i=n-min(fday,sday)+1;i<=n;i++){
//		add_edge(i+n,t,INF,0);
//	}
	printf("%lld\n",mcmf(s,t));
}
