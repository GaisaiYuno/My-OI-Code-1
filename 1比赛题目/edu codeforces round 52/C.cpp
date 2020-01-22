#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 200005
#define INF 0x7f7f7f7f
using namespace std;
int n,k;
int a[maxn];
int cnt[maxn];//每一层的个数
int sum[maxn];//cnth的前缀和 
int maxh,minh;
int get_num(int r,int l){
	return sum[r]-sum[l-1];
} 
int main(){
	maxh=0;
	minh=INF;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		maxh=max(maxh,a[i]);
		minh=min(minh,a[i]);
		cnt[1]++;
		cnt[a[i]+1]--;
	}
	for(int i=1;i<=maxh;i++){
		cnt[i]+=cnt[i-1]; 
	} 
	for(int i=1;i<=maxh;i++){
		sum[i]=sum[i-1]+cnt[i]; 
	} 
	int ans=0;
	int last=maxh;
	for(int i=maxh;i>minh;){
		ans++;
		while(get_num(last,i)<=k&&i>minh) i--;
		last=i;
	}
	printf("%d\n",ans);
}
