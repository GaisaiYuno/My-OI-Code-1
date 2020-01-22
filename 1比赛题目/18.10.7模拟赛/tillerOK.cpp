//单调队列优化dp
//dp[i]表示1~i划分的段数 
//dp[i]=min(dp[j])+1 j<i-l&& [j+1,i]的最大值-最小值<s
//用单调队列维护 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<deque>
#define INF 0x7f7f7f7f
#define maxn 100005
#define maxlog 32
using namespace std;
int n,l,s;
int a[maxn];
int st_max[maxn][maxlog];
int st_min[maxn][maxlog];
void init(){
	for(int i=1;i<=n;i++){
		st_max[i][0]=st_min[i][0]=a[i];
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<(j-1))<=n;i++){
			st_max[i][j]=max(st_max[i][j-1],st_max[i+(1<<(j-1))][j-1]);
			st_min[i][j]=min(st_min[i][j-1],st_min[i+(1<<(j-1))][j-1]); 
		}
	}
}
int query(int l,int r){
	int k=log2(r-l+1);
	return max(st_max[l][k],st_max[r-(1<<k)+1][k])-min(st_min[l][k],st_min[r-(1<<k)+1][k]);
}

struct node{
	int v;
	int i;
	node(){
		
	}
	node(int value,int pos){
		v=value;
		i=pos;
	}
};
deque<node>q;
int dp[maxn];
int main(){
	scanf("%d %d %d",&n,&s,&l);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	init();
	memset(dp,0x7f,sizeof(dp));
	dp[0]=0;
	for(int i=l;i<=n;i++){
		while(!q.empty()&&q.back().v>dp[i-l]) q.pop_back();
		q.push_back(node(dp[i-l],i-l));
		while(!q.empty()&&(i-q.front().i<l||query(q.front().i+1,i)>s)){
			              //区间太小        //区间最大值-最小值>s 
			q.pop_front();
		}
		if(!q.empty()) dp[i]=min(dp[i],q.front().v+1);
	}
	if(dp[n]>=INF) printf("-1\n");
	else printf("%d\n",dp[n]);
} 
