//HDU 5945
//优化 
#include<iostream>
#include<cstring>
#define maxn 1000020
using namespace std;
int c,x,k,t;
int dp[maxn],q[maxn];
int head,tail;
int main() {
	cin>>c;
	while(c--) {
		cin>>x>>k>>t;
		int ans=0;
		if(t==0) { //特判
			while(x!=1) {
				x/=k;
				ans++;
			}
		}else if(k==0) {
			if((x-1)%t==0) ans=(x-1)/t;
			else ans=(x-1)/t+1;
		} else {
			head=0,tail=1; 
			memset(q,0,sizeof(q));
			memset(dp,0x7f,sizeof(dp));
			dp[1]=0;
			q[head]=1;
			for(int i=2; i<=x; i++) {
				while(i-q[head]>t&&head<tail) head++;//单调队列优化 
				dp[i]=dp[q[head]]+1;
				if(i%k==0) dp[i]=min(dp[i],dp[i/k]+1);
				while(dp[q[tail]]>dp[i]&&head<tail) tail--;
                q[++tail]=i;
			}
			ans=dp[x];
		}
		cout<<ans<<endl;
	}
}
//dp[i]=min(min(dp[i-t]~dp[i-1])+1,dp[i/k]+1)
/*
对于单调队列，我们这样子来定义： 
1、维护区间最值 
2、去除冗杂状态 
3、保持队列单调，最大值是单调递减序列，最小值反之 
4、最优选择在队首

大致过程： 
1、维护队首（对于上题就是如果你已经是当前的m个之前那你就可以被删了,head++） 
2、在队尾插入（每插入一个就要从队尾开始往前去除冗杂状态） 
*/ 
