//https://vjudge.net/contest/311947#problem/B
/*
门和钥匙的对应关系是个排列，排列是一个一个的环，其中每个环炸一次就可以把环取完，
所以题目的要求就是n！个排列中组成<=k个环的排列数量，这就是第一类斯特林数的定义 S(n,i)
不能炸一号门其实很简单，就是一号点不能单独为环 S(n-1,i-1)
ans=sum(S(n,i)-S(n-1,i-1))/fact(n)
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 20
using namespace std;
typedef long long ll;
ll fact[maxn+5];
ll S[maxn+5][maxn+5];
void ini(int n){
	for(int i=0;i<=n;i++){
		S[i][0]=0;
		S[i][i]=1;
		for(int j=1;j<i;j++){
			S[i][j]=S[i-1][j-1]+(i-1)*S[i-1][j];
		}
	}
	fact[0]=1;
	for(int i=1;i<=n;i++) fact[i]=fact[i-1]*i;
}

double calc(int n,int k){
	long long ans=0;
	for(int i=1;i<=k;i++){
		ans+=S[n][i]-S[n-1][i-1];
	}
	return 1.0*ans/fact[n];
}
int t,n,k;
int main(){
	ini(maxn);
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		printf("%.4lf\n",calc(n,k));
	}
	
}
