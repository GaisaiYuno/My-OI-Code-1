//http://119.29.55.79/problem/1502
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm> 
#define maxn 100000
using namespace std;
int n;
int a[maxn+5];
void discrete(int *a,int n){
	static int b[maxn+5];
	for(int i=1;i<=n;i++) b[i]=a[i];
	sort(b+1,b+1+n);
	int sz=unique(b+1,b+1+n)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+1+sz,a[i])-b;

}

struct list{
	int pre[maxn+5],nex[maxn+5];
	void ini(int n){
		pre[0]=-1;//相当于NULL
		for(int i=1;i<=n;i++){
			pre[i]=i-1;
			nex[i]=i+1;
		} 
	}
	void del(int x){
		nex[pre[x]]=nex[x];
		pre[nex[x]]=pre[x];
	}
}L;
int lst[maxn+5];
int dp[maxn+5];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	discrete(a,n);
	L.ini(n);
	dp[0]=0;
	for(int i=1;i<=n;i++) dp[i]=i;//每个数一段,答案最大不超过i 
	for(int i=1;i<=n;i++){
		if(lst[a[i]]) L.del(lst[a[i]]);	//相同的数只保留最后一个 
		//考虑到j从i-1倒序枚举到1时，若出现重复的a[i]，除第一次出现外应该删去，
		//因为枚举到的a[i]加入num^2部分不会使num变大,所以dp[i]和它前后的dp值应该是等价的 
		lst[a[i]]=i;
		int num=0;
		for(int j=L.pre[i];j!=-1;j=L.pre[j]){
			num++;
			if(num*num>i) break;//如果超过i显然不优，可以直接break掉 
			dp[i]=min(dp[i],dp[j]+num*num);
		}
	}
	printf("%d\n",dp[n]); 
}

