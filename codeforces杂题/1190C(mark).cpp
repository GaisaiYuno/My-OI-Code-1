//判断第一步先手是否必胜
//再判断一下第二步后手是否必胜
//这样就可以了，因为一个人可以把翻过去的翻回来导致平局 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100000
using namespace std;
int n,k; 
int a[maxn+5];
int sum[maxn+5];
inline int query(int l,int r){
	return l>r?0:sum[r]-sum[l-1];
}
bool check1(){//找一个区间，区间外是全0或全1 
	for(int i=1;i+k-1<=n;i++){
		int sum=query(1,i-1)+query(i+k,n);
		if(sum==0||sum==n-k) return 1;
	}
	return 0;
}
bool check2(){//
	if(k==1) return 0;
	if(k*2<n) return 0;
	for(int i=2;i<=n-k-1;i++){
		if(a[i]!=a[i-1]) return 0;
		if(a[n-i+1]!=a[n-i+2]) return 0;
	}
	if(a[1]==a[n]||a[n-k-1]==a[n-k]||a[k+1]==a[k+2]) return 0;
	return 1;
} 

int main(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++) scanf("%1d",&a[i]);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	if(check1()) printf("tokitsukaze\n");
	else{
		if(check2()) printf("quailty\n");
		else printf("once again\n");
	} 
}

