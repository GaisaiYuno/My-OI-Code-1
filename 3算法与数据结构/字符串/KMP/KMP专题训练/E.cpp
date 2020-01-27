//http://www.cnblogs.com/dedicatus545/p/8903324.html 
/*
ģ�崮����: 
1.һ��ģ�崮A��Ҫ����ı���B�Ĺ���ǰ��׺
2.���һ��ģ�崮A����һ��ģ�崮B��Ҳ����B���Ը���A������ôB�Ǳ�A���ŵ�һ����
3.���ģ�崮A������ȫ�����ı���B����ôA��B�е�ƥ��λ�ã����տ�ͷ�㣩֮��Ŀո������ᳬ��A�ĳ���

fail��(nex[i]->i����)����:
1.��x����ǵ�y�����ȣ���ôy�����ǰ׺��һ������ǰ��׺Ϊx�����ǰ׺
2.����ͬһ�����ڵ���������ǰ׺���ܻ�����ȫ����(����������1) 
 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define maxn 500000
using namespace std;
struct edge{
	int from;
	int to;
	int next;
}E[maxn*2+5];
int sz=1;
int head[maxn+5];
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

int n;
char s[maxn+5];
int nex[maxn+5];

struct list{
	int pre[maxn+5],nex[maxn+5];
	int mv;
	void ini(int n){
		mv=1;
		for(int i=1;i<=n;i++){
			pre[i]=i-1;
			nex[i]=i+1;
		}
	}
	void del(int x){
		pre[nex[x]]=pre[x];
		nex[pre[x]]=nex[x];
		mv=max(mv,nex[x]-pre[x]);
		pre[x]=nex[x]=0;
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			del(y);
		}
	}
	inline int query(){
		return mv;
	}
}S;
int ans=0;
bool mark[maxn+5];
void dfs(int x){//xʵ������ĳ��nex,����ǰ׺(ģ�崮)���� 
	int to;
	if(S.query()<=x){//ģ�崮����3 
		ans=x;
		return;
	}
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(mark[y]) to=y;
		else S.del(y);//����fail��������2,�Ѳ���ƥ��Ĳ���ȥ�����õ�����ƥ��λ��֮��������� 
	}
	dfs(to);
} 
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=2,j=0;i<=n;i++){
		while(j>0&&s[j+1]!=s[i]) j=nex[j];
		if(s[j+1]==s[i]) j++;
		nex[i]=j;
	}
	for(int i=1;i<=n;i++) add_edge(nex[i],i);//����fail�� 
	S.ini(n);
	for(int i=n;i>0;i=nex[i]) mark[i]=1;//ģ�崮����1 
	dfs(0);
	printf("%d\n",ans);
}

