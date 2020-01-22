//http://111.230.183.91:8080/problem/18
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int n;
int a[maxn];
long long sum[maxn];
int exist[maxn];

int is_ok(int block){
	for(int i=1;i<=sum[n]/block;i++){
		if(!exist[block*i]) return 0;
	}
	return 1;
}
int main(){
	n=qread();
	for(int i=1;i<=n;i++){
		a[i]=qread();
	} 
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		exist[sum[i]]=1;
	}
	for(int i=1;i<=n;i++){
		if(sum[n]%sum[i]==0){
			if(is_ok(sum[i])){
				printf("%d\n",sum[n]/sum[i]);
				break;
			}
		}
	}
	return 0;
} 
