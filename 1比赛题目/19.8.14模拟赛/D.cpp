#pragma GCC optimize(3)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 100000
using namespace std;
typedef long long ll;
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
inline void qread(ll &x){
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
inline void qprint(long long x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n;
struct edge{
	int from;
	int to;
	ll len;
	int next;
}E[maxn*2+5];
int sz=1;
int ehead[maxn+5];
void add_edge(int u,int v,ll w){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].len=w;
	E[sz].next=ehead[u];
	ehead[u]=sz;
}

int top=0;
int deep[maxn+5];
ll dist[maxn+5];
void dfs1(int x,int fa){
	deep[x]=deep[fa]+1;
	for(int i=ehead[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dist[y]=dist[x]+E[i].len;
			dfs1(y,x);
			
		}
	}
}

ll dp[maxn+5];
ll w[maxn+5];
ll v[maxn+5];
int head,tail;
int q[maxn*20+5];
vector<int>delhead[maxn+5];
vector<int>deltail[maxn+5];
inline double get_up(int j,int k){
	return dp[k]-dp[j];
}
inline double get_down(int j,int k){
	return dist[k]-dist[j];
}

int bin_search(int l,int r,double k){
	int ans=r;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(get_up(q[mid],q[mid+1])/get_down(q[mid],q[mid+1])>=k){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	return ans;
}

void dfs2(int x,int fa){
//	while(head<tail&&get_up(q[head],q[head+1])/get_down(q[head],q[head+1])<v[x]){
//		delhead[x].push_back(q[head]);
//		head++;
//	} 
	if(x==3){
		x=3;
	}
	int f;
	f=q[bin_search(head,tail,v[x])];
	if(x!=1) dp[x]=dp[f]+w[x]+v[x]*(dist[x]-dist[f]);
	printf("best=%d dp[%d]=%lld\n",f,x,dp[x]);
	while(head<tail&&get_up(q[tail-1],q[tail])/get_down(q[tail-1],q[tail])>get_up(q[tail],x)/get_down(q[tail],x)){
		deltail[x].push_back(q[tail]);
		tail--;
	}
	//不要出队，二分找到插入点，然后修改top即可
	//队列里的元素不用删除 
	//回溯的时候恢复top 
	q[++tail]=x;

	for(int i=ehead[x];i;i=E[i].next){
		int y=E[i].to;
		if(y!=fa){
			dfs2(y,x);
		}
	}
	
	tail--;
	for(int i=deltail[x].size()-1;i>=0;i--){
		q[++tail]=deltail[x][i];
	}
//	deltail[x].clear();
//	for(int i=delhead[x].size()-1;i>=0;i--){
//		q[--head]=delhead[x][i];
//	}
//	delhead[x].clear();
}

int main(){
//#ifdef LOCAL
//	freopen("1.in","r",stdin);
//	freopen("1.out","w",stdout); 
//#endif
	int aa,bb;
	long long cc;
	qread(n);
	for(int i=1;i<n;i++){
		qread(aa);
		qread(bb);
		qread(cc);
		add_edge(aa,bb,cc);
		add_edge(bb,aa,cc);
	}
	for(int i=2;i<=n;i++){
		qread(w[i]);
		qread(v[i]);
	}
	dfs1(1,0);
	memset(dp,0x3f,sizeof(dp));
	dp[1]=0;
	head=1,tail=0;
	dfs2(1,0);
	for(int i=2;i<=n;i++){
		qprint(dp[i]);
		putchar(' ');
	}
}
