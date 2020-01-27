#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 505
#define maxm 505 
using namespace std;
int n,m;
struct edge {
	int from;
	int to;
	int next;
} E[maxm<<1];
int head[maxn];
int ecnt=0;
void add_edge(int u,int v) {
	ecnt++;
	E[ecnt].from=u;
	E[ecnt].to=v;
	E[ecnt].next=head[u];
	head[u]=ecnt;
}

int root=0;
int tim=0;
int dfn[maxn];
int low[maxn];
int cut[maxn];
int ccnt=0;//��ͨ�������� 
int scnt=0;//��ͨ���С
int mark[maxn];//��ͨ���� 
void ini(){
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head));
	ecnt=0;
	memset(dfn,0,sizeof(dfn));
	memset(low,0,sizeof(low));
	memset(cut,0,sizeof(cut));
	memset(mark,0,sizeof(mark));
	root=0;
	tim=0;
}
void tarjan(int x) {
	int flag=0;
	dfn[x]=low[x]=++tim;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(!dfn[y]) {
			tarjan(y);
			low[x]=min(low[x],low[y]);
			if(dfn[x]<=low[y]) {
				flag++;
				if(flag>1||x!=root) {
					cut[x]=1;
				}
			}
		} else {
			low[x]=min(low[x],dfn[y]);
		}
	}
}


void dfs(int x) {
	mark[x]=tim;
	scnt++;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		if(mark[y]>=tim) continue;
		if(cut[y]) {
			mark[y]=tim;
			ccnt++;
		} else dfs(y);
	}
}
int main() {
	int u,v;
	int cas=0;
	while(scanf("%d",&m)!=EOF) {
		if(m==0) break;
		cas++;
		ini();
		n=0;
		for(int i=1; i<=m; i++) {
			scanf("%d %d",&u,&v);
			add_edge(u,v);
			add_edge(v,u);
			n=max(n,u);
			n=max(n,v);
		}
		for(int i=1; i<=n; i++) {
			if(!dfn[i]){
				root=i;
				tarjan(i);
			}
		}

		tim=0;
		long long ans1=0,ans2=1;
		for(int i=1; i<=n; i++) {
			tim++;
			ccnt=0;
			scnt=0;
			if(!mark[i]&&!cut[i]){
				dfs(i);
				if(ccnt==0){//�޸�� 
					if(scnt==1){//ֻ��һ���ڵ㣬��1�� 
						ans1++; 
					}else{//�ж���ڵ㣬��scnt����ѡ��2���� 
						ans1+=2;
						ans2=ans2*(long long)scnt*(scnt-1)/2;// C(scnt,2) 
					}
				}else if(ccnt==1){//һ����������������� 
					ans1++; 
					ans2=ans2*(long long)scnt; 
				}else if(ccnt==2){
					//����2����㣬����һ�����ƻ��˶�����ͨ����һ�� 
				}
			}
		}
		printf("Case %d: %lld %lld\n",cas,ans1,ans2);
	}
}
