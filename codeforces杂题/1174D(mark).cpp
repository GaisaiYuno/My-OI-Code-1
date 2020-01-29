#include<iostream>
#include<cstdio>
#define maxn (1<<18)
using namespace std;
//维护序列的前缀xor和，将区间转化为前缀
//问题就变为前缀和数组中不能有相同的数，并且不能存在一对数xor不能为x
//暴力将1~2^n-1插进去然后判断就可以了 
//由于sum[i]=sum[i-1]^a[i],最后答案a[i]=sum[i]^sum[i-1] 
int sum[maxn+5];
int vis[maxn+5];
int n,x;
int cnt=0;
int main(){
	scanf("%d %d",&n,&x);
	sum[0]=0;
	vis[0]=1;
	for(int i=1;i<(1<<n);i++){
		if(vis[i^x]) continue;
		sum[++cnt]=i;
		vis[i]=1;
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++){
		printf("%d ",sum[i]^sum[i-1]);
	}
}

