//直接DP会TLE
//考虑邻接矩阵的幂的意义
//从floyd算法考虑,A^k的意义： A^k的第i行第j列表示i到j走k步的方案数
//如何处理停留，自爆？
// 停留:自己向自己连边即可
// 自爆：建一个没有出边的虚拟点0，其他点向它连边  
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 35 
#define mod 2017
using namespace std;
inline int qread(){
	register int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int n,m,t;
struct matrix{
	long long a[maxn][maxn];
	matrix(){
		memset(a,0,sizeof(a));
	}
	friend matrix operator *(matrix x,matrix y){
		matrix z;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					z.a[i][j]+=x.a[i][k]*y.a[k][j];
				}
				z.a[i][j]%=mod;
			}
		}
		return z;
	}
};
matrix fast_pow(matrix x,int k){
	matrix ans;
	for(int i=0;i<=n;i++){
		ans.a[i][i]=1;
	}
	while(k){
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1;
	}
	return ans;
}

int u,v;
matrix x;
int main(){
	n=qread();
	m=qread();
	for(int i=1;i<=m;i++){
		u=qread();
		v=qread();
		x.a[u][v]=x.a[v][u]=1;
	}
	for(int i=0;i<=n;i++){
		x.a[i][i]=1;
	}
	for(int i=1;i<=n;i++){
		x.a[i][0]=1;
	}
	t=qread();
	x=fast_pow(x,t);
	long long ans=0;
	for(int i=0;i<=n;i++){
		ans+=x.a[1][i];
		ans%=mod;
	}
	cout<<ans;
}
