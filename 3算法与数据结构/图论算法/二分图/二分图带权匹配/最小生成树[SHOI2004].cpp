//https://blog.csdn.net/Deep_Kevin/article/details/84786736
/*

            -. .
       _____   ',' ,
     ,'     ,'   ', ',
   ,'     ,'      |  |
  \       \       |  |
    \ /^\   \    ,' ,'
          \   \ ,' ,'      L'Internationale,
    / ~-.___\.-'  ,'            Sera le genre humain.
  /   .______.- ~ \
/   /'          \   \
\./               \/'

Problem:��С������[SHOI2004]
Source:http://111.230.183.91/problem/149
Algorithm:KM
Description:
�������ʣ�
1.̰�ģ��������߼�С������������
2.ÿ������౻�޸�һ��
��ı�ֵ�ľ���ֵΪd
����һ��������j(u,v)������u->v��·���ϵ�����һ����i�ı�Ȩ����Ҫ<j�������i�滻��j���Եõ�һ�ø�С��������
�����wi-di<=wj+dj
ת��һ����wi-wj<=di+dj
������ʽ��KM�㷨�еĶ�����룬���԰ѱ߿��ɵ㣬�仯ֵΪ����
��KM�㷨����
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<map>
#include<utility>
#define maxn 55
#define maxm 805
#define maxlog 32
#define INF 0x3f3f3f3f
using namespace std;
int n,m;
map<pair<int,int>,int>edge_id;
struct edge {
	int from;
	int to;
	int len;
	int next;
} G[maxm<<1],T[maxm<<1];
int sz=1;
int head[maxn];
void add_edge1(int u,int v) {
	sz++;
	T[sz].from=u;
	T[sz].to=v;
	T[sz].next=head[u];
	head[u]=sz;
}

int log2n;
int deep[maxn];
int anc[maxn][maxlog];
void dfs1(int x,int fa) {
	deep[x]=deep[fa]+1;
	anc[x][0]=fa;
	for(int i=1; i<=log2n; i++) {
		anc[x][i]=anc[anc[x][i-1]][i-1];
	}
	for(int i=head[x]; i; i=T[i].next) {
		int y=T[i].to;
		if(y!=fa) {
			dfs1(y,x);
		}
	}
}

int lca(int x,int y) {
	if(deep[x]<deep[y]) swap(x,y);
	for(int i=log2n; i>=0; i--) {
		if(deep[anc[x][i]]>=deep[y]) x=anc[x][i];
	}
	if(x==y) return x;
	for(int i=log2n; i>=0; i--) {
		if(anc[x][i]!=anc[y][i]) {
			x=anc[x][i];
			y=anc[y][i];
		}
	}
	return anc[x][0];
}

int dist[maxm][maxm];
void add_edge2(int u,int v,int w){
	dist[u][v]=w; 
}

void make_graph(int x,int y,int ed){
	int l=lca(x,y);
	if(x==l){
		for(int i=y;i!=l;i=anc[i][0]){
			int t=edge_id[make_pair(x,y)];
			add_edge2(t,ed,G[t].len-G[ed].len);
		}
	}else if(y==l){
		for(int i=x;i!=l;i=anc[i][0]){
			int t=edge_id[make_pair(x,y)];
			add_edge2(t,ed,G[t].len-G[ed].len);
		}
	}else{
		for(int i=x;i!=l;i=anc[i][0]){
			int t=edge_id[make_pair(x,y)];
			add_edge2(t,ed,G[t].len-G[ed].len);
		}
		for(int i=y;i!=l;i=anc[i][0]){
			int t=edge_id[make_pair(x,y)];
			add_edge2(t,ed,G[t].len-G[ed].len);
		}
	}
}

int la[maxn];
int lb[maxn];
int va[maxn];
int vb[maxn];
int match[maxn];
int delta;
int dfs(int x){
	va[x]=1;
	for(int y=1;y<=n;y++){
		if(!vb[y]&&dist[x][y]!=INF){
			if(la[x]+lb[y]==dist[x][y]){
				vb[y]=1;
				if(!match[y]||dfs(match[y])){
					match[y]=x;
					return 1;
				}
			}
		}
	}
	return 0;
}

int KM(){
	for(int i=1;i<=n;i++){
		la[i]=-INF;
		for(int j=1;j<=n;j++){
			if(dist[i][j]!=INF)la[i]=max(la[i],dist[i][j]);
		}
		lb[i]=0;
	}
	for(int i=1;i<=n;i++){
		while(1){
			memset(va,0,sizeof(va));
			memset(vb,0,sizeof(vb));
			delta=INF;
			if(dfs(i)) break;
			for(int j=1;j<=n;j++){
				if(!va[j]) continue;
				for(int k=1;k<=n;k++){
					if(!vb[k]&&dist[j][k]!=INF){
						delta=min(delta,la[j]+lb[k]-dist[j][k]);
					}
				}
			}
			if(delta==INF) return -1;
			for(int j=1;j<=n;j++){
				if(va[j]) la[j]-=delta;
				if(vb[j]) lb[j]+=delta;
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		ans+=dist[match[i]][i];
	}
	return ans;
}

int main() {

}

