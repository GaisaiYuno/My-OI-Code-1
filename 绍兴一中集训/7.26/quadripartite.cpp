#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 40
#define maxbin 10000000
//#define lowbit(x) ((x)&(-x))
using namespace std; 
inline int lowbit(int x){
	return x&-x;
}
int n;
long long ans;
bool gab[maxn+5][maxn+5],gac[maxn+5][maxn+5],gbd[maxn+5][maxn+5],gcd[maxn+5][maxn+5];//因为编号可能重复，开4个邻接矩阵
int log2[maxbin+5];
void dfs(int x,int bb,int cc,int dd){
//	printf("%d %d %d %d\n",x,bb,cc,dd);
	if(x==n+1){
		ans++;
		return;
	}
	for(int b=bb;b>0;b-=lowbit(b)){//从低到高 取出每一位 
		int i=log2[lowbit(b)];
		if(gab[x][i]){
			for(int c=cc;c>0;c-=lowbit(c)){
				int j=log2[lowbit(c)];
				if(gac[x][j]){
					for(int d=dd;d>0;d-=lowbit(d)){
						int k=log2[lowbit(d)];
						if(gbd[i][k]&&gcd[j][k]){
							dfs(x+1,bb^(1<<(i-1)),cc^(1<<(j-1)),dd^(1<<(k-1)));
						}
					}
				}
			}
		} 
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			gab[i][j]=1;
			gac[i][n+i-j]=1;
			gbd[j][i+j-1]=1;
			gcd[n+i-j][i+j-1]=1;
		}
	} 
	int t=(1<<(2*n-1));
	log2[0]=0;
	for(int i=1;i<=t;i++) log2[i]=log2[i>>1]+1;
	dfs(1,(1<<n)-1,(1<<(2*n-1))-1,(1<<(2*n-1))-1);
	printf("%d %lld\n",n,ans);
} 
