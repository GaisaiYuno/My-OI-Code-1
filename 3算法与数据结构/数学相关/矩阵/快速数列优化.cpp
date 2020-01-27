#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#define MAXN 5
#define mod 1000000007
using namespace std;
struct matrix{
	int n;
	int m;
	long long a[MAXN][MAXN];
	matrix(int x,int y){
		n=x;
		m=y;
		memset(a,0,sizeof(a));
	}
	void print(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				printf("%d ",a[i][j]);
			}
		}
	}
	friend matrix operator *(matrix x,matrix y){
		matrix tmp=matrix(x.m,y.m);
		for(int i=1;i<=x.n;i++){
			for(int j=1;j<=y.m;j++){
	        	tmp.a[i][j]=0;
				for(int k=1;k<=y.n;k++){
					tmp.a[i][j]+=(x.a[i][k]*y.a[k][j])%mod;
				}
				tmp.a[i][j]%=mod;
			}
		}
		return tmp;
	}
};
matrix fastpow(matrix x,int k){
	matrix ans=matrix(3,3);
	for(int i=1;i<=ans.n;i++){
		ans.a[i][i]=1;
	}
	while(k>0){
		if(k%2==1){
		 	ans=ans*x;
		}
		k>>=1;
		x=x*x; 
	}
	return ans;
}
int x,t;
int main(){
	//freopen("H:\C++\数学相关\矩阵\快速数列优化（data)\seq1.in","r",stdin);
    scanf("%d",&t);
	while(t--){ 
		//int t[4][4]={{0,0,0,0},{0,1,0,1},{0,1,0,0},{0,0,1,0}};
		matrix unit=matrix(3,3);
		scanf("%d",&x);
		unit.a[1][1]=1;
		unit.a[1][2]=0;
		unit.a[1][3]=1;
		unit.a[2][1]=1;
		unit.a[2][2]=0;
		unit.a[2][3]=0;
		unit.a[3][1]=0;
		unit.a[3][2]=1;
		unit.a[3][3]=0;
		matrix ans=matrix(3,3);
		ans=fastpow(unit,x-3);
		long long sum=0;
		long long tmp;
		for(int i=1;i<=ans.n;i++){
			sum+=ans.a[1][i];
		}
		sum%=mod;
        printf("%lld\n",sum);
	} 
	
}
