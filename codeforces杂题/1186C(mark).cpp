//设b串中1的个数为x，c串中1的个数为y
//两串中均为1的位置个数为z
//根据容斥原理，不相同的位置个数为x+y-2*z
//无论z为何值，2*z均为偶数
//因此只需x+y为偶数
//前缀和即可 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000
using namespace std;
int n,m;
char a[maxn+5];
int suma[maxn+5];
char b[maxn+5];
int sumb[maxn+5];
int main(){
	scanf("%s",a+1);
	scanf("%s",b+1);
	n=strlen(a+1);
	m=strlen(b+1);
	for(int i=1;i<=n;i++){
		suma[i]=suma[i-1]+a[i]-'0';
	}
	for(int i=1;i<=n;i++){
		sumb[i]=sumb[i-1]+b[i]-'0';
	}
	int ans=0;
	for(int i=1;i+m-1<=n;i++){
		if(((suma[i+m-1]-suma[i-1])+sumb[n])%2==0){
			ans++;
		}
	} 
	printf("%d\n",ans);
}

