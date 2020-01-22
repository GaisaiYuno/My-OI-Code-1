#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005
using namespace std;
int n,m;
char a[maxn];
char b[maxn];
int next[maxn];
int f[maxn];
int kmp(){
	n=strlen(a+1);
	m=strlen(b+1);
	memset(f,0,sizeof(f));
	memset(next,0,sizeof(next));
	next[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j>0&&a[i]!=a[j+1]) j=next[j];
		if(a[i]==a[j+1]) j++;
		next[i]=j;
	}
	for(int i=1,j=0;i<=m;i++){
		while(j>0&&b[i]!=a[j+1]) j=next[j];
		if(b[i]==a[j+1]) j++;
		f[i]=j;
	}
	int ans=0;
	for(int i=1;i<=m;i++){
		if(f[i]==n) ans++;
	}
	return ans;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%s",a+1);
		scanf("%s",b+1);
		printf("%d\n",kmp());
	}
}
