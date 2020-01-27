#include<iostream>
#include<cstdio>
#define maxn 20
#define INF 2147483647
using namespace std;
int n,w;
int c[maxn];
int main(){
	int sum=0;
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;i++){
		 scanf("%d",&c[i]);
		 sum+=c[i]; 
	} 
	if(sum%w==0) printf("%d\n",sum/w);
	else printf("%d\n",sum/w+1);
	return 0;
}
