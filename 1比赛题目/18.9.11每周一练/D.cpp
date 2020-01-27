#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 100005 
using namespace std;
int n;
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int head[maxn];
int size=0;
void add_edge(int u,int v){
	size++;
	E[size].from=u;
	E[size].to=v;
	E[size].next=head[u];
	head[u]=size;
}

int sz[maxn];
double ex[maxn];
void dfs(int x,int fa){
	sz[x]=1; 
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
			sz[x]+=sz[y];
		}
	}
}
void dfs2(int x,int fa){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to; 
		if(y!=fa){
			ex[y]=ex[x]+1+(double)(sz[x]-sz[y]-1)*0.5;
			//���ֱ�ӴӸ��ڵ���ʹ���,ex[y]=ex[x]+1
			//����ȷ��������ֵܽڵ�������ٷ��ʹ���,���ܷ��ʵĽڵ㹲sz[x]-sz[y]-1��
			//��������ɵ�dfs����,ĳ���ֵܽڵ������Լ���ǰ��ĸ���Ϊ1/2
			//�����ܹ���Ϊ1/2(sz[x]-sz[y]-1)
			dfs2(y,x);
		}
	}
}
int main(){
	int p;
	scanf("%d",&n);
	for(int i=2;i<=n;i++){
		scanf("%d",&p);
		add_edge(i,p);
		add_edge(p,i); 
	}
	dfs(1,0);
	ex[1]=1.0;
	dfs2(1,0);
	for(int i=1;i<=n;i++){
		printf("%.7f ",ex[i]);
	}
} 
