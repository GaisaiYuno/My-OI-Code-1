#include<iostream>
#include<cstring>
#include<fstream>
#define maxk 7
#define maxn 41
using namespace std;
ifstream fin,fans;
int k,n;
char s[maxk];
long long dp[maxn][maxk];
long long tonum(int l,int r){
	long long x=0;
	for(int i=l;i<=r;i++){
		x=x*10+s[i]-'0';
	} 
	return x;
} 
long long bd;
int main(){
	fin.open("cjzd6.in");
    fans.open("cjzd6.ans");
	fin>>n>>k;
	fin>>s; 
	fans>>bd;
	for(int i=0;i<n;i++){
		dp[i][0]=tonum(0,i);
	}
	for(int i=0;i<n;i++){
		for(int j=1;j<=k;j++){
			for(int u=j-1;u<i;u++){ 
				dp[i][j]=max(dp[i][j],dp[u][j-1]*tonum(u+1,i));
			} 
		}
   }
	//if(bd==dp[n-1][k]){
	//	printf("AC! read %d,expected %d \n",dp[n-1][k],dp[n-1][k]);
	//}
	//else printf("WA! read %d,expected %d\n",dp[n-1][k],bd);
	cout<<dp[n-1][k]<<endl;
}
/*
dp[i][j]=dp[u][j-1]*tonum(u+1,i)
  u¡Ê[j,i] 
*/ 
