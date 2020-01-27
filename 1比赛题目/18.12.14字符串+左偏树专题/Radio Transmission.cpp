//http://111.230.183.91:8080/problem/28 
#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005 
int n;
char s[maxn];
int next[maxn];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	next[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j>0&&s[i]!=s[j+1]) j=next[j];
		if(s[i]==s[j+1]) j++;
		next[i]=j;
	} 
	printf("%d\n",n-next[n]);
} 
