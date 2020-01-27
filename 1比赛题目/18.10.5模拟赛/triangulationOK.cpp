//将每一个三角形看做一个节点，相邻的三角形之间连边
//连边之后会形成二叉树
//答案即为树的直径+1 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 500005
#define INF 0x7f7f7f7f
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
int n;
struct edge{//记录每一条边 
	int u;
	int v;
	int i;//属于的三角形编号 
	edge(){
		
	}
	edge(int from,int to,int id){
		if(from>to) swap(from,to);
		u=from;
		v=to;
		i=id;
	}
	friend bool operator <(edge x,edge y){
		if(x.u==y.u){
			if(x.v==y.v) return x.i<y.i;
			else return x.v<y.v;
		}else return x.u<y.u;
	}
}a[maxn];
int tot=0;
void add_edge(int u,int v,int i){
	if(u>v) swap(u,v); 
	if(v==u+1||(u==1&&v==n) )return;
	a[++tot]=edge(u,v,i);
} 

vector<int>E[maxn];
struct node{
	int x;
	int t;
	node(){
		
	}
	node(int u,int d){
		x=u;
		t=d;
	}
};
int used[maxn];
node bfs(int s){
	memset(used,0,sizeof(used));
	queue<node>q;
	q.push(node(s,0));
	node now;
	node ans=node(0,0);
	while(!q.empty()){
		now=q.front();
		q.pop();
		int x=now.x;
		used[x]=1;
		if(now.t>ans.t){
			ans.x=now.x;
			ans.t=now.t;
		}
		int s=E[x].size();
		for(int i=0;i<s;i++){
			int y=E[x][i];
			if(!used[y]){
				q.push(node(y,now.t+1));
			}
		}
	}
	return ans;
}
int main(){
	int p,q,r;
	n=qread();
	for(int i=1; i<=n-2; i++) {
//		scanf("%d %d %d",&p,&q,&r);
		p=qread();
		q=qread();
		r=qread();
		add_edge(p,q,i);
		add_edge(p,r,i);
		add_edge(r,q,i);
	}
	sort(a+1,a+1+tot);
	for(int i=1;i<tot;i++){
		if(a[i].u==a[i+1].u&&a[i].v==a[i+1].v){
//			printf("(%d,%d)",a[i].i,a[i+1].i);
			E[a[i].i].push_back(a[i+1].i);
			E[a[i+1].i].push_back(a[i].i);
		}
	}
	node t1=bfs(1);
	node t2=bfs(t1.x);
	printf("%d\n",t2.t+1);
}

