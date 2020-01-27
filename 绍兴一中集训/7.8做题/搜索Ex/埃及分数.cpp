//http://codevs.cn/problem/1288/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 1005
using namespace std;
long long ans[maxn],tmp[maxn];
inline long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}
long long is_ok(long long x){
	if(ans[x]==-1) return 1;
	if(ans[x]>tmp[x]) return 1;
	return 0;
}
long long iddfs(long long d,long long limit,long long last,long long a,long long b){
	if(d>limit) return 0;
	long long g=gcd(a,b);
	a/=g;
	b/=g;
	if(d==limit){
		if(a==1&&b>last){
			tmp[d]=b;
			if(is_ok(d)){
				for(long long i=1;i<=d;i++){
					ans[i]=tmp[i];
				}
				return 1;
			}
		}
		return 0;
	}
	long long flag=0;
	for(long long i=last+1;i<=ceil(1.0*b*(limit-d+1)/a);i++){
		tmp[d]=i;
		flag=flag|iddfs(d+1,limit,i,i*a-b,i*b);
		tmp[d]=0;
	}
	return flag;
}
long long a,b;
int main(){
	scanf("%d %d",&a,&b);
	long long g=gcd(a,b);
	a/=g;
	b/=g;
	memset(ans,-1,sizeof(ans));
	for(long long deep=1;;deep++){
		if(iddfs(1,deep,1,a,b)){
			for(long long i=1;i<=deep;i++){
				printf("%d ",ans[i]);
			}
			break;
		}
	}
}
