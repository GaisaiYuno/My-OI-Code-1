#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#define maxn 1000000
#define mod 998244353
using namespace std;
int n,m,k;
struct block{
	int x1;
	int y1;
	int x2;
	int y2;
}a[maxn+5];
vector<int>E[maxn*2+5];
int in[maxn*2+5];
void add_edge(int u,int v){
	E[u].push_back(v);
	in[v]++;
} 

queue<int>q;

long long dp[maxn*2+5];
long long calc(int s,int t){
	q.push(s);
	dp[s]=1;
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int i=0;i<E[x].size();i++){
			int y=E[x][i];
			in[y]--;
			dp[y]+=dp[x];
			dp[y]%=mod;
			if(in[y]==0){
				q.push(y);
			}
		}
	}
	return dp[t];
}
int main(){
#ifndef LOCAL
	freopen("ski.in","r",stdin);
	freopen("ski.out","w",stdout);
#endif
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=k;i++){
		scanf("%d %d %d %d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	if(k==0){
		printf("1\n");
		return 0;
	}
	int s=k*2+1;
	int t=k*2+2;
	for(int i=1;i<=k;i++){
		add_edge(s,i);
	}
	for(int i=k+1;i<=k*2;i++){
		add_edge(i,t);
	}
	for(int i=1;i<=k;i++){
		if(a[i].x1>1&&a[i].y2<m) add_edge(i,i+k);
		if(a[i].y1>1&&a[i].x2<n) add_edge(i,i+k); 
	}
	for(int i=1;i<=k;i++){
		for(int j=i+1;j<=k;j++){
			if(a[i].x2<a[j].x2&&a[i].y2<=a[j].y2) add_edge(i+k,j);
		}
	}
	printf("%lld\n",calc(s,t));
}
