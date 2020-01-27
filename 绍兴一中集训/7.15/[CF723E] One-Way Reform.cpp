//https://vjudge.net/contest/311234#problem/B
/*
���Ͻ�Ϊ������ͼ�е�ż�����������ǹ��췽���ﵽ����Ͻ�
��һ�����S������������ߣ�������㶼�����ż�㣬�����ĸ���һ����ż������SҲ�Ǹ�ż��
������ͼ����ŷ����·����������Ա߽��ж�����ԭͼ������ż����ȵ��ڳ��ȣ��ﵽ�Ͻ�

*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200
#define maxm 100000
using namespace std;
int t,n,m;
struct edge{
	int from;
	int to;
	int next;
}E[maxm*2+5];
int head[maxn+5];
int sz=1;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}
 
int st=0;
int deg[maxn+5];
int visv[maxn+5],vise[maxm*2+5];
int cur[maxn+5];
void dfs(int x){
	visv[x]=1;
	for(int& i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!vise[i]&&!vise[i^1]){
			vise[i]=vise[i^1]=1;
			if(x!=0&&y!=0) printf("%d %d\n",x,y);
			dfs(y);
		}
	}
}
 
void ini(){
	sz=1;
	memset(head,0,sizeof(head));
	memset(deg,0,sizeof(deg));
	memset(visv,0,sizeof(visv));
	memset(vise,0,sizeof(vise));
}
int main(){
	int u,v;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&m);
		ini();
		for(int i=1;i<=m;i++){
			scanf("%d %d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
			deg[u]++;
			deg[v]++;
		}
		st=0;
		int ans=0;
		for(int i=1;i<=n;i++){
			if(deg[i]%2==1){
				add_edge(st,i);
				add_edge(i,st);
			}else ans++;
		}
		
//		for(int i=1;i<=top;i++) printf("%d ",s[i]);
//		printf("\n");
		printf("%d\n",ans);
		for(int i=0;i<=n;i++){
			dfs(i);
		}
//		for(int i=1;i<top;i++){
//			if(s[i]!=0&&s[i+1]!=0)printf("%d %d\n",s[i],s[i+1]);
//		}
	}
} 
