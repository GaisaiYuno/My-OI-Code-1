/*
Problem: 方格染色[APIO2011]
Source:http://111.230.183.91/contest/14/problem/9
Algorithm:异或方程，边带权并查集 
Description:
画图可以发现
当i,j为偶数，a[1][1]^a[i][1]^a[1][j]^a[i][j]=1
否则 		 a[1][1]^a[i][1]^a[1][j]^a[i][j]=0
转换一下变成 a[1][1]^a[i][1]^a[1][j]=1^a[i][j]
 			 a[1][1]^a[i][1]^a[1][j]=a[i][j]
所以只要确定第1行和第1列就可以了
将第1行和第1列看成n+m个变量
我们可以枚举a[1][1]的值,然后根据关系去计算其他的
题目给出的条件相当于给出k个方程，然后求方程组解的组数
确定了a[1][1]后，例如a[1][1]=1，则对于a[i][j]，有关系： 
a[i][1]^a[1][j]=a[i][j]
a[i][1]^a[1][j]=1^a[i][j]
通过边带权并查集来维护,边权d[x]为0,表示x与fa[x]对应的值相等 
最后并查集中有b个fa[i]=i的点，就说明有b个变量是独立的，可以任意取0/1,确定了这b个就可以推出所有变量的值
由于a[1][1]在枚举时已经确定，所以解有2^(b-1)个 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000000
#define maxn 1000005
using namespace std;
int n,m,k;
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k>0){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
int x[maxn];
int y[maxn];
int c[maxn];
int fa[maxn];
int d[maxn];
int find(int x){
	if(x==fa[x]) return x;
	int root=find(fa[x]);
	d[x]^=d[fa[x]];
	fa[x]=root;
	return root;
}

long long solve(int x0){
	for(int i=1;i<=n+m;i++){
		fa[i]=i;
		d[i]=0;
	}
	fa[n+1]=1;
	if(x0==1){
		for(int i=1;i<=k;i++){
			if(x[i]>1&&y[i]>1) c[i]^=1;
		}
	}
	for(int i=1;i<=k;i++){
		if(!(x[i]==1&&y[i]==1)){
			int fx=find(x[i]);
			int fy=find(y[i]+n);
			int tmp=d[x[i]]^d[y[i]+n]^c[i];
			if(fx==fy){
				if((d[x[i]]^d[y[i]+n])!=c[i]) return 0;
			}else{
				fa[fy]=fx;
				d[fy]=tmp;
			}
		}
	}
	int block=0;
	for(int i=1;i<=n+m;i++){
		if(fa[i]==i) block++;
	}
	return fast_pow(2,block-1);
} 
int main(){ 
	int limit;
	scanf("%d %d %d",&n,&m,&k);
	limit=-1;
	for(int i=1;i<=k;i++){
		scanf("%d %d %d",&x[i],&y[i],&c[i]);
		if(x[i]%2==0&&y[i]%2==0) c[i]^=1;
		if(x[i]==1&&y[i]==1){
			limit=c[i];
		}
	}
	if(limit!=-1) printf("%lld\n",solve(limit));
	else{
		long long ans=0;
		for(int i=0;i<=1;i++) ans+=solve(i);
		ans%=mod;
		printf("%lld\n",ans);
	}
}

