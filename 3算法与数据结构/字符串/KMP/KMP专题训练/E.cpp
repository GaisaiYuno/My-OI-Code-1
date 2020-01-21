//http://www.cnblogs.com/dedicatus545/p/8903324.html 
/*
模板串性质: 
1.一个模板串A是要求的文本串B的公共前后缀
2.如果一个模板串A有另一个模板串B（也就是B可以覆盖A），那么B是比A更优的一个解
3.如果模板串A可以完全覆盖文本串B，那么A在B中的匹配位置（按照开头算）之间的空格数不会超过A的长度

fail树(nex[i]->i连边)性质:
1.点x如果是点y的祖先，那么y代表的前缀的一个公共前后缀为x代表的前缀
2.不在同一子树内的两点代表的前缀不能互相完全覆盖(不满足性质1) 
 
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
void dfs(int x){//x实际上是某个nex,代表前缀(模板串)长度 
	int to;
	if(S.query()<=x){//模板串性质3 
		ans=x;
		return;
	}
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(mark[y]) to=y;
		else S.del(y);//根据fail树的性质2,把不能匹配的部分去掉，得到两个匹配位置之间的最大距离 
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
	for(int i=1;i<=n;i++) add_edge(nex[i],i);//建立fail树 
	S.ini(n);
	for(int i=n;i>0;i=nex[i]) mark[i]=1;//模板串性质1 
	dfs(0);
	printf("%d\n",ans);
}

