//循环排列:n个数排成一圈的方案数 n!/n=(n-1)! 
//第一类斯特林数S(p,k)：将p个物体排成k个非空循环排列的方法数。
//S(p,k)的递推公式： S(p,k)=(p-1)*S(p-1,k)+S(p-1,k-1) ,1<=k<=p-1
// (p-1)*S(p-1,k)插到之前的制作,可在p-1个位置中任选一个           S(p-1,k-1)单独一个环 
//边界S(i,i)=1,S(i,0)=0
 
//将最高的拿出来,左边有f-1个房子可以看到，右边有b-1个房子，
//也就是从n-1个房子中选出f+b-2个房子，这f+b-2个房子各自属于一组，分成了f+b-2组
//对于每组组内有k个数,最大的那个数在最左（右）边，剩余的（k-1)数全排列，方案是(k-1)!，由于(k-1)！就是k个数的循环排列
//所以方案数就是S(n-1,f+b-2)
//又因为有前后关系，要从f+b-2中选f-1个做前面的房子
//最终答案为  S(n-1,f+b-2)*C(f+b-2,f-1)

#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 2000
#define mod 1000000007
using namespace std;
int t,n,f,b;
long long S[maxn+5][maxn+5];
long long C[maxn+5][maxn+5];
void prework(){
	C[0][0]=1;
	for(int i=1;i<=maxn;i++){
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
	S[0][0]=1;
	for(int i=1;i<=maxn;i++){
		S[i][0]=0;
		S[i][i]=1;
		for(int j=1;j<i;j++){
			S[i][j]=(S[i-1][j-1]+((i-1)*S[i-1][j])%mod)%mod;
		}
	}
} 
int main(){
	prework();
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d",&n,&f,&b);
		if(f+b-2>n){
			printf("%d\n",0);
		}else{
			printf("%I64d\n",(S[n-1][f+b-2]*C[f+b-2][f-1])%mod);
		}
	}
} 

