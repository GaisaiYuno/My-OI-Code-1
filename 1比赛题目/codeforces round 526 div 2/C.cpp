//将所有其他字母去掉，只剩a,b 
//可以求出所有a的连续块长度 
//将每块的长度len+1乘起来即为答案（每段中只能选1个（编号len种）或不选） 
//但是不能全部不选，所以答案还要-1 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 100005
#define mod 1000000007
using namespace std;
int n,m;
char a[maxn];
char b[maxn];
int pre[maxn];
int is_all(char c){
	for(int i=1;i<=n;i++){
		if(a[i]!=c) return 0;
	}
	return 1;
}
int main(){
	scanf("%s",a+1);
	n=strlen(a+1);
	for(int i=1;i<=n;i++){
		if(a[i]=='a'||a[i]=='b'){
			b[++m]=a[i];
		}
	}
	if(is_all('a')){
		printf("0\n");
		return 0;
	}
	for(int i=1;i<=m;i++){
		if(b[i]=='b') pre[i]=0;
		else pre[i]=pre[i-1]+1;
	}
	long long ans=1;
	for(int i=1;i<=m;i++){
		if(b[i+1]!='a'){
			ans=(ans*(pre[i]+1))%mod;
		}
	}
	ans-=1; 
	printf("%I64d\n",ans);
} 
