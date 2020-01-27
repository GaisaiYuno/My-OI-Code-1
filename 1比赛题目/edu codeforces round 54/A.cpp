#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 200005
using namespace std;
int n;
char s[maxn];
int main(){
	scanf("%d",&n);
	scanf("%s",s+1);
	char maxc=0;
	int pos=0;
	for(int i=1;i<n;i++){
		if(s[i]>s[i+1]){
			for(int j=1;j<=n;j++){
				if(j==i) continue;
				printf("%c",s[j]);
			}
			return 0;
		}
	}
	for(int i=1;i<=n;i++){
		if(i==n) continue;
		printf("%c",s[i]);
	} 
} 
