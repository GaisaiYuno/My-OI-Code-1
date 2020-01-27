/*
Problem:̫�շ��мƻ��������� 24 �⡹
Source:http://111.230.183.91/problem/159
Description: 
����ÿһ��ʵ�飬��Դ�㵽ʵ����һ������Ϊ������֧����Ǯ�ıߣ�
����ÿһ���������������������һ������Ϊ�������ѵıߡ�����ÿһ��ʵ������Ҫ��������
��ʵ��������֮����һ�����������ıߡ�������ͼ����һ����������Ϳ��Եõ���С�Ļ��ѣ������������̵�֧��Ǯ��ȥ������Ѽ��ɡ�
Ϊʲô�����ǶԵ��أ�
��Դ�㵽ʵ��ı߱�֤��������������ʵ�鲻�ᳬ�������̵�Ǯ���������������ı���֤���������ֻ�Ứ�ѵ���ô���Ǯ
��ô������ͳ�ƴ��أ�
��������ʹ�õ���Dinic�����������ô���ǿ���ֱ�ӽ������ͼ��depth��������⡣
��Ϊ���Ҫѡȡ��ʵ�������ӯ���ģ����Դ�Դ�㵽ӯ����ʵ��ı�һ��һ�������ģ���ôҲ����˵�����һ��bfs��һ���������ȣ�
��ô����ֻҪ�ҳ�depth��Ϊ0��ʵ�鼴�ɡ�
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define maxn 110
#define maxm 10005 
#define INF 0x7fffffff
using namespace std;
int n,m;
int p[maxn];
int c[maxn];
struct edge{
	int from;
	int to;
	int next;
}E[maxm<<1];
long long flow[maxm];
int head[maxn];
int sz=1;
void add_edge(int u,int v,int w){
//	printf("%d->%d %d\n",u,v,w);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
	flow[sz]=w;
}

int deep[maxn];
int bfs(int s,int t){
	queue<int>q;
	memset(deep,0,sizeof(deep));
	deep[s]=1;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(flow[i]&&!deep[y]){
				deep[y]=deep[x]+1;
				q.push(y);
				if(y==t) return 1;
			} 
		}
	}
	return 0;
}

long long dfs(int x,int t,long long minf){
	if(x==t) return minf;
	long long rest=minf,k;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(flow[i]&&deep[y]==deep[x]+1){
			k=dfs(y,t,min(rest,flow[i]));
			if(k==0) deep[y]=0;
			flow[i]-=k;
			flow[i^1]+=k;
			rest-=k;
		}
	}
	return minf-rest;
}

long long dinic(int s,int t){
	long long maxflow,nowflow;
	maxflow=0;
	while(bfs(s,t)){
		while(nowflow=dfs(s,t,INF)){
			maxflow+=nowflow;
		}
	}
	return maxflow;
}

vector<int>ans;
int main(){
	int x;
	char ch;
	long long tot=0;
	scanf("%d %d",&m,&n);
	for(int i=1;i<=m;i++){
		scanf("%d",&p[i]);
		tot+=p[i];
		while(scanf("%d%c",&x,&ch)!=EOF){
			add_edge(i,x+m,INF);
			add_edge(x+m,i,0);
			if(ch=='\n'||ch=='\r') break;
		}
	}
	for(int i=1;i<=n;i++) scanf("%d",&c[i]);
	for(int i=1;i<=m;i++){
		add_edge(0,i,p[i]);
		add_edge(i,0,0);
	} 
	for(int i=1;i<=n;i++){
		add_edge(i+m,m+n+1,c[i]);
		add_edge(m+n+1,i+m,0);
	}
	long long res=tot-dinic(0,m+n+1);
	for(int i=1;i<=m;i++){
        if(deep[i]!=0){
        	ans.push_back(i);
		}
    }
    for(int i=0;i<ans.size();i++){
    	printf("%d",ans[i]);
    	if(i!=ans.size()-1) printf(" ");
    	else printf("\n");
	}
	ans.clear();
    for(int i=m+1;i<=m+n;i++){
        if(deep[i]!=0){
        	ans.push_back(i-m);
		}
    }
    for(int i=0;i<ans.size();i++){
    	printf("%d",ans[i]);
    	if(i!=ans.size()-1) printf(" ");
    	else printf("\n");
	}
	printf("%lld\n",res);
}

