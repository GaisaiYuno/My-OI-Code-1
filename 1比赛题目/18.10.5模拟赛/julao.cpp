#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 50005 
#define maxm 200005
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
char pri[20];
inline void qprint(int x){
	if(x==0){
		putchar('0');
	}else{
		int ptr=0;
		while(x>0){
			pri[++ptr]=x%10+'0';
			x/=10;
		}
		for(int i=ptr;i>=1;i--){
			putchar(pri[i]);
		}
	}
	putchar('\n');
}
int n;
struct edge{
	int from;
	int to;
	int next;
}E[maxm];
int tmp[maxn];
int in[maxn];
int out[maxn];
int ans[maxn];
int head[maxn];
int sz;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}

struct queue{
	int Q[maxm];
	int head;
	int tail;
	queue(){
		head=tail=0;
	}
	void clear(){
		head=tail=0;
//		memset(Q,0,sizeof(Q));
	}
	void push(int x){
		Q[tail++]=x;
	}
	void pop(){
		head++;
	}
	bool empty(){
		return head>=tail;
	}
	int front(){
		return Q[head];
	}
}q;
int bfs(int s){
	q.clear();
//	queue<int>q;
	q.push(s);
	int x,y;
	int cnt=0;
	for(int i=1;i<=n;i++) tmp[i]=in[i];
	while(!q.empty()){
		x=q.front();
		q.pop();
		if(x!=s)cnt++;
		for(int i=head[x];i;i=E[i].next){
			y=E[i].to;
			tmp[y]--;
			if(tmp[y]==0) q.push(y);
		}
	}
	return cnt;
}
int main(){
	freopen("julao.in","r",stdin);
	freopen("julao.out","w",stdout);
	n=qread();
	int x=1;
	for(int i=1;i<=n;i++){
		while(1){
			x=qread();
			if(x==0) break;
			add_edge(x,i);
			in[i]++;
			out[x]++;
		}
	}
	for(int i=1;i<=n;i++){
		if(out[i]){
			ans[i]=bfs(i);
		}
	}
	for(int i=1;i<=n;i++){
		qprint(ans[i]);
	}
}
