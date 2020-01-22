#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 500005
#define INF 0x3f3f3f3f3f3f3f3f 
using namespace std;
int n,d;
int k;
int x[maxn];
int a[maxn];
long long dp[maxn];
struct node{
    long long v;
    int x;
    node(){
        
    }
    node(long long val,int pos){
        v=val;
        x=pos;
    }
};
struct deque{
    int head,tail;
    node Q[maxn];
    node front(){
        return Q[head];
    }
    node back(){
        return Q[tail-1];
    }
    void push_back(node p){
        Q[tail]=p;
        tail++;
    }
    void pop_front(){
        head++;
    }
    void pop_back(){
        tail--;
    }
    bool empty(){
        if(head<tail) return 0;
        else return 1;
    }
    deque(){
        head=tail=0;
    }
    void clear(){
        head=tail=0;
    }
}q;
int check(int g){
	int l0,r0; 
	if(g<d) {
		l0=d-g;
		r0=d+g;
	} else {
		l0=1;
		r0=d+g;
	}
	int j=0;
	memset(dp,-0x3f,sizeof(dp));
	q.clear();
	dp[0]=0;
	for(int i=1;i<=n;i++){
		while(x[i]-x[j]>=l0){
			while(!q.empty()&&dp[j]>=q.back().v) q.pop_back();
			q.push_back(node(dp[j],x[j]));
			j++;
		}
		while(!q.empty()&&x[i]-q.front().x>r0) q.pop_front();
		if(q.empty()) dp[i]=-INF;
		else dp[i]=q.front().v+a[i];
		if(dp[i]>=k) return 1; 
	}
	return 0;
}
int main(){
	scanf("%d %d %d",&n,&d,&k);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x[i],&a[i]);
	}
	x[0]=0;
	int l=0,r=x[n];
	int mid;
	int ans=-1;
	while(l<=r){
		mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	printf("%d\n",ans);
}
//Dedicated to Selina 
