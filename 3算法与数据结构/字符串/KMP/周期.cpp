//http://119.29.55.79/problem/3279
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000
using namespace std;
int n;
char s[maxn+5];
int nex[maxn+5];
void get_nex(char *a,int n,int *nex){
	nex[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j>0&&a[i]!=a[j+1]) j=nex[j];
		if(a[i]==a[j+1]) j++;
		nex[i]=j;
	}
} 


int main(){	
	int cas=0;
	while(1){
		scanf("%d",&n);
		if(n==0) break;
		scanf("%s",s+1);
		get_nex(s,n,nex);
		printf("Test case #%d\n",++cas);
		for(int i=2;i<=n;i++){
			if(i%(i-nex[i])==0&&i/(i-nex[i])>1){
				printf("%d %d\n",i,i/(i-nex[i])); 
			} 
		}
		printf("\n");
	}
}
