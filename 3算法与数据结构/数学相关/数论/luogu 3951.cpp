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
������a<b 
�����Ϊx 
��x=ma(mod b) (1<=m<=b-1)
��x=ma+nb(1<=m<=b-1)
��Ȼn>=0ʱx����a,b��ʾ
��n=-1,m=b-1ʱx�����ֵab-a-b 
*/
