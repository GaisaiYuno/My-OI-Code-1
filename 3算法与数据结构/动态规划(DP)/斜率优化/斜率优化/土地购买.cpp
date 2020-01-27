#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 50000
using namespace std;
typedef long long ll;
int n,cnt;
struct land{
	ll len;
	ll wid;
	friend bool operator < (land p,land q){
		if(p.len==q.len) return p.wid<q.wid;
		else return p.len<q.len;
	}
}a[maxn+5],b[maxn+5];


int head,tail;
int q[maxn+5];
ll dp[maxn+5];
inline ll get_up(int j1,int j2){
	return dp[j1]-dp[j2];
}
inline ll get_down(int j1,int j2){
	return b[j2+1].wid-b[j1+1].wid;
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld %lld",&a[i].len,&a[i].wid);
	}
	sort(a+1,a+1+n);
	
	for(int i=1;i<=n;i++){
		while(cnt>0&&b[cnt].wid<=a[i].wid) cnt--;//维护wid单调递减的单调栈 
		b[++cnt]=a[i];
	}
//	printf("%d\n",cnt);
//	for(int i=1;i<=cnt;i++){
//		printf("(%lld,%lld)\n",b[i].len,b[i].wid);
//	}
	n=cnt;
	head=tail=1;
	q[head]=0;
	for(int i=1;i<=n;i++){
		while(head<tail&&1.0*get_up(q[head],q[head+1])/get_down(q[head],q[head+1])<b[i].len) head++;
		dp[i]=dp[q[head]]+b[q[head]+1].wid*b[i].len;
		while(head<tail&&1.0*get_up(q[tail-1],q[tail])/get_down(q[tail-1],q[tail])>1.0*get_up(q[tail],i)/get_down(q[tail],i)) tail--;
		q[++tail]=i;
	}
	printf("%lld\n",dp[n]);
} 
