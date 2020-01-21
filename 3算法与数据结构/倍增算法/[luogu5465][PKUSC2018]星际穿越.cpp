#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath> 
#define maxn 300000
#define maxlogn 25 
using namespace std;
int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int n,q;
int log2n;
int a[maxn+5]; 
int f[maxn+5][maxlogn+5];
int g[maxn+5][maxlogn+5];
int calc(int x,int l){ //[l,x-1]内答案 
	if(a[x]<=l) return x-l;
	//特判第一次跳 
	int ans=x-a[x];
	int cnt=1;
	x=a[x]; 
	for(int i=log2n;i>=0;i--){
		if(f[x][i]>=l){
			ans+=g[x][i]+cnt*(x-f[x][i]);//[f[x][i],x-1]跳到x还需cnt步 
			cnt+=(1<<i);
			x=f[x][i];
		}
	}
	if(x>l) ans+=x-l+cnt*(x-l);//如果最后一步没跳满，加上f[x][i] 
	return ans; 
} 
int main(){
	int l,r,x;
	scanf("%d",&n);
	log2n=log2(n)+1;
	a[1]=1;
	for(int i=2;i<=n;i++) scanf("%d",&a[i]);
	f[n][0]=a[n];
	for(int i=n-1;i>=1;i--){
		f[i][0]=min(f[i+1][0],a[i]);
		g[i][0]=i-f[i][0];
	}
	for(int j=1;j<=log2n;j++){
		for(int i=1;i<=n;i++){
			if(f[i][j-1]){
				f[i][j]=f[f[i][j-1]][j-1];
				g[i][j]=g[i][j-1]+g[f[i][j-1]][j-1]+((f[i][j-1]-f[i][j])<<(j-1)); 
				//[f[i][j],f[i][j-1]-1]内的点跳到j还需2^{j-1}步 
			}
		}
	}
	scanf("%d",&q);
	while(q--){
		scanf("%d %d %d",&l,&r,&x);
		int up=calc(x,l)-calc(x,r+1);
		int down=r-l+1;
		int g=gcd(up,down);
		up/=g;
		down/=g;
		printf("%d/%d\n",up,down);
	}
}
//https://www.luogu.org/problemnew/solution/P5465
