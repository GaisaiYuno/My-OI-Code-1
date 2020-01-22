//如果全部递增，输出0
//考虑把序列第i项变成i
//若b>a/2,则a%b=a-b
//假如a[i]-i>a[i]/2,则a[i]%(a[i]-i)=i-(a[i]-i)=i
//由上面的不等式知a[i]>2*i 
//所以统一给每个a[i]加上2*n就可以保证了
//所以有一次+操作，一次%操作 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
using namespace std;
int n;
int a[maxn];
int main(){
	scanf("%d",&n);
	bool flag=true;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i>=2&&a[i]<=a[i-1]){
			flag=false;
		}
	}
	if(flag){
		printf("0\n");
		return 0;
	}
	printf("%d\n",n+1);
	printf("1 %d 200000\n",n);
	for(int i=1;i<=n;i++){
		a[i]+=200000; 
	}
	for(int i=1;i<=n;i++){
		printf("2 %d %d\n",i,a[i]-i);
	}
}
