#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 13
using namespace std;
int n;
long long fact[maxn+5];
long long ans=0;
int a[(1<<maxn)+5];
inline void swap_seg(int x,int y,int k){
	for(int i=1;i<=k;i++){
		swap(a[x+i-1],a[y+i-1]);
	}
}
inline int lb(int id,int len){
	return (1<<len)*(id-1)+1;
}
inline int rb(int id,int len){
	return id*(1<<len);
}
inline int length(int k){
	return 1<<k;
}

bool check(int k){
	for(int i=1;i<=(1<<(n-k));i++){
		if(a[lb(i,k)+length(k-1)]!=a[lb(i,k)]+length(k-1)) return 0;
	}
	return 1;
} 




int cnt=0;
void debug(){
	for(int i=1;i<=(1<<n);i++) printf("%d ",a[i]);
	printf("\n");
}

void dfs(int deep,int num){
	if(deep!=0&&check(deep)==0) return;
	if(deep==n){
		ans+=fact[num];
		return;
	}
	dfs(deep+1,num);
	int sz=0;//统计出不递增的小段 
	int tmp[5];//不能用全局变量，每层tmp都不一样 
	for(int i=1;i<=(1<<(n-deep));i+=2){
		if(a[rb(i,deep)+1]!=a[lb(i,deep)]+length(deep)){
			tmp[++sz]=i;
			tmp[++sz]=i+1; 
			if(sz>4) return;//无解 
		}
	}

	if(sz==0) return;//不用交换 
	//枚举如何交换小段 
	for(int i=1;i<=sz;i++){
		for(int j=i+1;j<=sz;j++){
			swap_seg(lb(tmp[i],deep),lb(tmp[j],deep),length(deep));
			dfs(deep+1,num+1);
			swap_seg(lb(tmp[i],deep),lb(tmp[j],deep),length(deep));
		}
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=(1<<n);i++) scanf("%d",&a[i]);
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i;
	dfs(0,0);
	printf("%lld\n",ans);
}
