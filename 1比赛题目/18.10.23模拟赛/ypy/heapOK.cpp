//������ʵ�����ϵ�LIS����Ҷ�ӽڵ�����ڵ��γ�LIS
//����LIS��O(nlogn)�㷨���õ������飬��multiset��ÿ���ڵ�ά������һ�����飬�洢�����ڵ�ֵ
//���ϵ�ͬʱ�ϲ�����multiset��������ʽ�ϲ� 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<set>
#define maxn 200005
using namespace std;
int n;
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int head[maxn];
int sz;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
} 

int a[maxn];
multiset<int>s[maxn];
void merge(int x,int y){//����ʽ�ϲ� 
	if(s[x].size()<s[y].size()) swap(s[x],s[y]);
	for(multiset<int>::iterator it=s[y].begin();it!=s[y].end();it++){
		s[x].insert(*it);
	}
}
void dfs(int x,int fa){
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs(y,x);
			merge(x,y); 
		}
	}
	multiset<int>::iterator it=s[x].lower_bound(a[x]);
	if(it==s[x].end()) s[x].insert(a[x]);
	else{
		s[x].erase(it);
		s[x].insert(a[x]);
	}
}
int main(){
	int fa;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[i],&fa);
		if(fa!=0){
			add_edge(i,fa);
			add_edge(fa,i); 
		} 
	}
	dfs(1,0);
	printf("%d\n",s[1].size());
} 
