#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000 
using namespace std;
int n;
char s[maxn+5];
int nex[maxn+5];

int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	for(int i=2,j=0;i<=n;i++){
		while(j>0&&s[j+1]!=s[i]) j=nex[j];
		if(s[j+1]==s[i]) j++;
		nex[i]=j;
	}	
	printf("%d\n",n-nex[n]);
}
