//gcd(x,y)=1,1<=x,y<=n的对数是phi(1)+phi(2)+...+phi(n)
//欧拉函数增长很快，当n=600时就超过100000
//所以直接暴力枚举，当cnt>=m时break
//因为结果增长很快，所以不会TLE 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 100005
using namespace std;
vector<int>v[maxn];
int n,m;
inline int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}
int main(){
	scanf("%d %d",&n,&m);
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(gcd(i,j)==1){
				v[i].push_back(j);
				cnt++;
			}
			if(cnt>=m) break;
		}
		if(cnt>=m) break;
	}
	if(cnt>=m&&m>=n-1){
		printf("Possible\n");
		for(int i=1;i<=n;i++){
			for(int j=0;j<v[i].size();j++){
				printf("%d %d\n",i,v[i][j]);
			}
		}
	}else{
		printf("Impossible\n");
	}
} 
