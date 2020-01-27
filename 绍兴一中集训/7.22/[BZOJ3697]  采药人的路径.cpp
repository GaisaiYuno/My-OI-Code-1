#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100000 
using namespace std;
int n;
struct edge{
	int from;
	int to;
	int len;
	int next;
}E[maxn*2+5];
int esz=1;
int head[maxn*2+5];
void add_edge(int u,int v,int w){
	esz++;
	E[esz].from=u;
	E[esz].to=v;
	E[esz].len=w;
	E[esz].next=head[u];
	head[u]=esz;
}

int root=0;
int sum;
bool vis[maxn+5];
int sz[maxn+5];
int f[maxn+5];
void get_root(int x,int fa){
	sz[x]=1;
	f[x]=0;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa&&!vis[y]){
			get_root(y,x);
			sz[x]+=sz[y];
			f[x]=max(f[x],sz[y]);
		}
	}
	f[x]=max(f[x],sum-sz[x]);
	if(f[x]<f[root]) root=x;
}
/*
����0��ȨΪ-1��1��ȨΪ1.�ӷ������Ŀ�ʼ�����ϵ��¿�ʼǰ׺
���Ƿ��֣�����·���ܺϲ������ҽ�����һ��·���ϴ�����Ϣ�㣬��������·���ĳ��Ⱥ�Ϊ�෴�� 
���Ǽ�A[i]Ϊ����Ϣ��ģ�ֵΪi�ĸ���
��B[i]Ϊ����Ϣ��ģ�ֵΪi�ĸ���
��ôͳ�ƴ�ʱ��һ����u�Ĺ��׾���A[-dist[x]]+B[-dist[x]]
*/
int spcnt=0; 
int sza,szb;
struct arr {
    int cnt[maxn *2+5];
    inline int & operator [] (const int index) { 
		return cnt[index + maxn]; 
	}
} cnta,cntb,mark;//��¼x���ڵ㵽��ǰ�������ĵ�distֵ������� 
int dista[maxn+5],distb[maxn+5];

void get_dist(int x,int fa,int d){
	if(mark[d]){//������ڵ㵽��ǰ����������distֵΪd�ĵ㣬����������֮��һ������һ����Ϣ�� 
		//������ЩB�ൽ�������ĵ�·����ֻ�з������ĵ�ֵ�ǵ���B��
		//���ʱ��ͻ������� 
		if(d==0&&mark[d]==1) spcnt++; //ֻ�з������ĵ�ֵ(0)�ǵ���B�� 
		cntb[d]++;
		distb[++szb]=d;
	}else{
		cnta[d]++;
		dista[++sza]=d;	
	}
	mark[d]++;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa&&!vis[y]) get_dist(y,x,d+E[i].len);
	} 
	mark[d]--;
}
long long calc(int x,int d){
	if(d){
		dista[++sza]=0;
		mark[0]++;
	}
	get_dist(x,0,d);
	if(d) mark[0]--;
	long long ansa=0,ansb=0;
	if(d==0) ansa-=spcnt;//ֻҪ�������ʱ������һ�� 
	for(int i=1;i<=szb;i++){
		ansa+=cnta[-distb[i]];
		ansb+=cntb[-distb[i]];
		if(distb[i]==0) ansb--; 
	}
	ansb/=2;
	for(int i=1;i<=sza;i++) cnta[dista[i]]=0;
	for(int i=1;i<=szb;i++) cntb[distb[i]]=0;
	sza=szb=0;
	spcnt=0;
	return ansa+ansb;
}

long long ans;
void solve(int x){
	vis[x]=1;
	ans+=calc(x,0);
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(!vis[y]){
			ans-=calc(y,E[i].len);
			root=0;
			sum=sz[y];
			f[root]=n+1;
			get_root(y,0);
			solve(root);
		}
	}
}

int main(){
	int u,v,w;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d %d %d",&u,&v,&w);
		if(w==1){
			add_edge(u,v,1);
			add_edge(v,u,1);
		}else{
			add_edge(u,v,-1);
			add_edge(v,u,-1);
		}
	}
	root=0;
	sum=n;
	f[root]=n+1;
	get_root(1,0);
	solve(root); 
	printf("%lld\n",ans);
}
