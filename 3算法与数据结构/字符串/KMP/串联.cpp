//http://119.29.55.79/problem/3278
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000
using namespace std;
int n;
char s[maxn+5];
int nex[maxn+5];
void get_nex(char *a,int n,int *nex){
	// for(int i=1;i<=n;i++) nex[i]=0;
	nex[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j>0&&a[i]!=a[j+1]) j=nex[j];
		if(a[i]==a[j+1]) j++;
		nex[i]=j;
	}
} 
int main(){
	while(scanf("%s",s+1)){
		n=strlen(s+1);
		if(n==1&&s[1]=='.') break;
		get_nex(s,n,nex);
		if(n%(n-nex[n])==0) printf("%d\n",n/(n-nex[n]));
		else printf("1\n");
	}
}
