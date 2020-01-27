/*
Problem:����ƽ������
Source:https://www.luogu.org/problemnew/show/P4016
Description:
���ڹ�ͼ��

���ȣ�����һ����С���ã�����ָ���������ڲֿ��е����䵥�ۣ����������Ŀ��

1.�ز����ٵ���һ������Դ��ͻ�㣬st=0,ed=n+1��

2.̰�ĵ��룬Ϊ�������вֿ����������ȣ���Ӧ�ý�����ƽ��ֵ�Ĳֿ���������ƽ��ֵ�Ĳֿ⣬��Ȼ��Ȼ���뵽��Ĳֿ�Ӧ�ù��ף�����Դ�㣻�ٵĲֿ�Ӧ�õõ��������㣬�ҷ���Ϊ0����Ϊ����ָ���������ڲֿ��е����䵥�ۣ���

3.���⣬���ڵĽڵ�֮��ҲҪ���ߣ������������ڵĽڵ㣬����Ӧ������һ������ΪINF�������������䣩������Ϊ1�ıߣ���Ϊ������ͼ������Ӧ�ý�˫��ߣ�ע�⣺��Ҫ������ߣ�����⣩��

4.ע�⣺����Ϊ��������1�Žڵ���n�Žڵ㻹Ӧ���⴦������3��
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define INF 0x3f3f3f3f
#define maxn 5005
#define maxm 500005
using namespace std;
inline void qread(int &x){
    x=0;
    int sign=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-') sign=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+c-'0';
        c=getchar();
    }
    x=x*sign;
}
int n,m;
int a[maxn];
struct edge {
    int from;
    int to;
    int next;
    int flow;
    int cost;
} E[maxm<<1];
int sz=1;
int head[maxn];
int pre[maxn];
int minf[maxn];
int dist[maxn];
int inq[maxn];
void add_edge(int u,int v,int w,int c) {
    sz++;
    E[sz].from=u;
    E[sz].to=v;
    E[sz].flow=w;
    E[sz].cost=c;
    E[sz].next=head[u];
    head[u]=sz;
}

int spfa(int s,int t){
    queue<int>q;
    memset(dist,0x3f,sizeof(dist));
    memset(inq,0,sizeof(q));
    q.push(s);
    dist[s]=0;
    inq[s]=1;
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

int main(){
	int sum=0;
	scanf("%d",&n);
	int s=0,t=n+1;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	} 
	sum/=n;
	for(int i=1;i<=n;i++){
		if(a[i]>sum){
			add_edge(s,i,a[i]-sum,0);
			add_edge(i,s,0,0); 
		}else{
			add_edge(i,t,sum-a[i],0);
			add_edge(t,i,0,0);
		}
	}
	add_edge(1,n,INF,1);
	add_edge(n,1,0,-1);
	add_edge(n,1,INF,1);
	add_edge(1,n,0,-1);
	for(int i=2;i<=n;i++){
		add_edge(i-1,i,INF,1);
		add_edge(i,i-1,0,-1);
		add_edge(i,i-1,INF,1);
		add_edge(i-1,i,0,-1);
	}
	memset(minf,0x3f,sizeof(minf));
	int maxflow=0,mincost=0;
	while(spfa(s,t)){
		update(s,t);
		mincost+=minf[t]*dist[t];
		maxflow+=minf[t];
	} 
	printf("%d\n",mincost);
}

