#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005
using namespace std;
int n;
char a[maxn];
int next[maxn];
void kmp(){
	memset(next,0,sizeof(next));
	next[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j>0&&a[i]!=a[j+1]) j=next[j];
		if(a[i]==a[j+1]) j++;
		next[i]=j;
	}
}
int main(){
	while(scanf("%s",a+1)!=EOF){
		n=strlen(a+1);
		if(n==1&&a[1]=='.') break;
		kmp();
		if(n%(n-next[n])==0){
			printf("%d\n",n/(n-next[n]));
		}else{
			printf("1\n");
		}
	}
}
