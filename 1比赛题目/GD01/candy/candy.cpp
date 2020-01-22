#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector> 
#define mod 1000000007
#define maxn 5000
using namespace std;
typedef long long ll;

int n,m,k;
vector<int>D[maxn+5];
int in[maxn+5];
ll f[maxn+5][maxn+5],sum[maxn+5][maxn+5];
void add_edge(int u,int v){
	D[u].push_back(v);
	in[v]++;
}
ll topo_sort(){
	queue<int>q;
	for(int i=1;i<=n+1;i++){
		if(!in[i]){
			q.push(i);
			for(int j=1;j<=n+1;j++) f[i][j]=1;
			for(int j=1;j<=n;j++) sum[i][j]=(sum[i][j-1]+f[i][j])%mod;
			
		}
	}
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<(int)D[x].size();i++){
			int y=D[x][i];
			for(int j=1;j<=n;j++){
				f[y][j]+=sum[x][j+1];
				f[y][j]%=mod;
			}
			for(int j=1;j<=n;j++){
				sum[y][j]=(sum[y][j-1]+f[y][j])%mod;
			}
			in[y]--;
			if(in[y]==0) q.push(y);
		}
	}	
	return f[n+1][1];
}

int l[maxn+5],r[maxn+5];
int main(){
	freopen("candy.in","r",stdin); 
	freopen("candy.out","w",stdout);
	int x,y;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n;i++){
		l[i]=1;
		r[i]=n;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		x++;
//		if(i+1<=n) add_edge(i+1,x);
//		if(i-1>=1) add_edge(i-1,x); 
	} 
	for(int i=1;i<=k;i++){
		scanf("%d",&y);
		y++;
//		if(i+1<=n) add_edge(y,i+1);
//		if(i-1>=1) add_edge(y,i-1);
	}
//	for(int i=1;i<=n;i++) add_edge(i,n+1);
//	printf("%lld\n",topo_sort()-1);	
	ll ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(j==i) continue;
			for(int k=1;k<=n;k++){
				l[k]=1;
				r[k]=n;
			}
			l[x]=r[x]=j;
			l[y]=r[y]=j;
			if(x+1<=n) l[x+1]=i+1;
			if(x-1>=1) r[x+1]=i+1;
			if(y+1<=n) r[y+1]=j-1;
			if(y-1>=1) r[y-1]=j-1;
			ll sum=1;
			for(int k=1;k<=n;k++){
				sum*=max(r[k]-l[k]+1,0);
				sum%=mod;
			}
			ans=(ans+sum)%mod;
		}
	}
	printf("%lld\n",ans);
} 
