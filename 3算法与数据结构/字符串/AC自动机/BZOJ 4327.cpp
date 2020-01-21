#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#define maxn 1000006
#define maxl 10000006
using namespace std;
int len[maxn];
struct AC_automaton {
	int c[maxn][5];
	int fail[maxn];
	int last[maxn];//第i个串的结尾对应trie节点 
	int match[maxn];//标记trie第i个节点是否匹配 
	int fa[maxn]; //第i个节点在trie上的父亲 
	int size;

	inline int get_id(char ch) {
		if(ch=='N') return 0;
		if(ch=='S') return 1;
		if(ch=='W') return 2;
		if(ch=='E') return 3;
		else return -1;
	}

	void insert(char *s,int id) {
		int n=len[id];
		int now=0;
		for(int i=1; i<=n; i++) {
			int v=get_id(s[i]);
			if(!c[now][v]){
				c[now][v]=++size;
				fa[size]=now;
			}
			now=c[now][v];
		}
		last[id]=now;
	}

	void build() {
		queue<int>q;
		for(int i=0; i<=3; i++) {
			if(c[0][i]) {
				fail[c[0][i]]=0;
				q.push(c[0][i]);
			}
		}
		while(!q.empty()) {
			int now=q.front();
			q.pop();
			for(int i=0; i<=3; i++) {
				if(c[now][i]) {
					fail[c[now][i]]=c[fail[now]][i];
					q.push(c[now][i]);
				} else c[now][i]=c[fail[now]][i];
			}
		}
	}
	
	void do_match(char *s){
		int n=strlen(s+1);
		int now=0;
		for(int i=1;i<=n;i++){
			int v=get_id(s[i]);
			now=c[now][v];
			for(int j=now;j;j=fail[j]){//沿着fail指针跳，路上的每个节点都可以匹配前缀 
				if(match[j]) break;//保证每个节点只被标记一次 
				match[j]=1;
			}
		}
	} 
	
	int query(int len,int id){
		int ans=len;
		for(int i=last[id];i;i=fa[i]){//从后往前跳 
			if(match[i]) return ans;
			ans--;
		}
//		return 0;
	}
}A;

int n,m;
char s[maxl];
char a[maxn];
int main(){
	scanf("%d %d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=m;i++){
		scanf("%s",a+1);
		len[i]=strlen(a+1);
		A.insert(a,i);
	}
	A.build();
	A.do_match(s);
	for(int i=1;i<=m;i++){
		printf("%d\n",A.query(len[i],i));
	}
}

