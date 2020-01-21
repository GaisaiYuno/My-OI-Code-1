#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000005 
using namespace std;
int n;
char a[maxn];
int next[maxn];
int main(){
	scanf("%d",&n);
	scanf("%s",a+1);
	next[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j>0&&a[i]!=a[j+1]) j=next[j];
		if(a[i]==a[j+1]) j++;
		next[i]=j;
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		if(next[next[i]]) next[i]=next[next[i]];
	}
	for(int i=1;i<=n;i++){
		if(next[i]) ans+=(i-next[i]);
	}
	cout<<ans;
} 
