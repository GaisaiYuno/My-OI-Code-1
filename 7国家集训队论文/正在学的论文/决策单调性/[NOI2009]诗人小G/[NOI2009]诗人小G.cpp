//https://www.cnblogs.com/luoshuitianyi/p/10386710.html
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring> 
#define maxn 500000
#define maxl 30
#define INF 1e18
using namespace std;
typedef long double db;
int T;
int n,L,P;
char s[maxn+5][maxl+5];
int sum[maxn+5];
db dp[maxn+5];
int res[maxn+5];
inline db fast_pow(db x,int k){
	db ans=1;
	while(k){
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1;
	}
	return ans;
}
inline db calc(int j,int i){//计算f[j]+val(j,i) 
	return dp[j]+fast_pow(abs(sum[i]-sum[j]+(i-j-1)-L),P);
}
inline int bin_search(int a,int b){//找到第一个决策b比决策a优的位置 
	if(calc(a,n)<calc(b,n)) return n+1;
	int l=b,r=n;
	int ans=-1;
	int mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(calc(b,mid)<=calc(a,mid)){
			ans=mid;
			r=mid-1;
		}else l=mid+1;
	}
	return ans;
}
void ini(){
	for(int i=1;i<=n;i++){
		dp[i]=INF;
		res[i]=0;
	}
}

int q[maxn+5];
int stk[maxn+5];//找出1~n最优决策的每一段 
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %d %d",&n,&L,&P);
		ini();
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]);
			sum[i]=strlen(s[i])+sum[i-1];
		} 
		int head=1,tail=0;
		q[++tail]=0;
		dp[0]=0;
		for(int i=1;i<=n;i++){
			while(head<tail&&bin_search(q[head],q[head+1])<=i) head++;
			//使得head决策点的对应区间包含i 
			res[i]=q[head];
			dp[i]=calc(q[head],i);
			while(head<tail&&bin_search(q[tail-1],q[tail])>=bin_search(q[tail],i)) tail--;
			//把以队尾决策点为决策点不如以i为决策点更优的位置出队 
			q[++tail]=i; //并替换成i 
		}
		if(dp[n]>INF){
			printf("Too hard to arrange\n");
		}else{
			printf("%lld\n",(long long)dp[n]);
			int top=0;
			for(int i=n;i;i=res[i]) stk[++top]=i;
			stk[++top]=0;
			for(int i=top-1;i>=1;i--){
				int r=stk[i],l=stk[i+1]+1;
				for(int j=l;j<r;j++) printf("%s ",s[j]);
				printf("%s\n",s[r]);
			} 
		}
		printf("--------------------\n");
	}
}

