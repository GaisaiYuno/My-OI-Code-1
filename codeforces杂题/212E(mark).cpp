//����:һ���������ڵ�Ⱦ������ɫ������Ⱦɫ�ڵ���ɫ��ͬ�����Բ�Ⱦ
//��Ȼ��һ����Ⱦ���ţ���n-1��Ⱦɫ
//dp[x][i]��ʾx��Ⱦ����xΪ���������Ƿ������i����Ⱦ��ɫ1 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxn 5005
using namespace std;
int n;
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int head[maxn];
int ecnt=0;
void add_edge(int u,int v){
	ecnt++;
	E[ecnt].from=u;
	E[ecnt].to=v;
	E[ecnt].next=head[u];
	head[u]=ecnt;
}

int sz[maxn];
int dp[maxn][maxn];
void dfs(int x,int fa){
	sz[x]=1;
	dp[x][0]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
			sz[x]+=sz[y];
			for(int i=n-1;i>=0;i--){
				if(dp[x][i]==1) dp[x][i+sz[y]]=1;
			}
		}
	}
	for(int i=n-1;i>=0;i--){
		if(dp[x][i]==1){
			dp[x][i+n-sz[x]]=1;
		}
	}
}

vector<int>ans;
int main(){
	int u,v;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0);
	for(int i=1;i<n-1;i++){
		for(int j=1;j<=n;j++){
			if(dp[j][i]) ans.push_back(i); 
		}
	}
	int cnt=unique(ans.begin(),ans.end())-ans.begin();
	printf("%d\n",cnt);
	for(int i=0;i<cnt;i++){
		printf("%d %d\n",ans[i],n-1-ans[i]);
	}
	
} 
