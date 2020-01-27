/*
Problem:Ææ¹ÖµÄÓÎÏ· 
Source:http://119.29.55.79/contest/22/problem/2
Description:
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1605
#define maxc 45
#define maxm 10005
#define INF 0x3f3f3f3f3f3f3f3f
#define int long long
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


int T;
int n,m;
long long a[maxc][maxc];
struct edge{
	int from;
	int to;
	int next;
	long long flow;
}E[maxm<<1];
int sz=1;
int head[maxn];

void add_edge(int u,int v,long long w){
//	printf("%d->%d %d\n",u,v,w);
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	E[sz].flow=w;
	head[u]=sz;
	sz++;
	E[sz].from=v;
	E[sz].to=u;
	E[sz].next=head[v];
	E[sz].flow=0;
	head[v]=sz;
}

struct queue{
	int q[maxn*5];
	int head=0,tail=0;
	bool empty(){
		return head>=tail;
	}
	int front(){
		return q[head];
	}
	void push(int x){
		q[tail++]=x;
	} 
	void pop(){
		head++;
	} 
	void clear(){
		head=tail=0;
	}
}q;
int deep[maxn];
bool bfs(int s,int t){
	q.clear();
	memset(deep,0,sizeof(deep));
	deep[s]=1;
	q.push(s);
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=head[x];i;i=E[i].next){
			int y=E[i].to;
			if(E[i].flow&&!deep[y]){
				deep[y]=deep[x]+1;
				if(y==t) return 1;
				q.push(y);
			}
		}
	}
	return 0;
}

long long dfs(int x,int t,long long minf){
	if(x==t) return minf;
	long long k,rest=minf;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(E[i].flow&&deep[y]==deep[x]+1){
			k=dfs(y,t,min(rest,E[i].flow));
			if(k==0) deep[y]=0;
			rest-=k;
			E[i].flow-=k;
			E[i^1].flow+=k;
			if(rest==0) break;
		}
	}
	return minf-rest;
}

long long dinic(int s,int t){
	long long now=0,sum=0;
	while(bfs(s,t)){
		while(now=dfs(s,t,INF)) sum+=now;
	}
	return sum;
}

int mark[maxc][maxc];
const int walkx[4]={1,-1,0,0},walky[4]={0,0,1,-1};
inline int get_id(int x,int y){
	return (x-1)*m+y;
}
int check(long long last){
	int s=0,t=n*m+1;
	memset(head,0,sizeof(head));
	sz=1;
	long long tot=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(mark[i][j]){
				add_edge(s,get_id(i,j),last-a[i][j]);
				tot+=last-a[i][j];
				for(int k=0;k<4;k++){
					int x=i+walkx[k];
					int y=j+walky[k];
					if(x>=1&&x<=n&&y>=1&&y<=m){
						add_edge(get_id(i,j),get_id(x,y),INF);
					}			
				}
			}else add_edge(get_id(i,j),t,last-a[i][j]);
		}
	}
//	printf("judgeing... last=%lld there are %d edges\n",last,sz); 
	if(tot==dinic(s,t)) return 1;
	else return 0;
} 

int bcnt,wcnt;
long long bsum,wsum;
void ini(){
	bcnt=wcnt=bsum=wsum=0;
	memset(mark,0,sizeof(mark));
	sz=1;
	memset(E,0,sizeof(E));
	memset(head,0,sizeof(head));
}
#undef int
int main(){
#define int long long
#ifdef FILE_IO
	freopen("2.in","r",stdin);
#endif
	long long mv=0;
	qread(T);
	for(int c=1;c<=T;c++){
		qread(n);
		qread(m);
		ini();
		mv=0;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				qread(a[i][j]);
				mv=max(mv,a[i][j]);
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if((i+j)%2==1){
					mark[i][j]=1;
					bcnt++;
					bsum+=a[i][j];
				}else{
					wcnt++;
					wsum+=a[i][j];
				}
			}
		}
		if(wcnt==bcnt){
			if(wsum!=bsum){
				printf("-1\n");
			}else{
				long long l=mv,r=2e9,ans;
				while(l<=r){
					long long mid=(l+r)>>1;
					if(check(mid)){
						ans=mid;
						r=mid-1;
					}else l=mid+1;
				}
				printf("%lld\n",(ans*n*m-bsum-wsum)/2);
			}
		}else{
			long long x=(wsum-bsum)/(wcnt-bcnt);
			if(x>=mv&&check(x)){
				printf("%lld\n",(x*n*m-bsum-wsum)/2);
			}else{
				printf("-1\n"); 
			}
		}
	}
}


