//若n%(n-next[n])==0,则a一定可以被前(n-next[n])个字符重复n/(n-next[n])得到
//证明：
//next[n]<n,且n%(n-next[n])==0,所以n-next[n]<=n/2
//当n-next[n]==n/2,即next[n]=n/2时，显然字符串被分成相等的两半，得证
//当n-next[n]<n/2,即next[n]>n/2时,将字符串分为3部分
// [s1 s2] 
//    [s2 s3]  
//显然s1=s3
//又因为n%(n-next[n])==0，所以len(s1)=len(s2)=len(s3)
//将[s1,s2][s2,s3]对齐，发现s1=s2,s2=s3
//得证 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005
using namespace std;
int n;
char a[maxn];
int next[maxn];
int main(){
	while(scanf("%s",a+1)){
		if(a[1]=='.') break;
		n=strlen(a+1);
		next[1]=0;
		for(int i=2,j=0;i<=n;i++){
			while(j>0&&a[i]!=a[j+1]) j=next[j];
			if(a[j+1]==a[i]) j++;
			next[i]=j;
		}
		if(n%(n-next[n])==0) printf("%d\n",n/(n-next[n]));
		else printf("1\n");
	}
}
