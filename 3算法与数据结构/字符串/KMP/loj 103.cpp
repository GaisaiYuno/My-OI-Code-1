#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005
using namespace std;
char a[maxn],b[maxn];
int next[maxn];
int f[maxn];
int main(){
	scanf("%s",a+1);
	scanf("%s",b+1);
	int n=strlen(a+1);
	int m=strlen(b+1);
	next[1]=0;
	for(int i=2,j=0;i<=m;i++){
		while(j>0&&b[i]!=b[j+1]) j=next[j];
		if(b[j+1]==b[i]) j++;
		next[i]=j;
	}
	for(int i=1,j=0;i<=n;i++){
		while(j>0&&a[i]!=b[j+1]) j=next[j];
		if(a[i]==b[j+1]) j++;
		f[i]=j;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(f[i]==m) cnt++; 
	}
	printf("%d\n",cnt);
} 
