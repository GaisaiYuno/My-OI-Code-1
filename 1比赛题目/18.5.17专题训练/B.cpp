//廝寄社520酔赤! 
//  *　　 *　　 *　　　* 
// *　　　　* *　　　　 * 
//  *   　　 *　　　　　* 
//　 *  I　LOVE　OI　 * 
//　   *　　　　　　* 
//　　   *　　　　* 
//         *　　* 
//　　　　   *　　　
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2005
#define maxq 1000005
#define INF 99999999
using namespace std;
int dp[maxn][maxn];
struct deque {
	int q[maxq];
	int head,tail;
	deque() {
		memset(q,0,sizeof(q));
		head=1;
		tail=0;
	}
	void clear() {
		head=1;
		tail=0;
	}
	int empty() {
		return (tail-head+1==0);
	}
	int front() {
		if(empty()) return -INF;
		return q[head];
	}
	void push(int x) {
		while(q[tail]<x&&head<=tail) tail--;
		q[++tail]=x;
	}
	void pop(int x) {
		if(q[head]==x) head++;
	}
};
struct date {
	int ap;
	int bp;
	int as;
	int bs;
} day[maxn];
deque q1,q2;
int maxc;
int t,maxp,w;
//dp[i][j]=max(dp[i][k]+ap[x]*(k-j),dp[i][k]+bp[x]*(k-j))
void buy(int i,int j,int k) {
	if(k+1>day[i].as) q1.pop(dp[j][k-day[i].as]+day[i].ap*(k-day[i].as));
	q1.push(dp[j][k]+day[i].ap*k);
}
void sell(int i,int j,int k) {
	q2.pop(dp[j][k+1]+day[i].bp*(k+1));
	if(k+day[i].bs<maxp) q2.push(dp[j][k+day[i].bs+1]+day[i].bp*(k+day[i].bs+1));
}
void debug() {
	for(int i=1; i<=t; i++) {
		for(int j=0; j<=maxp; j++) {
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}
int main() {
	scanf("%d",&maxc);
	while(maxc--) {
		scanf("%d %d %d",&t,&maxp,&w);
		q1.clear();
		q2.clear();
		for(int i=1; i<=t; i++) {
			scanf("%d %d %d %d",&day[i].ap,&day[i].bp,&day[i].as,&day[i].bs);
		}
		memset(dp,0,sizeof(dp));
		for(int i=1; i<=maxp; i++) dp[0][i]=-INF;
		
		for(int i=1; i<=t; i++) {
			int j=max(i-w-1,0);
			q1.clear();
			q2.clear();
			for(int k=1; k<=min(maxp,day[i].bs); k++) {
				q2.push(dp[j][k]+day[i].bp*k);//沢竃
			}
			for(int k=0; k<=maxp; k++) {
//				dp[i][k]=max(max(dp[i][k],q1.front()-day[i].ap*k),max(dp[i-1][k],q2.front()-day[i].bp*k));
				dp[i][k]=dp[i-1][k];
				dp[i][k]=max(dp[i][k],max(q1.front()-day[i].ap*k,q2.front()-day[i].bp*k));
				buy(i,j,k);
				sell(i,j,k);
//				debug(); 
			}
		}
//		debug();
		int ans=0;
		for(int i=0; i<=maxp; i++) ans=max(ans,dp[t][i]);
		printf("%d\n",ans);
	}
}
