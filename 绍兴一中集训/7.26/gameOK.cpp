//有后效性，bfs多次迭代转移(类似spfa) 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 30000
#define maxm 100000
#define maxq 30000000
#define min(a,b) ((a)>(b)?(b):(a)) //卡常 
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
} 
int n,m,lim;
int a[maxn+5];
struct edge{
	int from;
	int to;
	int len;
	int next;
}E[maxm*2+5];
int sz=1;
int head[maxn+5];
void add_edge(int u,int v,int w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=head[u];
	head[u]=sz;
}

struct node{
	int x;
	int hp;
	int tim;
	node(){
		
	}
	node(int _x,int _hp,int _tim){
		x=_x;
		hp=_hp;
		tim=_tim;
	}
};
struct fast_queue{
	node q[maxq+5];
	int head;
	int tail;
	inline void clear(){
		head=1;
		tail=0;
	}
	inline bool empty(){
		return head>tail;
	}
	inline void push(node x){
		q[++tail]=x;
	}
	inline void pop(){
		head++;
	}
	inline node front(){
		return q[head];
	}
	fast_queue(){
		clear();
	}
}q;

int maxhp[maxn+5];
int main(){
//	freopen("excitement10.in","r",stdin);
	int u,v,w;
	qread(n);
	qread(m);
	qread(lim);
	for(int i=1;i<=n;i++) qread(a[i]);
	for(int i=1;i<=m;i++){
		qread(u);
		qread(v);
		qread(w);
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	q.push(node(1,lim,0));
	int ans=-1;
	while(!q.empty()){
		node now=q.front();
		int x=now.x;
		q.pop();
		if(now.x==n){
			ans=now.tim;
			break;
		}
		if(now.hp>maxhp[x]){//重要剪枝，当前值>之前经过x的最大值 
			maxhp[x]=now.hp;
			now.hp=min(now.hp+a[x],lim);
			for(int i=head[x];i;i=E[i].next){
				int y=E[i].to;
				if(now.hp-E[i].len>maxhp[y]){
					q.push(node(y,now.hp-E[i].len,now.tim+1));
				}
			}
		}
	}
	printf("%d\n",ans);
}
