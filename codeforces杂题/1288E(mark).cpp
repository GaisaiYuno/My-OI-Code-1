#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 300000
#define maxm 300000 
using namespace std;
int n,m;
struct fenwick_tree{
	int c[maxn+maxm+5];
	inline int lowbit(int x){
		return x&(-x);
	}
	void update(int x,int v){
		for(int i=x;i<=n+m;i+=lowbit(i)) c[i]+=v;
	}
	int sum(int x){
		int ans=0; 
		for(int i=x;i>=1;i-=lowbit(i)) ans+=c[i];
		return ans;
	}
}T;

int minp[maxn+5],maxp[maxn+5];
int pos[maxn+maxm+5];
int main(){
	int x;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		pos[i]=i+m;
		T.update(pos[i],1);
		minp[i]=maxp[i]=i; 
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		minp[x]=1;//如果收到过信息,最小值一定是1,否则是i 
		maxp[x]=max(maxp[x],T.sum(pos[x]));//i的位置一定在自己收到信息之前达到最大值
		T.update(pos[x],-1);
		pos[x]=m-i+1; //移到前面，注意越早收信的会排在越后面,所以是m-i+1 
		T.update(pos[x],1);
	}
	for(int i=1;i<=n;i++) maxp[i]=max(maxp[i],T.sum(pos[i]));//对于一直没有收到信息的,更新最大值 
	for(int i=1;i<=n;i++) printf("%d %d\n",minp[i],maxp[i]);
}

