/*
Problem:将N个数分成2组,使每组的和尽量相近
Source:常数优化论文 HDU 1171
Algorithm:DP
Description:
多重背包，单调队列优化 
62ms
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 250005 
using namespace std;
struct node{
	int v;
	int i;
	node(){
			
	}
	node(int pos,int val){
		v=val;
		i=pos;
	}
};
struct deque{
	node q[maxn*2];
	int head,tail;
	void clear(){
		head=0,tail=0;
	}
	bool empty(){
		return !(head<tail);
	} 
	node front(){
		return q[head];
	}
	node back(){
		return q[tail-1];
	}
	void push_back(node x){
		q[tail++]=x;
	}
	void pop_back(){
		tail--;
	}
	void pop_front(){
		head++;
	}
	deque(){
		clear();	
	}
}q;

int n,m;
int v[maxn];
int w[maxn];
int c[maxn];
int dp[maxn];
int calc(int i,int u,int k){
	return dp[u+k*v[i]]-k*w[i];
}
int main(){
	while(scanf("%d",&n)!=EOF){ 
		if(n<0) break;
		m=0;
		memset(dp,0xcf,sizeof(dp));
		dp[0]=0; 
		q.clear();
		for(int i=1;i<=n;i++){
			scanf("%d %d",&v[i],&c[i]);
			w[i]=v[i];
			m+=v[i]*c[i];
		}
		for(int i=1;i<=n;i++){
			for(int u=0;u<v[i];u++){
				q.clear();
				int maxp=(m-u)/v[i];
				for(int k=maxp-1;k>=max(maxp-c[i],0);k--){
					while(!q.empty()&&q.back().v<=calc(i,u,k)) q.pop_back();
					q.push_back(node(k,calc(i,u,k)));
				}
				for(int p=maxp;p>=0;p--){
					while(!q.empty()&&q.front().i>p-1) q.pop_front(); 
					if(!q.empty()) dp[u+p*v[i]]=max(dp[u+p*v[i]],q.front().v+p*w[i]);
					if(p-c[i]-1>=0){
						while(!q.empty()&&q.back().v<=calc(i,u,p-c[i]-1)) q.pop_back();
						q.push_back(node(p-c[i]-1,calc(i,u,p-c[i]-1)));
					}
				}
				
			}
		}
		for(int i=m/2;i>=0;i--){
			if(dp[i]>=0){
				printf("%d %d\n",m-dp[i],dp[i]);
				break;
			}
		}
	} 
}
