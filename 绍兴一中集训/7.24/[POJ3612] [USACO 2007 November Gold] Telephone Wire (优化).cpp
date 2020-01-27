#include<iostream>
#include<cstdio>
#include<cstring>
#define INF 0x3f3f3f3f
#define rg register
#define maxn 100000
#define maxh 100
using namespace std;
typedef long long ll;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}

int n,c,lim;
int h[maxn+5]; 
int dp[maxn+5][maxh+5];
inline int abs(int x){
	return x>=0?x:-x; 
} 
inline int min(int x,int y){
	return x<=y?x:y; 
}
int main(){
	qread(n);
	qread(c);
	lim=0;
	for(rg int i=1;i<=n;i++){
		qread(h[i]);
		lim=max(lim,h[i]);
	}
	memset(dp,0x3f,sizeof(dp));
	for(rg int j=h[1];j<=lim;j++){
		dp[1][j]=(j-h[1])*(j-h[1]);
	}
	for(rg int i=2;i<=n;i++){
		rg int k=h[i-1];//k有决策单调性，不用每次从h[i-1]开始枚举 
		int bestk=h[i-1];
		for(rg int j=h[i];j<=lim;j++){
			int last=INF; 
			k=bestk;//从上一次的决策点开始枚举 
			for(;k<=lim;k++){
				int now=dp[i-1][k]+c*abs(j-k)+(j-h[i])*(j-h[i]);
				if(dp[i][j]>now){
					dp[i][j]=now;
					bestk=k;
				}
				if(now>last) break;//由于代价是二次函数，找到最小值点就不用再找了 
				last=now;
			}
//			printf("i=%d j=%d k=%d\n",i,j,bestk);
		}
	}
	int ans=INF;
	for(rg int i=h[n];i<=lim;i++) ans=min(ans,dp[n][i]);
	printf("%d\n",ans);
}
