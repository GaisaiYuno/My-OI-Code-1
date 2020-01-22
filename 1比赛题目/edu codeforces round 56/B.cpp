#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 1005
using namespace std;
int t,n;
char a[maxn]; 
int count[26];
int is_palin(){
	for(int i=1;i<=n/2;i++){
		if(a[i]!=a[n-i+1]) return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		scanf("%s",a+1);
		n=strlen(a+1);
		sort(a+1,a+1+n);
		if(is_palin()) printf("-1\n");
		else printf("%s\n",a+1);
	}
} 
