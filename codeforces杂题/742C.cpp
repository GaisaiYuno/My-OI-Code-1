#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 105
using namespace std;
int n; 
int dyf[maxn];//crush
long long t[maxn];
int used[maxn];
struct edge{
	int from;
	int to;
	int next;
}E[maxn<<1];
int head[maxn];
int sz=0;
void add_edge(int u,int v){
	sz++;
	E[sz].from=u;
	E[sz].to=v;
	E[sz].next=head[u];
	head[u]=sz;
}
inline long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}
inline long long lcm(long long a,long long b){
	return a/gcd(a,b)*b;
}
int dfs(int x,int s,int cnt){
	used[x]=1;
	for(int i=head[x];i;i=E[i].next){
		int y=E[i].to;
		if(used[y]&&y!=s){
			return -1;
		}else if(used[y]&&y==s){
			return cnt;
		}else{
			return dfs(y,s,cnt+1);
		}
	} 
}

int ring_cnt=0;
int main(){
	int f;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&dyf[i]);
		add_edge(i,dyf[i]);
	}
	for(int i=1;i<=n;i++){
		if(!used[i]){
			int ring_sz=dfs(i,i,1);
			if(ring_sz!=-1){
				if(ring_sz%2==0) t[++ring_cnt]=ring_sz/2;
				else t[++ring_cnt]=ring_sz; 
			}else{
				printf("-1\n");
				return 0;
			}
			
		}
	}
	long long ans=1;
	for(int i=1;i<=ring_cnt;i++){
		ans=lcm(ans,t[i]);
	}
	printf("%I64d\n",ans);
} 
