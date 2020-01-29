//https://www.luogu.com.cn/problem/P2178
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxs 128 
#define maxn 300000
using namespace std;
typedef long long ll;
void rsort(int *ans,int *fi,int *se,int n,int m){
	static int buck[maxn+5];
	for(int i=0;i<=m;i++) buck[i]=0;
	for(int i=1;i<=n;i++) buck[fi[i]]++;
	for(int i=1;i<=m;i++) buck[i]+=buck[i-1];
	for(int i=n;i>=1;i--) ans[buck[fi[se[i]]]--]=se[i];
}
int sa[maxn+5],rk[maxn+5],height[maxn+5];
void suffix_sort(char *s,int n,int m){
	static int se[maxn+5];
	for(int i=1;i<=n;i++){
		rk[i]=s[i];
		se[i]=i;
	}
	rsort(sa,rk,se,n,m);
	for(int k=1;k<=n;k*=2){
		int p=0;
		for(int i=n-k+1;i<=n;i++) se[++p]=i;
		for(int i=1;i<=n;i++) if(sa[i]>k) se[++p]=sa[i]-k;
		rsort(sa,rk,se,n,m);
		swap(rk,se);
		rk[sa[1]]=1;
		p=1;
		for(int i=2;i<=n;i++){
			if(se[sa[i-1]]==se[sa[i]]&&se[sa[i-1]+k]==se[sa[i]+k]) rk[sa[i]]=p;
			else rk[sa[i]]=++p;
		}
		if(p==n) break;
		m=p;
	}
}
void get_height(char *s,int n,int m){
	suffix_sort(s,n,m);
	for(int i=1;i<=n;i++) rk[sa[i]]=i;
	int k=0;
	for(int i=1;i<=n;i++){
		if(k) k--;
		int j=sa[rk[i]-1];
		while(s[i+k]==s[j+k]) k++;
		height[rk[i]]=k;
	}
}

int n;
char str[maxn+5];
int val[maxn+5];

ll cnt[maxn+5];
ll mul[maxn+5];//i相似的方案数和最大乘积 
int fa[maxn+5];
ll sz[maxn+5],maxv[maxn+5],minv[maxn+5];
//集合大小,最大值，最小值 
int find(int x){
	if(fa[x]==x) return x;
	else return fa[x]=find(fa[x]);
} 
void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	int r=height[y];//按照height从大到小合并,lcp一定是当前height值
	cnt[r]+=sz[fx]*sz[fy];
	mul[r]=max(mul[r],max(maxv[fx]*maxv[fy],minv[fx]*minv[fy]));//可能有负数,所以两个最小值相乘也可以很大
	maxv[fy]=max(maxv[fx],maxv[fy]);
	minv[fy]=min(minv[fy],minv[fx]);
	sz[fy]+=sz[fx];
	fa[fx]=fy;
}

vector<int>pos[maxn+5];//每个height值在height数组上对应的下标(rank) 
int main(){
	scanf("%d",&n);
	scanf("%s",str+1);
	for(int i=1;i<=n;i++) scanf("%d",&val[i]); 
	get_height(str,n,maxs);
	for(int i=1;i<=n;i++){
		fa[i]=i;
		sz[i]=1;
		maxv[i]=minv[i]=val[sa[i]];//按照height数组的顺序,即排名合并 
	}
	memset(cnt,0,sizeof(cnt));
	memset(mul,0xcf,sizeof(mul));
	for(int i=1;i<=n;i++) pos[height[i]].push_back(i);
	for(int i=n-1;i>=0;i--){//按照height从大到小合并 
		for(int j=0;j<(int)pos[i].size();j++){
			int x=pos[i][j];
			merge(x-1,x);//把height>=i的相邻值并成连续区间 
		}
	}
	for(int i=n-2;i>=0;i--){
		cnt[i]+=cnt[i+1];
		mul[i]=max(mul[i],mul[i+1]);
		//求后缀和 
		//我们合并时求出的是lcp恰好为i的答案,而题目求的是lcp>=i的答案 
	}
	for(int i=0;i<=n-1;i++){
		printf("%lld ",cnt[i]);
		if(cnt[i]!=0) printf("%lld\n",mul[i]);
		else printf("0\n");
	}
}

