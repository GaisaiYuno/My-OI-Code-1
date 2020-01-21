#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long a,b;
int main(){
	scanf("%d %d",&a,&b);
	printf("%lld\n",a*b-a-b);
}
/*
不妨设a<b 
假设答案为x 
若x=ma(mod b) (1<=m<=b-1)
即x=ma+nb(1<=m<=b-1)
显然n>=0时x可用a,b表示
故n=-1,m=b-1时x有最大值ab-a-b 
*/
