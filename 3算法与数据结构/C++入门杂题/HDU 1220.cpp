//所有对数为C(n^3,2)=n^3(n^3-1)/2
//相邻点数0,1,2,4,最多4
//所以只要算出最多的再拿总数去减就可以了
//一列有n-1队(相邻的有两个),一层有n列，从某个面看有n层，共6面 
// 6n^2(n-1)
//因为每对被重复算了两次，所以3n^2(n-1),ans= n^3(n^3-1)/2-3n^2(n-1)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
long long n;
int main(){
	while(scanf("%lld",&n)!=EOF){
		printf("%lld\n",n*n*n*(n*n*n-1)/2-3*n*n*(n-1));
	}
} 
